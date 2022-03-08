import { Component, OnInit } from '@angular/core';
import { LoginService } from '../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-reddit',
  templateUrl: './reddit.component.html',
  styleUrls: ['./reddit.component.scss']
})
export class RedditComponent implements OnInit {

  constructor(private loginService: LoginService) { }

  ngOnInit(): void {
    // Get code in the url
    const code = window.location.href.split('code=')[1].split("#_")[0];
    console.log(code);
    this.loginService.getRedditAccessToken(code)
    .then(token_res => {
      console.log("token_res", token_res);
      this.loginService.registerToken("reddit", token_res.access_token)
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
