import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { IonicModule } from '@ionic/angular';
import { FormsModule } from '@angular/forms';

import { DashboardPage } from './dashboard.page';
import { DashboardPageRoutingModule } from './dashboard-routing.module';
import { ActionComponent } from '../action/action.component';
import { SocialAuthServiceConfig, SocialLoginModule } from 'angularx-social-login';
import { LoginService } from '../services/login.service';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    DashboardPageRoutingModule,
    SocialLoginModule
  ],
  declarations: [DashboardPage, ActionComponent],
  providers: [
    LoginService,
    {
      provide: 'SocialAuthServiceConfig',
      useValue: {
        autoLogin: false,
        providers: []
      } as SocialAuthServiceConfig,
    }
  ]
})
export class DashboardPageModule {}
