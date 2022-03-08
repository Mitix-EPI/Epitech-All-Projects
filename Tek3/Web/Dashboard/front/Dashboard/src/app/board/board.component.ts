import { Component, OnInit, ViewChild, ViewEncapsulation } from '@angular/core';
import { Router } from '@angular/router';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { ServiceWidget } from '../interfaces/servicewidget.interface';
import { UserService } from '../service/user.service';
import { WidgetService } from '../service/widget.service';

const templateServiceWidgets: ServiceWidget[] = [];

const githubProfileStatWidget: ServiceWidget = {
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

const githubLanguageStatWidget: ServiceWidget = {
  id: 0,
  service: 'Github',
  title: 'Laguages stat',
  icon: 'bi bi-github',
  color: '#212529',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const youtubeNumberSubscribersOfChannelWidget: ServiceWidget = {
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

const youtubeLastVideoOfChannelWidget: ServiceWidget = {
  id: 0,
  service: 'Youtube',
  title: 'Last video',
  icon: 'bi bi-youtube',
  color: '#dc3545',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const nasaTodayWidget: ServiceWidget = {
  id: 0,
  service: 'NASA',
  title: "Today's photo",
  icon: 'fa fa-space-shuttle',
  color: '#0b3d91',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const nasaSearchImageWidget: ServiceWidget = {
  id: 0,
  service: 'NASA',
  title: "Search Image",
  icon: 'fa fa-space-shuttle',
  color: '#0b3d91',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const nasaXDayWidget: ServiceWidget = {
  id: 0,
  service: 'NASA',
  title: 'Nasa Image',
  icon: 'fa fa-space-shuttle',
  color: '#0b3d91',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const spotifyPlalistWidget: ServiceWidget = {
  id: 0,
  service: 'Spotify',
  title: 'Your weekly spotify playlist',
  icon: 'bi bi-spotify',
  color: '#1DB954',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const spotifyRecentsTracksWidget: ServiceWidget = {
  id: 0,
  service: 'Spotify',
  title: 'Your recently played tracks',
  icon: 'bi bi-spotify',
  color: '#1DB954',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const currentWeatherWidget: ServiceWidget = {
  id: 0,
  service: 'Weather',
  title: 'Current weather',
  icon: 'bi bi-weather',
  color: '#007bff',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const forecastWeatherWidget: ServiceWidget = {
  id: 0,
  service: 'Weather',
  title: 'Forecast weather',
  icon: 'bi bi-weather',
  color: '#007bff',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const currencyConverterWidget: ServiceWidget = {
  id: 0,
  service: 'CurrencyConverter',
  title: 'Price converter',
  icon: 'bi bi-cash',
  color: '#ffc107',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

const cryptoConverterWidget: ServiceWidget = {
  id: 0,
  service: 'CurrencyConverter',
  title: 'Crypto converter',
  icon: 'bi bi-cash',
  color: '#ffc107',
  coords: {x: 0, y: 0},
  city: '',
  date: '',
  urlProfile: '',
};

templateServiceWidgets.push(githubProfileStatWidget);
templateServiceWidgets.push(githubLanguageStatWidget);
templateServiceWidgets.push(youtubeNumberSubscribersOfChannelWidget);
templateServiceWidgets.push(youtubeLastVideoOfChannelWidget);
templateServiceWidgets.push(nasaTodayWidget);
templateServiceWidgets.push(nasaXDayWidget);
templateServiceWidgets.push(nasaSearchImageWidget);
templateServiceWidgets.push(spotifyPlalistWidget);
templateServiceWidgets.push(spotifyRecentsTracksWidget);
templateServiceWidgets.push(currentWeatherWidget);
templateServiceWidgets.push(forecastWeatherWidget);
templateServiceWidgets.push(currencyConverterWidget);
templateServiceWidgets.push(cryptoConverterWidget);

@Component({
  selector: 'app-board',
  templateUrl: './board.component.html',
  styleUrls: ['./board.component.scss'],
  encapsulation: ViewEncapsulation.None
})
export class BoardComponent implements OnInit {

  dragPosition = {x: 0, y: 0};

  isLoading: number = 0;

  widgetsArray: Array<ServiceWidget> = [];

  @ViewChild('NASAServiceModalComponent') nasaServiceModalComponent!: any;

  constructor(private modal: NgbModal,
    private userService: UserService,
    private router: Router, private widgetService: WidgetService) { }




  ngOnInit(): void {
    this.userService.refreshUser().then(res => {
      if (res) {
        this.isLoading += 1;
        this.widgetService.getWidgets()
        .then(res => {
          if (res) {
            this.isLoading += 1;
            const widgets = res.widgets;
            this.resetWidget(widgets);
          } else {
            console.log('Internal Error. Please contact support');
            setInterval(() => {
              this.widgetService.getWidgets()
              .then(res => {
                if (res) {
                  this.isLoading += 1;
                  const widgets = res.widgets;
                  this.resetWidget(widgets);
                } else {
                  alert('Internal Error. Please contact support');
                }
              });
            }, 3000);
          }
        });
      } else {
        this.userService.logout();
        this.router.navigate(['/account/login']);
      }
    });
  }

  resetWidget(widgets: any) {
    this.widgetsArray = [];
    widgets.forEach((widget: any) => {
      const goodWidget = templateServiceWidgets.find(w => w.title === widget.title);
      if (goodWidget) {
        const addedWidget = Object.assign({}, goodWidget);
        addedWidget.id = widget.id;
        addedWidget.coords = {x: widget.x, y: widget.y};
        addedWidget.city = widget.city;
        addedWidget.date = widget.date;
        addedWidget.urlProfile = widget.urlProfile;
        this.widgetsArray.push(addedWidget);
      }
    });
  }

  updateWidget(widgets: any) { // Optimized because no need to reset the array every time
    const results = widgets.filter(({ id: id1 }: any) => !this.widgetsArray.some(({ id: id2 }) => id2 === id1)); // Get the new widgets (but there is only one)
    if (results) {
      const widget = results[0];
      const goodWidget = templateServiceWidgets.find(w => w.title === widget.title);
      if (goodWidget) {
        const addedWidget = Object.assign({}, goodWidget);
        addedWidget.id = widget.id;
        addedWidget.coords = {x: widget.x, y: widget.y};
        addedWidget.city = widget.city;
        addedWidget.date = widget.date;
        this.widgetsArray.push(addedWidget);
      }
    }
  }

  closeWidget(index: number) {
    this.widgetService.deleteWidget(this.widgetsArray[index].id);
    this.widgetsArray.splice(index,1);
  }

  openServiceModal(content: any, customClass: string, size: 'sm' | 'lg' | 'xl') {
    this.modal.open(content, { centered: true, windowClass: customClass, size: size });
  }

  setToFirst(index: number) {
    let tmp = this.widgetsArray[index];
    this.widgetsArray.splice(index,1);
    this.widgetsArray.push(tmp);
  }

  addGithubProfileStatWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Github', githubProfileStatWidget.title, this.dragPosition, undefined, undefined, 'githubProfileUrl')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addGithubMostPopularRepoWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Github', githubLanguageStatWidget.title, this.dragPosition, undefined, undefined, 'githubProfileUrl')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addNbYoutubeSubscribersWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Youtube', youtubeNumberSubscribersOfChannelWidget.title, this.dragPosition, undefined, undefined, 'youtubeProfileUrl')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addLastYoutubeVideoWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Youtube', youtubeLastVideoOfChannelWidget.title, this.dragPosition, undefined, undefined, 'youtubeProfileUrl')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addNASATodayWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('NASA', nasaTodayWidget.title, this.dragPosition, undefined, undefined)
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addNASAXDayWidget() {
    this.modal.dismissAll();
    const yourDate = new Date()
    const date: string = yourDate.toISOString().split('T')[0]
    this.widgetService.registerWidget('NASA', nasaXDayWidget.title, this.dragPosition, date, undefined)
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addNASAImageSearchWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('NASA', nasaSearchImageWidget.title, this.dragPosition, undefined, undefined, '')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addSpotifyPlaylistWidget() {
    const authToken = this.widgetService.getSpotifyAuth();
    if (authToken) { // Token Exists
      // Already Loggedin
      this.modal.dismissAll();
      this.widgetService.registerWidget('Spotify', spotifyPlalistWidget.title, this.dragPosition, undefined, undefined)
      .then(res => {
        this.updateWidget(res.widgets);
      });
    } else {
      this.modal.dismissAll();
      this.widgetService.spotifyLogin();
    }
  }

  addSpotifyRecentTracksWidget() {
    const authToken = this.widgetService.getSpotifyAuth();
    if (authToken) { // Token Exists
      // Already Loggedin
      this.modal.dismissAll();
      this.widgetService.registerWidget('Spotify', spotifyRecentsTracksWidget.title, this.dragPosition, undefined, undefined)
      .then(res => {
        this.updateWidget(res.widgets);
      });
    } else {
      this.modal.dismissAll();
      this.widgetService.spotifyLogin();
    }
  }

  addCurrentWeatherWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Weather', currentWeatherWidget.title, this.dragPosition, undefined, 'Montpellier')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addForecastWeatherWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Weather', forecastWeatherWidget.title, this.dragPosition, undefined, 'Montpellier')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addCurrencyConverter() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('CurrencyConverter', currencyConverterWidget.title, this.dragPosition)
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addCryptoConverter() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('CurrencyConverter', cryptoConverterWidget.title, this.dragPosition)
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addSubscribersYoutubeWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Youtube', youtubeNumberSubscribersOfChannelWidget.title, this.dragPosition, undefined, undefined, '')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addLatestYoutubeVideoWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Youtube', youtubeLastVideoOfChannelWidget.title, this.dragPosition, undefined, undefined, '')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addGithubStatAccountWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Github', githubProfileStatWidget.title, this.dragPosition, undefined, undefined, '')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }

  addGithubLanguageWidget() {
    this.modal.dismissAll();
    this.widgetService.registerWidget('Github', githubLanguageStatWidget.title, this.dragPosition, undefined, undefined, '')
    .then(res => {
      this.updateWidget(res.widgets);
    });
  }
}
