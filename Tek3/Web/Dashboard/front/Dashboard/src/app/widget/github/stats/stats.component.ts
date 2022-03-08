import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-github-stats',
  templateUrl: './stats.component.html',
  styleUrls: ['./stats.component.scss']
})
export class StatsComponent implements OnChanges {

  @Input() service: ServiceWidget = {
    id: 0,
    service: 'Github',
    title: 'Github profile stat',
    icon: 'bi bi-github',
    color: '#212529',
    coords: {x: 0, y: 0},
    city: '',
    date: '',
    urlProfile: '',
  };
  accountName: string = '';
  isLoading: boolean = false;
  error: boolean = false;
  url: string = '';

  constructor(private widgetService: WidgetService) { }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      if (this.service.urlProfile !=='') {
        this.accountName = this.service.urlProfile;
        this.searchGithubAccount();
      }
    }
  }

  searchGithubAccount() {
    this.isLoading = true;
    this.widgetService.saveUrlProfile(this.service.id, this.accountName);
    this.widgetService.getGithubAccount(this.accountName)
    .then((res: any) => {
      this.isLoading = false;
      console.log('searchGithubAccount', res);
      if (res && res.result && res.result.type !=="Organization" && res.result !=='Github account not found') {
        this.error = false;
        this.setUrlGithubStat(res.result.login);
      } else {
        this.error = true;
        this.url = '';
      }
    });
    setInterval(this.searchGithubAccount, 60000 * 5);
  }

  setUrlGithubStat(login: string) {
    this.url = 'https://github-readme-stats.vercel.app/api/?username=' + login + '&show_icons=true&title_color=fff&icon_color=79ff97&text_color=9f9f9f&bg_color=151515';
    console.log('url github', this.url);
  }

}
