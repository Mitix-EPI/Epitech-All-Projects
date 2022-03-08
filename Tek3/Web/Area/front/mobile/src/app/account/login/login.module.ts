import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormBuilder, FormsModule, ReactiveFormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { LoginPageRoutingModule } from './login-routing.module';

import { LoginPage } from './login.page';
import { LoginService } from 'src/app/services/login.service';
import { SocialAuthServiceConfig, SocialLoginModule } from 'angularx-social-login';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    LoginPageRoutingModule,
    ReactiveFormsModule,
    SocialLoginModule
  ],
  declarations: [LoginPage],
  providers: [
    FormBuilder,
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
export class LoginPageModule {}
