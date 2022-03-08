import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { AddServicePageRoutingModule } from './add-service-routing.module';

import { AddServicePage } from './add-service.page';
import { ApiService } from 'src/app/services/api.service';
import { HttpClientModule } from '@angular/common/http';
import { ActionsService } from 'src/app/services/actions.service';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    AddServicePageRoutingModule,
    HttpClientModule
  ],
  declarations: [AddServicePage],
  providers: [ApiService, ActionsService]
})
export class AddServicePageModule {}
