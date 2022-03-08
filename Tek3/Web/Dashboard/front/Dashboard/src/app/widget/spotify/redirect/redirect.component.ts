import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { filter, map, tap } from 'rxjs/operators';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-redirect',
  templateUrl: './redirect.component.html',
  styleUrls: ['./redirect.component.scss']
})
export class RedirectComponent implements OnInit {

  constructor(private route: ActivatedRoute, private router: Router, private widgetService: WidgetService) { }

  ngOnInit(): void {
    let params = this.route.fragment.pipe(
      filter((fragment) => !!fragment),
      map((fragment) => new URLSearchParams(fragment as string)),
      map((params) => ({
        accessToken: params.get('access_token'),
        tokenType: params.get('token_type'),
        expiresIn: Number(params.get('expires_in')),
        state: params.get('state')
      })));
    params.subscribe(res => {
      let state = res.state;
      let accessToken = res.accessToken
      if (state === null || accessToken === null) {
        alert('Invalid state');
        return;
      } else {
        this.widgetService.setSpotifyAuth(accessToken);
        this.router.navigate(['/']);
      }
    })
  }

}
