import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { HttpClientModule, HTTP_INTERCEPTORS } from '@angular/common/http';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NgbDatepickerModule, NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { DragDropModule } from '@angular/cdk/drag-drop';
import { HeaderComponent } from './header/header.component';
import { BoardComponent } from './board/board.component';
import { WidgetComponent } from './widget/widget.component';
import { MomentModule } from 'ngx-moment';
import { FacebookLoginProvider, GoogleLoginProvider, MicrosoftLoginProvider, SocialAuthServiceConfig, SocialLoginModule, VKLoginProvider } from 'angularx-social-login';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { environment } from './../environments/environment';
import { FontAwesomeModule } from '@fortawesome/angular-fontawesome';
import { PlaylistComponent } from './widget/spotify/playlist/playlist.component';
import { SpotifyAuthInterceptor2 } from './spotify-auth.interceptor';
import { UserService } from './service/user.service';
import { AuthService, SpotifyAuthModule, TokenService } from 'spotify-auth';
import { RedirectComponent } from './widget/spotify/redirect/redirect.component';
import { SafePipe } from './safe.pipe';
import { RecentTracksComponent } from './widget/spotify/recent-tracks/recent-tracks.component';
import { TodayPhotoComponent } from './widget/nasa/today-photo/today-photo.component';
import { XDayPhotoComponent } from './widget/nasa/x-day-photo/x-day-photo.component';
import { CurrentWeatherComponent } from './widget/weather/current-weather/current-weather.component';
import { ForecastWeatherComponent } from './widget/weather/forecast-weather/forecast-weather.component';
import { CurrencyConverterComponent } from './widget/currency/currency-converter/currency-converter.component';
import { CryptoConverterComponent } from './widget/currency/crypto-converter/crypto-converter.component';
import { SubscribersComponent } from './widget/youtube/subscribers/subscribers.component';
import { LastVideoComponent } from './widget/youtube/last-video/last-video.component';
import { StatsComponent } from './widget/github/stats/stats.component';
import { LanguagesComponent } from './widget/github/languages/languages.component';
import { SearchImageComponent } from './widget/nasa/search-image/search-image.component';
import { WidgetService } from './service/widget.service';

const vkLoginOptions = {
  fields: 'photo_max,contacts', // Profile fields to return, see: https://vk.com/dev/objects/user
  version: '5.124', // https://vk.com/dev/versions
};

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    BoardComponent,
    WidgetComponent,
    PlaylistComponent,
    RedirectComponent,
    SafePipe,
    RecentTracksComponent,
    TodayPhotoComponent,
    XDayPhotoComponent,
    CurrentWeatherComponent,
    ForecastWeatherComponent,
    CurrencyConverterComponent,
    SubscribersComponent,
    LastVideoComponent,
    StatsComponent,
    LanguagesComponent,
    SearchImageComponent,
    CryptoConverterComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NgbModule,
    HttpClientModule,
    DragDropModule,
    MomentModule,
    SocialLoginModule,
    ReactiveFormsModule,
    FontAwesomeModule,
    FormsModule,
    NgbDatepickerModule
  ],
  providers: [
    UserService,
    AuthService,
    WidgetService,
    TokenService,
    {
      provide: 'SocialAuthServiceConfig',
      useValue: {
        autoLogin: false,
        providers: [
          {
            id: GoogleLoginProvider.PROVIDER_ID,
            provider: new GoogleLoginProvider(
              environment.googleClientId
            )
          },
          {
            id: FacebookLoginProvider.PROVIDER_ID,
            provider: new FacebookLoginProvider(
              environment.fbAppId
            )
          },
          {
            id: MicrosoftLoginProvider.PROVIDER_ID,
            provider: new MicrosoftLoginProvider(
              environment.microsoftClientId, {
              redirect_uri: 'http://localhost:4200',
              logout_redirect_uri: 'http://localhost:4200/logout',
            }),
          },
          {
            id: VKLoginProvider.PROVIDER_ID,
            provider: new VKLoginProvider(
              environment.vkAppId,
              vkLoginOptions
            ),
          }
        ]
      } as SocialAuthServiceConfig,
    },
    {
      provide: HTTP_INTERCEPTORS,
      useClass: SpotifyAuthInterceptor2, // Force interception.
      multi: true
    }
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
