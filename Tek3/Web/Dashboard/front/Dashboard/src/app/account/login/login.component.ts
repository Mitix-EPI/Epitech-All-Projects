import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { FacebookLoginProvider, GoogleLoginProvider, MicrosoftLoginProvider, SocialAuthService, SocialUser, VKLoginProvider } from 'angularx-social-login';
import { first } from 'rxjs/operators';
import { User } from 'src/app/interfaces';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {

  form: FormGroup = new FormGroup({});
  loading = false;
  submitted = false;
  socialUser!: SocialUser;
  isLoggedIn: boolean = false;

  constructor(
      private formBuilder: FormBuilder,
      private userService: UserService,
      private socialAuthService: SocialAuthService,
      private router: Router
  ) { }

  ngOnInit() {
      this.form = this.formBuilder.group({
          email: ['', Validators.required],
          password: ['', Validators.required]
      });
      this.socialAuthService.authState.subscribe((socialUserRes) => {
        console.log("DEBUG ", socialUserRes)
        this.socialUser = socialUserRes;
        this.isLoggedIn = (socialUserRes !== null);
        if (this.socialUser) {
          const provider = this.getProvider(this.socialUser.provider);
          const user : User = {
            id: '0',
            email: this.socialUser.email,
            idOAuth2: this.socialUser.id,
            service: provider,
            urlCover: 'https://lh3.googleusercontent.com/proxy/pIwxyKmjgcdPhQfoSv9K54jDIMp2mj9cZ9rTAT8KT6U3SqfiP8Jnkj1kj7tLVvW_0kMYAvdgMnJogKxcV40OotfbSgd_r3lWVt-QHLUMXBnDnr8sbQq7DSP659JiQFkje8OnTagDrj4_KmgyDh2u4phAd8HsfwBxyq8eVZS-Alp3FW8CO4F1JUpvP6W6wyPQr-g'
          }
          this.userService.login(user).then(res => {
            if (!res.error) { // Change property
              this.router.navigate(['/']);
            } else {
              console.log("ERROR ", res);
            }
          });
        } else {
          this.userService.isLoggedIn = false;
          this.userService.isOAuth2 = false;
          this.router.navigate(['/account/login']);
        }
      });
  }

  // convenience getter for easy access to form fields
  get f() { return this.form.controls; }

  onSubmit() {
      this.submitted = true;

      // stop here if form is invalid
      if (this.form.invalid) {
          return;
      }

      this.loading = true;
      const user: User = {
        id: "0",
        email: this.f.email.value,
        password: this.f.password.value,
        service: 'None',
        urlCover: 'https://lh3.googleusercontent.com/proxy/pIwxyKmjgcdPhQfoSv9K54jDIMp2mj9cZ9rTAT8KT6U3SqfiP8Jnkj1kj7tLVvW_0kMYAvdgMnJogKxcV40OotfbSgd_r3lWVt-QHLUMXBnDnr8sbQq7DSP659JiQFkje8OnTagDrj4_KmgyDh2u4phAd8HsfwBxyq8eVZS-Alp3FW8CO4F1JUpvP6W6wyPQr-g'
      };
      this.userService.login(user).then(res => {
        if (!res.error) { // Change property
          this.router.navigate(['/']);
        } else {
          alert(res.error);
        }
      });
  }

  loginWithGoogle() {
    this.socialAuthService.signIn(GoogleLoginProvider.PROVIDER_ID);
  }

  loginWithFB(): void {
    this.socialAuthService.signIn(FacebookLoginProvider.PROVIDER_ID);
  }

  loginWithMicrosoft(): void {
    this.socialAuthService.signIn(MicrosoftLoginProvider.PROVIDER_ID);
  }

  loginWithVK(): void {
    this.socialAuthService.signIn(VKLoginProvider.PROVIDER_ID)
  }

  refreshToken(): void {
    this.socialAuthService.refreshAuthToken(GoogleLoginProvider.PROVIDER_ID);
  }

  logout() {
    this.userService.logout();
  }

  getProvider(provider: string): 'Google' | 'Facebook' | 'Microsoft' | 'None' {
    switch (provider) {
      case 'FACEBOOK':
        return 'Facebook';
      case 'GOOGLE':
        return 'Google';
      case 'MICROSOFT':
        return 'Microsoft';
    }
    return 'None';
  }

}
