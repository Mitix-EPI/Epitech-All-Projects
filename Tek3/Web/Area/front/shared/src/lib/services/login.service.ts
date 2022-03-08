import { FacebookLoginProvider, GoogleLoginProvider, MicrosoftLoginProvider, SocialAuthService } from 'angularx-social-login';
import { ApiService } from "./api.service";
import { Injectable } from "@angular/core";
import { lastValueFrom, Observable } from "rxjs";

@Injectable({
  providedIn: "root",
})
export class LoginService {
  constructor(private apiService: ApiService, private socialAuthService: SocialAuthService) {}

  async login(mail: string, password: string): Promise<string> {
    try {
      const data = await lastValueFrom(
        this.apiService.sendPostRequest("auth/login", {
          mail,
          password,
        })
      );
      this.apiService.saveToken(data.token);
      return data.token;
    } catch (_) {
      throw new Error();
    }
  }

  async loginWithGoogle() {
    const userResponse = await this.socialAuthService.signIn(
      GoogleLoginProvider.PROVIDER_ID,
      {
        scope:
          "https://mail.google.com/ https://www.googleapis.com/auth/gmail.modify https://www.googleapis.com/auth/gmail.readonly https://www.googleapis.com/auth/gmail.addons.current.message.action https://www.googleapis.com/auth/gmail.addons.current.message.readonly",
      }
    );
    this.apiService
      .sendPostRequest("auth/login", {
        google_token: userResponse.response.access_token,
      })
      .subscribe({
        next: (data) => {
          console.log("Data", data);
          this.apiService.saveToken(data.token);
          window.location.href = "/dashboard";
        },
      });
  }

  async loginWithMicrosoft() {
    const userResponse = await this.socialAuthService.signIn(
      MicrosoftLoginProvider.PROVIDER_ID
    );
    this.apiService
      .sendPostRequest("auth/login", {
        office_token: userResponse.response.accessToken,
      })
      .subscribe({
        next: (data) => {
          console.log("Data", data);
          this.apiService.saveToken(data.token);
          window.location.href = "/dashboard";
        },
      });
  }

  async loginWithFacebook() {
    const userResponse = await this.socialAuthService.signIn(
      FacebookLoginProvider.PROVIDER_ID
    );
    this.apiService
      .sendPostRequest("auth/login", {
        facebook_token: userResponse.authToken,
      })
      .subscribe({
        next: (data) => {
          console.log("Data", data);
          this.apiService.saveToken(data.token);
          window.location.href = "/dashboard";
        },
      });
  }

  async register(mail: string, password: string): Promise<any> {
    return lastValueFrom(
      this.apiService.sendPostRequest("auth/register", { mail, password })
    );
  }

  async getUser(): Promise<any> {
    const token: string = this.apiService.getToken();
    return lastValueFrom(this.apiService.sendGetRequest(`token/get-user/${token}`));
  }

  async registerToken(service: "google" | "facebook" | "office" | "epitech_intra" | "reddit" | "spotify" | null, token: string): Promise<any> {
    return lastValueFrom(
      this.apiService.sendPostRequest(`subscribe/${service}`, { token })
    );
  }

  async getRedditAuthLink(): Promise<any> {
    return lastValueFrom(
      this.apiService.sendGetRequest("reddit/link")
    );
  }

  async getSpotifyAuthLink(): Promise<any> {
    return lastValueFrom(
      this.apiService.sendGetRequest("spotify/link")
    );
  }

  async getRedditAccessToken(code: string): Promise<any> {
    return lastValueFrom(
      this.apiService.sendGetRequest(`reddit/code/${code}`)
    );
  }

  async getSpotifyAccessToken(code: string): Promise<any> {
    return lastValueFrom(
      this.apiService.sendGetRequest(`spotify/code/${code}`)
    );
  }
}
