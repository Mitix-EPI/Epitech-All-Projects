import { Injectable } from '@angular/core';
import { environment } from 'src/environments/environment';
import { HttpClient, HttpHeaders, HttpParams } from '@angular/common/http';
import { Router } from '@angular/router';
import { SocialAuthService } from 'angularx-social-login';
import { BehaviorSubject, Observable } from 'rxjs';
import { AuthConfig, AuthService, TokenService } from 'spotify-auth';
import { User } from '../interfaces';
import ls from 'localstorage-slim';
import { UserService } from './user.service';

function generateRandomString(length: number) {
  var text = '';
  var possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';

  for (var i = 0; i < length; i++) {
    text += possible.charAt(Math.floor(Math.random() * possible.length));
  }
  return text;
};

const SPOTIFY_AUTHORIZE_URL = 'https://accounts.spotify.com/authorize';
const SPOTIFY_SCOPES = [
  //Listening History
  'user-read-recently-played',
  'user-top-read',
  'user-read-playback-position',
  //Spotify Connect
  'user-read-playback-state',
  'user-modify-playback-state',
  'user-read-currently-playing',
  //Playback - For SDK Playback //https://developer.spotify.com/documentation/web-playback-sdk/quick-start/
  'streaming',
  //Playlists
  'playlist-modify-public',
  'playlist-modify-private',
  'playlist-read-private',
  'playlist-read-collaborative',
  //Library
  'user-library-modify',
  'user-library-read',
  //Users - For SDK Playback //https://developer.spotify.com/documentation/web-playback-sdk/quick-start/
  'user-read-email',
  'user-read-private'
];

@Injectable({
  providedIn: 'root'
})
export class WidgetService {

  urlCover: string = "";
  state: string = generateRandomString(16)

  constructor(private http: HttpClient,
    private socialAuthService: SocialAuthService,
    private router: Router, private spotifyAuthService: AuthService,
    private spotifyTokenSvc: TokenService, private userService: UserService) { }

  async registerWidget(service: 'Youtube' | 'Github' | 'NASA' | 'Spotify' | 'Weather' | 'CurrencyConverter', title: string, coords: {x: number, y: number}, date?: string, city?: string, urlProfile?: string) {
    const body = {
      id: this.userService.userValue.id,
      service,
      title,
      coords,
      date: date,
      city: city,
      urlProfile: urlProfile
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/widget/add-widget`, body)
    .toPromise();
    if (!res.error) {
      console.log("registerWidget Successful");
      return res;
    } else {
      console.log("registerWidget Failed");
      return false;
    }
  }

  async getWidgets() {
    const body = {
      id: this.userService.userValue.id
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/widget/get-widgets-by-user`, body)
    .toPromise();
    if (!res.error) {
      console.log("getWidgets Successful");
      return res;
    } else {
      console.log("getWidgets Failed");
      return false;
    }
  }

  async deleteWidget(widgetId: number) {
    const body = {
      id: widgetId
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/widget/delete-widget`, body)
    .toPromise();
    if (!res.error) {
      console.log("deleteWidget Successful");
      return res;
    } else {
      console.log("deleteWidget Failed");
      return false;
    }
  }

  async saveWidgetPosition(widgetId: number, position: {x: number, y: number}) {
    const body = {
      id: widgetId,
      position
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/widget/save-widget-position`, body)
    .toPromise();
    if (!res.error) {
      console.log("saveWidgetPosition Successful");
      return true;
    } else {
      console.log("saveWidgetPosition Failed");
      return false;
    }
  }

