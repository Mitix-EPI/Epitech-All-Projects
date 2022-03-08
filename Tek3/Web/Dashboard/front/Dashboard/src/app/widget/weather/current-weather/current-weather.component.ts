import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import {Observable, OperatorFunction} from 'rxjs';
import {debounceTime, distinctUntilChanged, filter, finalize, map} from 'rxjs/operators';
import { cities } from '../forecast-weather/cities';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-weather-current-weather',
  templateUrl: './current-weather.component.html',
  styleUrls: ['./current-weather.component.scss']
})
export class CurrentWeatherComponent implements OnChanges {

  weatherIcon: string = '';
  model: any;
  data: any;
  isLoading: boolean = false;
  @Input() service: ServiceWidget = {
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

  formatter = (city: string) => city;

  constructor(private widgetService: WidgetService) {
    if("geolocation" in navigator){
      navigator.geolocation.watchPosition((success)=>{
        const lat = success.coords.latitude;
        const lon = success.coords.longitude;

        setInterval(() => {
          this.widgetService.getCurrentWeatherDataByCords(lat, lon).
          then(res => {
            console.log(res);
            this.data = res;
            this.weatherIcon = this.getWeatherIcon(res.weather[0].icon);
          });
        }, 60000 * 5);
      })
    }
  }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      if (this.service.city !=='') {
        this.model = this.service.city;
        this.searchForecastForCity();
      }
    }
  }

  search: OperatorFunction<string, readonly string[]> = (text$: Observable<string>) => text$.pipe(
    debounceTime(200),
    distinctUntilChanged(),
    filter(term => term.length >= 2),
    map(term => cities.filter(city => new RegExp(term, 'mi').test(city)).slice(0, 10)),
    finalize(() => this.searchForecastForCity())
  )

  searchForecastForCity() {
    const city = this.model;
    console.log('city', city);
    if (city) {
      this.isLoading = true;
      this.widgetService.saveCityToWeatherWidget(this.service.id, city);
      this.widgetService.getCurrentWeather(city)
      .then(res => {
        this.isLoading = false;
        this.data = res;
        this.weatherIcon = this.getWeatherIcon(res.weather[0].icon);
      })
    } else {
      this.isLoading = true;
    }
    setInterval(this.searchForecastForCity, 60000 * 5);
  }

  getWeatherIcon(id: string): string {
    return 'http://openweathermap.org/img/w/' + id + '.png'
  }

}
