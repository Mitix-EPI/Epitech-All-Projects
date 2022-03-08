import { Component, OnInit, Input, ComponentFactory, ComponentRef, ComponentFactoryResolver, ViewContainerRef, ViewChild, SimpleChanges, OnChanges} from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-currency-currency-converter',
  templateUrl: './currency-converter.component.html',
  styleUrls: ['./currency-converter.component.scss']
})

export class CurrencyConverterComponent implements OnChanges {

  baseCurrency: any = 'EUR';
  targetCurrency: any = 'USD';
  isLoading: boolean = false;
  convertedCurrency: any = null;
  @Input() service: ServiceWidget = {
    id: 0,
    service: 'CurrencyConverter',
    title: 'Price converter',
    icon: 'bi bi-cash',
    color: '#ffc107',
    coords: {x: 0, y: 0},
    city: 'EUR',
    date: 'USD',
    urlProfile: '',
  };

  constructor(private widgetService: WidgetService) {
  }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      if (this.service.city !=='') {
        this.baseCurrency = this.service.city; // Dégeu de faire ça mais on va mettre le baseCurrency à la valeur du service.city
      }
      if (this.service.date !=='') {
        this.targetCurrency = this.service.date; // la même ici
      }
    }
  }

  convertCurrency() {
    this.isLoading = true;
    this.widgetService.getCurrency(this.baseCurrency, this.targetCurrency)
    .then(res => {
      this.isLoading = false;
      if (!res) {
        this.convertedCurrency = 'Internal Error';
      } else {
        const data = res.result;
        const item = this.baseCurrency + '_' + this.targetCurrency;
        this.convertedCurrency = '1' + this.baseCurrency + ' = ' + data[item] + this.targetCurrency;
      }
    });
    setInterval(this.convertCurrency, 60000 * 5);
  }

  changeBaseCurrency(currency: string) {
    this.widgetService.saveCityToWeatherWidget(this.service.id, currency);
  }

  changeTargetCurrency(currency: string) {
    this.widgetService.saveDateToNasaPhotoWidget(this.service.id, currency);
  }
}