  async saveUrlProfile(widgetId: number, urlProfile: string) {
    const body = {
      id: widgetId,
      urlProfile
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/widget/save-url-profile`, body)
    .toPromise();
    if (!res.error) {
      console.log("saveUrlProfile Successful");
      return true;
    } else {
      console.log("saveUrlProfile Failed");
      return false;
    }
  }

  async getTodayNasaImage(): Promise<any> {
    const res = await this.http.get<any>(`${environment.apiUrl}/nasa/photo-of-today`).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getNasaImageOfDay(date: string): Promise<any> {
    let params = new HttpParams()
      .set('date', date);
    const res = await this.http.get<any>(`${environment.apiUrl}/nasa/photo-of-the-day`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getNasaImageSearch(search: string): Promise<any> {
    let params = new HttpParams()
      .set('search', search);
    const res = await this.http.get<any>(`${environment.apiUrl}/nasa/search-image`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async saveDateToNasaPhotoWidget(widgetId: number, date: string) { // TODO Route
    const body = {
      id: widgetId,
      date: date
    };
    console.log('saveDateToNasaPhotoWidget');
    const res = await this.http.post<any>(`${environment.apiUrl}/nasa/save-date-to-nasa-photo-widget`, body).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async spotifyLogin() {
    console.log('spotifyLogin');
    const ac: AuthConfig = {
      client_id: environment.spotifyClientId,
      response_type: "token",
      redirect_uri: environment.spotifyRedirectURL,
      state: this.state,
      show_dialog: true,
      scope: SPOTIFY_SCOPES.join(' ')
    };
    this.spotifyAuthService.configure(ac).authorize();
  }

  setSpotifyAuth(authToken: string) {
    ls.set('spotify-authtoken', authToken, { ttl: 3600 });
  }

  getSpotifyAuth(): string | null {
    return ls.get('spotify-authtoken');
  }

  async getLatestSpotifyPlaylist(): Promise<any> {
    const authToken = this.getSpotifyAuth();
    if (authToken === null) {
      this.spotifyLogin();
      return false;
    }
    let params = new HttpParams()
      .set('authToken', authToken);
    const res = await this.http.get<any>(`${environment.apiUrl}/spotify/get-latest-playlist`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getLatestSpotifyPlayedTracks(tracksNumber?: number): Promise<any> {
    const authToken = this.getSpotifyAuth();
    if (authToken === null) {
      this.spotifyLogin();
      return false;
    }
    let params = null;
    if (tracksNumber) {
      params = new HttpParams()
        .set('authToken', authToken)
        .set('tracksNumber', tracksNumber.toString());
    } else {
      params = new HttpParams()
        .set('authToken', authToken);
    }
    const res = await this.http.get<any>(`${environment.apiUrl}/spotify/get-recent-tracks`, { params }).toPromise();
    if (!res.error) {
      return res['items'];
    } else {
      return false;
    }
  }

  async getCurrentWeather(city: string): Promise<any> {
    let params = new HttpParams()
      .set('city', city);
    const res = await this.http.get<any>(`${environment.apiUrl}/weather/get-current-weather`, { params }).toPromise();
    console.log('getCurrentWeather ', res);
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getCurrentWeatherDataByCords(lat: number, lon: number): Promise<any> {
    let params = new HttpParams()
      .set('lat', lat)
      .set('lon', lon);
    const res = await this.http.get<any>(`${environment.apiUrl}/weather/get-current-weather-by-coords`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getForecastWeatherDataByCords(city: string): Promise<any> {
    let params = new HttpParams()
      .set('city', city);
    const res = await this.http.get<any>(`${environment.apiUrl}/weather/get-forecast-weather`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async saveCityToWeatherWidget(widgetId: number, city: string) {
    const body = {
      id: widgetId,
      city: city
    };
    console.log('saveCityToWeatherWidget');
    const res = await this.http.post<any>(`${environment.apiUrl}/weather/save-city-to-weather-widget`, body).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getCurrency(baseCurrency: string, targetCurrency: string): Promise<any> {
    let params = new HttpParams()
      .set('baseCurrency', baseCurrency)
      .set('targetCurrency', targetCurrency);
    const res = await this.http.get<any>(`${environment.apiUrl}/currency/currency-convertor`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getCryptoCurrency(baseCryptoCurrency: string, targetCryptoCurrency: string): Promise<any> {
    let params = new HttpParams()
      .set('baseCryptoCurrency', baseCryptoCurrency)
      .set('targetCryptoCurrency', targetCryptoCurrency);
    const res = await this.http.get<any>(`${environment.apiUrl}/currency/crypto-convertor`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getNumberSubscribers(channelName: string): Promise<any> {
    let params = new HttpParams()
      .set('channelName', channelName);
    const res = await this.http.get<any>(`${environment.apiUrl}/youtube/number-subscribers`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      alert(res.message);
      return false;
    }
  }

  async getGithubAccount(accountName: string): Promise<any> {
    let params = new HttpParams()
      .set('accountName', accountName);
    const res = await this.http.get<any>(`${environment.apiUrl}/github/get-github-account`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async searchChannelId(channelName: string): Promise<any> {
    let params = new HttpParams()
      .set('channelName', channelName);
    const res = await this.http.get<any>(`${environment.apiUrl}/youtube/get-channel-id`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }

  async getLatestVideoId(channelName: string): Promise<any> {
    let params = new HttpParams()
      .set('channelName', channelName);
    const res = await this.http.get<any>(`${environment.apiUrl}/youtube/get-last-video`, { params }).toPromise();
    if (!res.error) {
      return res;
    } else {
      return false;
    }
  }
}
