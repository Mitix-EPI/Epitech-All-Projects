import { Component, OnInit } from '@angular/core';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-spotify-recent-tracks',
  templateUrl: './recent-tracks.component.html',
  styleUrls: ['./recent-tracks.component.scss']
})
export class RecentTracksComponent {

  arrTracks: any = [];
  tracksNumber: number = 3
  isLoading: boolean = false;

  constructor(private widgetService: WidgetService) {
    this.getTracksArray();
  }

  getUrl(item: any): string {
    const id = item.track.id;
    return 'https://open.spotify.com/embed/track/' + id + '?utm_source=generator';
  }

  changeTracksNumber(event: any) {
    this.getTracksArray();
  }

  getTracksArray() {
    this.isLoading = true;
    this.widgetService.getLatestSpotifyPlayedTracks(this.tracksNumber)
    .then(res => {
      this.isLoading = false;
      if (res) {
        this.arrTracks = res;
        console.log('tracks', this.arrTracks)
        this.arrTracks.forEach((item: any) => {
          item.url = this.getUrl(item);
        });
      } else {
        console.log('getTracksArray', res);
        alert('Error');
      }
    });
    setInterval(this.getTracksArray, 60000 * 5);
  }

}
