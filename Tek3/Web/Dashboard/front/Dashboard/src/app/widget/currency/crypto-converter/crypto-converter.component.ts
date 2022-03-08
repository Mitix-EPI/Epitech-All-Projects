import { Component, OnInit, Input, ComponentFactory, ComponentRef, ComponentFactoryResolver, ViewContainerRef, ViewChild, SimpleChanges, OnChanges} from '@angular/core';
import { ServiceWidget } from 'src/app/interfaces';
import { WidgetService } from 'src/app/service/widget.service';

@Component({
  selector: 'app-currency-crypto-converter',
  templateUrl: './crypto-converter.component.html',
  styleUrls: ['./crypto-converter.component.scss']
})

export class CryptoConverterComponent implements OnChanges {

  baseCryptoCurrency: any = 'BTC';
  targetCryptoCurrency: any = 'ETH';
  isLoading: boolean = false;
  convertedCurrency: any = null;
  @Input() service: ServiceWidget = {
    id: 0,
    service: 'CurrencyConverter',
    title: 'Crypto currency converter',
    icon: 'bi bi-cash',
    color: '#ffc107',
    coords: {x: 0, y: 0},
    city: 'BTC',
    date: 'ETH',
    urlProfile: '',
  };

  constructor(private widgetService: WidgetService) {
  }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      if (this.service.city !=='') {
        this.baseCryptoCurrency = this.service.city; // Dégeu de faire ça mais on va mettre le baseCurrency à la valeur du service.city
      }
      if (this.service.date !=='') {
        this.targetCryptoCurrency = this.service.date; // la même ici
      }
    }
  }

  convertCurrency() {
    this.isLoading = true;
    this.widgetService.getCryptoCurrency(this.baseCryptoCurrency, this.targetCryptoCurrency)
    .then(res => {
      this.isLoading = false;
      if (!res) {
        this.convertedCurrency = 'Internal Error';
      } else {
        const data = res.result;
        console.log('data', data);
        const item = this.targetCryptoCurrency;
        this.convertedCurrency = '1' + this.baseCryptoCurrency + ' = ' + data[item] + this.targetCryptoCurrency;
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
