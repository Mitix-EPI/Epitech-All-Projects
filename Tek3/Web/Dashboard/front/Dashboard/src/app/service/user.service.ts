import { HttpClient, HttpHeaders, HttpParams } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { SocialAuthService } from 'angularx-social-login';
import { BehaviorSubject, Observable } from 'rxjs';
import { AuthConfig, AuthService, TokenService } from 'spotify-auth';
import { environment } from 'src/environments/environment';
import { User } from '../interfaces';

function generateRandomString(length: number) {
  var text = '';
  var possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';

  for (var i = 0; i < length; i++) {
    text += possible.charAt(Math.floor(Math.random() * possible.length));
  }
  return text;
};

@Injectable({
  providedIn: 'root'
})
export class UserService {

  isLoggedIn: boolean = false;
  isOAuth2: boolean = false;

  private userSubject!: BehaviorSubject<User | any>;
  public user!: Observable<User>;

  constructor(private http: HttpClient,
    private socialAuthService: SocialAuthService,
    private router: Router, private spotifyAuthService: AuthService, private spotifyTokenSvc: TokenService) {
      const userStorage = localStorage.getItem('user');
      let json = JSON.parse(userStorage && userStorage !== "undefined" ? userStorage : JSON.stringify(null))
      if (json === 'null') {
        json = null;
      }
      this.userSubject = new BehaviorSubject<User | any>(json);
      this.user = this.userSubject.asObservable();
      if (json !==null) {
        this.isLoggedIn = true;
        if (json.idOAuth2) {
          this.isOAuth2 = true;
        } else {
          this.isOAuth2 = false;
        }
      }
    }

  public get userValue(): User {
    return this.userSubject.value;
  }

  async refreshUser(): Promise<boolean> {
    const userId = this.userValue.id;
    let params = new HttpParams()
      .set('id', userId);
    const res = await this.http.get<any>(`${environment.apiUrl}/users/get-user`, { params }).toPromise();
    if (!res.error) {
      localStorage.setItem('user', JSON.stringify(res));
      this.userSubject.next(res);
      this.isLoggedIn = true;
      return true;
    } else {
      return false;
    }
  }

  public getCover(): string {
    const defaultCover = "https://bootstrapious.com/i/snippets/sn-static-header/background.jpg";
    return this.userValue.urlCover ? this.userValue.urlCover : defaultCover;
  }

  register(email: string, password: string) {
    return this.http.post<any>(`${environment.apiUrl}/users/register`, { email, password });
  }

  async login(user: User) {
    if (user.idOAuth2) {
      this.isOAuth2 = true;
    }
    const res = await this.http.post<any>(`${environment.apiUrl}/users/authenticate`, user)
    .toPromise();
    console.log('Login', res);
    if (!res.error) {
      this.isLoggedIn = true;
      localStorage.setItem('user', JSON.stringify(res.user));
      this.userSubject.next(res.user);
    }
    return res;
  }

  logout() {
    this.userSubject.next(null);
    if (this.isLoggedIn && this.isOAuth2) {
      this.socialAuthService.signOut();
    }
    localStorage.removeItem('user');
    this.isLoggedIn = false;
    this.isOAuth2 = false;
    this.router.navigate(['/account/login']);
  }

  async updateCover(url: string): Promise<boolean> {
    const body = {
      urlCover: url,
      id: this.userValue.id
    };
    const res = await this.http.post<any>(`${environment.apiUrl}/users/update-url-cover`, body)
    .toPromise();
    if (!res.error) {
      console.log("Cover Update Successful");
      return true;
    } else {
      console.log("Cover Update Failed");
      return false;
    }
  }

}
