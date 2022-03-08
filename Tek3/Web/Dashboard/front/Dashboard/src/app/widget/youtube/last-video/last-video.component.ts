import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-youtube-last-video',
  templateUrl: './last-video.component.html',
  styleUrls: ['./last-video.component.scss']
})
export class LastVideoComponent implements OnChanges {

  videoId: string = '';
  channelName: string = '';
  isLoading: boolean = false;
  @Input() service: ServiceWidget = {
    id: 0,
    service: 'Youtube',
    title: 'Number of subscribers',
    icon: 'bi bi-youtube',
    color: '#dc3545',
    coords: {x: 0, y: 0},
    city: '',
    date: '',
    urlProfile: '',
  };
  error: boolean = false;

  constructor(private widgetService: WidgetService) { }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      if (this.service.urlProfile !=='') {
        this.channelName = this.service.urlProfile;
        this.searchVideoId();
      }
    }
  }

  searchVideoId() {
    this.isLoading = true;
    this.widgetService.saveUrlProfile(this.service.id, this.channelName);
    this.widgetService.getLatestVideoId(this.channelName)
    .then((res: any) => {
      if (res) {
        console.log(res);
        this.videoId = res.result.id.videoId;
        this.isLoading = false;
        this.error = false;
      } else {
        this.isLoading = false;
        this.error = true;
        this.videoId = '';
      }
    });
    setInterval(this.searchVideoId, 60000 * 5);
  }

  get urlIframe(): string {
    return 'https://www.youtube.com/embed/' + this.videoId + '?rel=0&amp;controls=0&amp;showinfo=0';
  }

}
