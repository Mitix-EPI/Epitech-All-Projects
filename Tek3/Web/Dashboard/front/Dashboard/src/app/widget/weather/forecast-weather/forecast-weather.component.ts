import { Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import {Observable, OperatorFunction} from 'rxjs';
import {debounceTime, distinctUntilChanged, filter, finalize, map} from 'rxjs/operators';
import { cities } from './cities';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';


@Component({
  selector: 'app-weather-forecast-weather',
  templateUrl: './forecast-weather.component.html',
  styleUrls: ['./forecast-weather.component.scss']
})
export class ForecastWeatherComponent implements OnChanges {

  model: any;
  data: any;
  forecast: any[] = [];
  isLoading: boolean = false;
  @Input() service: ServiceWidget = {
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

  constructor(private widgetService: WidgetService) {
  }

  formatter = (city: string) => city;

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
      this.widgetService.getForecastWeatherDataByCords(city)
      .then(res => {
        this.isLoading = false;
        this.data = res;
        console.log('res getForecastWeatherDataByCords', res);
        this.forecast = res.forecast.forecastday;
      })
    } else {
      this.isLoading = true;
    }
    setInterval(this.searchForecastForCity, 60000 * 5);
  }

  getDate(str: string) {
    return new Date(str).toLocaleDateString("en-US")
  }

  getIconUrl(str: string) {
    let reg = /\/\/cdn.weatherapi.com\/weather\/64x64\/(.+)$/;

    str = str.replace(reg, "assets/weather/64x64/$1");
    return str;
  }

}
