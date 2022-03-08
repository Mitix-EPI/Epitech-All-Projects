import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import { NgbCalendar, NgbDateStruct } from '@ng-bootstrap/ng-bootstrap';
import * as moment from 'moment';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-nasa-x-day-photo',
  templateUrl: './x-day-photo.component.html',
  styleUrls: ['./x-day-photo.component.scss']
})
export class XDayPhotoComponent implements OnInit, OnChanges {

  nasaImgUrl: string = '';
  mediaType: 'img' | 'video' = 'img';
  maxDate: Date = new Date();
  model: any = null;
  date: any = null;
  @Input() service: ServiceWidget = {
    id: 0,
    service: 'NASA',
    title: 'Nasa Image',
    icon: 'fa fa-space-shuttle',
    color: '#0b3d91',
    coords: {x: 0, y: 0},
    city: '',
    date: 'null',
    urlProfile: '',
  };

  constructor(private widgetService: WidgetService, private ngbCalendar: NgbCalendar) {}

  ngOnInit(): void {
    if (this.service.date !=='' && this.service.date !=='null') {
      const model = moment(this.service.date).toObject();
      this.model = {
        year: model.years,
        month: model.months + 1,
        day: model.date
      };
      let date = this.model.year.toString() + '-' + (this.model.month) + '-' + this.model.day.toString();
      this.changeDate(null, date);
    }
  }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      if (this.service.date !=='') {
        const model = moment(this.service.date).toObject();
        this.model = {
          year: model.years,
          month: model.months,
          day: model.date
        };
      }
    }
  }

  formatDate(date: string) {
    var d = new Date(date),
        month = '' + (d.getMonth() + 1),
        day = '' + d.getDate(),
        year = d.getFullYear();

    if (month.length < 2)
        month = '0' + month;
    if (day.length < 2)
        day = '0' + day;

    return [year, month, day].join('-');
  }

  changeDate(event: any, date?: any) {
    if (date) {
      this.date = date;
    } else if (event && event.year && event.month && event.day) {
      let date = event.year.toString() + '-' + event.month.toString() + '-' + event.day.toString();
      this.date = date;
    }
    this.widgetService.saveDateToNasaPhotoWidget(this.service.id, this.date);
    this.widgetService.getNasaImageOfDay(this.date)
    .then(res => {
      console.log(res);
      if (res.media_type === 'video') {
        this.mediaType = 'video';
      } else {
        this.mediaType = 'img';
      }
      this.nasaImgUrl = res.url;
    });
    setInterval(this.changeDate, 60000 * 5);
  }


}
