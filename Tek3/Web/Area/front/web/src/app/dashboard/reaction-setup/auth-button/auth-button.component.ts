import { Component, EventEmitter, Input, OnInit, Output } from '@angular/core';
import { FacebookLoginProvider, GoogleLoginProvider, MicrosoftLoginProvider, SocialAuthService } from 'angularx-social-login';
import { LoginService } from '../../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-auth-button',
  templateUrl: './auth-button.component.html',
  styleUrls: ['./auth-button.component.scss']
})
export class AuthButtonComponent implements OnInit {

  @Input() serviceName: string = "";
  @Output() getToken = new EventEmitter();

  intraEpitechToken: string = "";

  constructor(private socialAuthService: SocialAuthService, private loginService: LoginService) { }

  ngOnInit(): void {
  }

  async loginWithFacebook() {
    const userResponse = await this.socialAuthService.signIn(
      FacebookLoginProvider.PROVIDER_ID
    );
    const facebookToken = userResponse.authToken;
    this.getToken.emit(facebookToken);
  }

  async loginWithGoogle() {
    const userResponse = await this.socialAuthService.signIn(
      GoogleLoginProvider.PROVIDER_ID,
      {
        scope:
          "https://mail.google.com/ https://www.googleapis.com/auth/gmail.modify https://www.googleapis.com/auth/gmail.readonly https://www.googleapis.com/auth/gmail.addons.current.message.action https://www.googleapis.com/auth/gmail.addons.current.message.readonly",
      }
    );
    const googleToken = userResponse.response.access_token;
    this.getToken.emit(googleToken);
  }

  async loginWithMicrosoft() {
    const userResponse = await this.socialAuthService.signIn(
      MicrosoftLoginProvider.PROVIDER_ID
    );
    const microsoftToken = userResponse.response.accessToken;
    this.getToken.emit(microsoftToken);
  }

  loginWithReddit() {
    this.loginService.getRedditAuthLink()
    .then(res => {
        console.log(res);
        window.location.href = res.link;
      }, err => {
        alert(err);
      }
    )
  }

  loginWithSpotify() {
    this.loginService.getSpotifyAuthLink()
    .then(res => {
        console.log(res);
        window.location.href = res.link;
      }, err => {
        alert(err);
      }
    )
  }

  loginWithIntraEpitech() {
    if (this.intraEpitechToken) {
      this.getToken.emit(this.intraEpitechToken);
    } else {
      alert("Please enter your intraEpitech token");
    }
  }

}
