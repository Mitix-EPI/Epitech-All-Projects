import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormBuilder, FormsModule, ReactiveFormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { RegisterPageRoutingModule } from './register-routing.module';
import { RegisterPage } from './register.page';
import { LoginService } from 'src/app/services/login.service';
import { SocialAuthServiceConfig, SocialLoginModule } from 'angularx-social-login';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    RegisterPageRoutingModule,
    ReactiveFormsModule,
    SocialLoginModule
  ],
  providers: [FormBuilder,
    LoginService,
    {
      provide: 'SocialAuthServiceConfig',
      useValue: {
        autoLogin: false,
        providers: []
      } as SocialAuthServiceConfig,
    }],
  declarations: [RegisterPage]
})
export class RegisterPageModule {}
