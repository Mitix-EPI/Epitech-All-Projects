import { Component } from '@angular/core';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-nasa-today-photo',
  templateUrl: './today-photo.component.html',
  styleUrls: ['./today-photo.component.scss']
})
export class TodayPhotoComponent {

  nasaImgUrl: string = '';
  mediaType: 'img' | 'video' = 'img';

  constructor(private widgetService: WidgetService) {
    this.getTodayNasaImage();
  }

  getTodayNasaImage() {
    this.widgetService.getTodayNasaImage()
    .then(res => {
      console.log(res);
      this.nasaImgUrl = res.url
      if (res.media_type === 'video') {
        this.mediaType = 'video';
      } else {
        this.mediaType = 'img';
      }
    });
    setInterval(() => {
      this.getTodayNasaImage();
    }, 60000 * 5);
  }

}
