import { Component, OnInit } from '@angular/core';
import { UserService } from '../service/user.service';
import { WidgetService } from '../service/widget.service';
import {NgbModal, ModalDismissReasons} from '@ng-bootstrap/ng-bootstrap';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss']
})
export class HeaderComponent implements OnInit {

  urlCover: string = "";
  newUrl: string = "";
  myDate: Date = new Date();

  constructor(public userService: UserService, private modalService: NgbModal) {
    this.urlCover = userService.getCover();
  }

  ngOnInit(): void {
    this.utcTime();
  }

  changeCover(content: any) {
    this.newUrl = "";
    this.modalService.open(content, { centered: true }).result.then(_ => {
      console.log(this.newUrl);
      if (this.checkURL(this.newUrl)) {
        this.userService.updateCover(this.newUrl).then(
          (res) => {
            if (res) {
              this.urlCover = this.newUrl;
            }
          }
        );
      } else {
        alert("Invalid URL");
      }
    }).catch((_) => {});;
  }

  checkURL(url: string) {
    return(url.match(/\.(jpeg|jpg|gif|png)$/) !==null);
  }

  utcTime(): void {
    setInterval(() => {
      this.myDate = new Date();
    }, 1000);
  }

  logout() {
    this.userService.logout();
  }

}
