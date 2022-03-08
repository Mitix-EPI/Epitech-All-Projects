import { ReactionSetupComponent } from './dashboard/reaction-setup/reaction-setup.component';
import { DashboardComponent } from './dashboard/dashboard/dashboard.component';
import { SharedModule } from '../../../shared/src/lib/shared.module';
import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { HttpClientModule } from '@angular/common/http';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { RegisterComponent } from './account/register/register.component';
import { LoginComponent } from './account/login/login.component';
import { NotFoundComponent } from './not-found/not-found.component';
import { CommonModule } from '@angular/common';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { FacebookLoginProvider, GoogleLoginProvider, MicrosoftLoginProvider, SocialLoginModule } from 'angularx-social-login';
import { NavbarComponent } from './navbar/navbar.component';
import { AuthButtonComponent } from './dashboard/reaction-setup/auth-button/auth-button.component';
import { SpotifyComponent } from './auth/spotify/spotify.component';
import { RedditComponent } from './auth/reddit/reddit.component';
import { DownloadAPKComponent } from './download-apk/download-apk.component';

@NgModule({
  declarations: [
    AppComponent,
    RegisterComponent,
    LoginComponent,
    NotFoundComponent,
    NavbarComponent,
    DashboardComponent,
    ReactionSetupComponent,
    AuthButtonComponent,
    SpotifyComponent,
    RedditComponent,
    DownloadAPKComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    SharedModule,
    HttpClientModule,
    CommonModule,
    ReactiveFormsModule,
    FormsModule,
    SocialLoginModule,
  ],
  providers: [
    {
      provide: "SocialAuthServiceConfig",
      useValue: {
        autoLogin: true,
        providers: [
          {
            id: GoogleLoginProvider.PROVIDER_ID,
            provider: new GoogleLoginProvider(
              "653520408818-99bnbmu2puoppkfbgtopg5ajgfncn042.apps.googleusercontent.com"
            ),
          },
          {
            id: MicrosoftLoginProvider.PROVIDER_ID,
            provider: new MicrosoftLoginProvider(
              "ddff1f59-f7bc-4314-9015-0c73ad43fd48",
              {
                authority:
                  "https://login.microsoftonline.com/901cb4ca-b862-4029-9306-e5cd0f6d9f86/",
                scopes: ["openid", "email", "profile", "Calendars.Read", "User.Read", "Tasks.ReadWrite",
                "Contacts.Read", "Contacts.ReadWrite", "Mail.Read", "Mail.Send", "Mail.Read", "Mail.ReadBasic",
                "Mail.ReadWrite", "Calendars.ReadWrite", "Calendars.ReadWrite.Shared"]
             }
            ),
          },
          {
            id: FacebookLoginProvider.PROVIDER_ID,
            provider: new FacebookLoginProvider("864939734206019"),
          },
        ],
      },
    },
  ],
  bootstrap: [AppComponent]
})
export class AppModule {}
