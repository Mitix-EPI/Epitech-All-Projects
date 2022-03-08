import { SharedService } from '../../../shared/src/lib/shared.service';
import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
})
export class AppComponent {
  title = 'Area';

  constructor(private sharedService: SharedService) {
    this.sharedService.test();
  }
}
