import { Component, OnInit } from '@angular/core';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-spotify-playlist',
  templateUrl: './playlist.component.html',
  styleUrls: ['./playlist.component.scss']
})
export class PlaylistComponent implements OnInit {

  idPlaylist = '5ySgLxftnZWaAV4kI5aO1X';
  urlPlaylist: string = '';

  constructor(private widgetService: WidgetService) {
    this.getLatestSpotifyPlaylist();
  }

  ngOnInit(): void {
    this.urlPlaylist = this.getPlaylistUrl();
  }

  getLatestSpotifyPlaylist() {
    this.widgetService.getLatestSpotifyPlaylist()
    .then(res => {
      this.idPlaylist = res.id;
      this.urlPlaylist = this.getPlaylistUrl();
    });
    setInterval(this.getLatestSpotifyPlaylist, 60000 * 5);
  }

  getPlaylistUrl(): string {
    const res = 'https://open.spotify.com/embed/playlist/' + this.idPlaylist + '?utm_source=generator';
    console.log(res);
    return res;
  }

}
