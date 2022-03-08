import { Component, Input, OnChanges, SimpleChanges } from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-youtube-subscribers',
  templateUrl: './subscribers.component.html',
  styleUrls: ['./subscribers.component.scss']
})
export class SubscribersComponent implements OnChanges {

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

  channelName: any = null;
  isLoading: boolean = false;
  data: any = null;
  error: boolean = false;

  constructor(private widgetService: WidgetService) {}

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      if (this.service.urlProfile !=='') {
        this.channelName = this.service.urlProfile;
        this.searchNumberSubscribers();
      }
    }
  }

  searchNumberSubscribers() {
    this.widgetService.saveUrlProfile(this.service.id, this.channelName);
    this.isLoading = true;
    this.widgetService.getNumberSubscribers(this.channelName)
    .then((res: any) => {
      if (res) {
        this.isLoading = false;
        console.log(res);
        this.data = res.result;
        this.error = false;
      } else {
        this.isLoading = false;
        this.error = true;
        this.data = null;
      }
    });
    setInterval(this.searchNumberSubscribers, 60000 * 5);
  }

}
