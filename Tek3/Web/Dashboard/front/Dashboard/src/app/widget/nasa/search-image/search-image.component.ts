import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-nasa-search-image',
  templateUrl: './search-image.component.html',
  styleUrls: ['./search-image.component.scss']
})
export class SearchImageComponent implements OnChanges {

  search: string = '';
  isLoading: boolean = false;
  data: any = '';
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
        this.search = this.service.urlProfile;
        this.searchImage();
      }
    }
  }

  searchImage() {
    this.isLoading = true;
    this.widgetService.saveUrlProfile(this.service.id, this.search);
    this.widgetService.getNasaImageSearch(this.search)
    .then((res: any) => {
      if (res) {
        console.log(res);
        this.data = res.result;
        console.log('searchImage', this.data);
        this.isLoading = false;
        this.error = false;
      } else {
        this.isLoading = false;
        this.error = true;
        this.data = '';
      }
    });
    setInterval(() => {
      this.searchImage();
    }, 60000 * 5);
  }

}
