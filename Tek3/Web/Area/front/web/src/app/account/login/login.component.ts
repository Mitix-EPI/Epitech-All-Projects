import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { ApiService } from '../../../../../shared/src/lib/services/api.service';
import { LoginService } from '../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {

  form: FormGroup = new FormGroup({});
  loading: boolean = false;
  loginFailed: boolean = false;
  private formSubmitAttempt: boolean = false;

  constructor(private formBuilder: FormBuilder, private route: Router, private loginService: LoginService) { }

  ngOnInit() {
    this.form = this.formBuilder.group({
        email: ['', [Validators.required, Validators.email]],
        password: ['', Validators.required]
    },{updateOn:'submit'});
  }

  // convenience getter for easy access to form fields
  get f() { return this.form.controls; }

  isFieldValid(field: string) {
    if (this.form) {
      if (this.form.get(field)) {
        return (!this.form.get(field)!.valid && this.form.get(field)!.touched)
        || (this.form.get(field)!.untouched && this.formSubmitAttempt);
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  login(): void {
    this.formSubmitAttempt = true;
    console.log("login");
    if (this.form.valid) {
      this.loading = true;
      console.log("login success", this.f);
      this.loginService.login(this.f["email"].value, this.f["password"].value)
      .then((res) => {
        this.loading = false;
        this.route.navigateByUrl('/dashboard');
      }, (err) => {
        this.loading = false;
        this.loginFailed = true;
      });
    }
  }

  isLoginFailed(): boolean {
    return this.loginFailed;
  }

  loginWithGoogle(): void {
    this.loginService.loginWithGoogle();
  }

  loginWithMicrosoft(): void {
    this.loginService.loginWithMicrosoft();
  }

  loginWithFacebook(): void {
    this.loginService.loginWithFacebook();
  }
  
  register(): void {
    console.log("register");
    this.route.navigateByUrl('/register');
  }
}
