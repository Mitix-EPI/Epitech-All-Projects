import { Component, OnInit } from '@angular/core';
import { LoginService } from '../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-spotify',
  templateUrl: './spotify.component.html',
  styleUrls: ['./spotify.component.scss']
})
export class SpotifyComponent implements OnInit {

  constructor(private loginService: LoginService) { }

  ngOnInit(): void {
    // Get code in the url
    const code = window.location.href.split('code=')[1].split("&state=")[0];
    console.log(code);
    this.loginService.getSpotifyAccessToken(code)
    .then(token_res => {
      console.log("token", token_res);
      this.loginService.registerToken("spotify", token_res.access_token)
      .then(res => {
        console.log("res", res);
        // Redirect to the dashboard
        window.location.href = "/dashboard";
      }, err => {
        alert("Register Token Error" + err);
      });
    }, err => {
      alert("Get Access Token" + err);
    });
  }

}
