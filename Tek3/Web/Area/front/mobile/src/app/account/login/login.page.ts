import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormControl, FormGroup, Validators } from '@angular/forms';
import { LoadingController, NavController } from '@ionic/angular';
import { ToastController } from '@ionic/angular';
import { ApiService } from 'src/app/services/api.service';
import { LoginService } from 'src/app/services/login.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.page.html',
  styleUrls: ['./login.page.scss'],
})
export class LoginPage implements OnInit {

  validations_form: FormGroup;
  errorMessage: string = '';
  loading: HTMLIonLoadingElement;
  loggedIn: boolean = false;
  serverIp: string = "http://localhost:8080";

  constructor(
    private loadingCtrl: LoadingController,
    public toastController: ToastController,
    private navCtrl: NavController,
    private formBuilder: FormBuilder,
    private loginService: LoginService,
    private apiService: ApiService) { }

  ngOnInit() {
    this.validations_form = this.formBuilder.group({
      email: new FormControl('', Validators.compose([
        Validators.required,
        Validators.pattern('^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+.[a-zA-Z0-9-.]+$')
      ])),
      password: new FormControl('', Validators.compose([
        Validators.minLength(5),
        Validators.required
      ])),
    });
  }

  validation_messages = {
    'email': [
      { type: 'required', message: 'Email is required.' },
      { type: 'pattern', message: 'Please enter a valid email.' }
    ],
    'password': [
      { type: 'required', message: 'Password is required.' },
      { type: 'minlength', message: 'Password must be at least 5 characters long.' }
    ]
  };

  login(value) {
    console.log(value);
    const email = value['email'];
    const password = value['password'];
    this.loginService.login(email, password)
    .then(res => {
      console.log(res);
      this.apiService.setServer(this.serverIp);
      this.navCtrl.navigateForward('/dashboard');
    }, err => {
      this.errorMessage = err.message;
    });
  }

  async facebookLogin() {
    this.loading = await this.loadingCtrl.create();
    this.loading.present();
    this.loggedIn = false;
    const error = "error";
    console.log('facebookLogin', error);
    if (error) {
      this.presentToast('Cordova is not available.');
      console.log('Facebook login failed. Cordova is not available - make sure to include cordova.js or run in a device');
    }
    this.loading.dismiss();
  }

  async presentToast(message: string) {
    const toast = await this.toastController.create({
      message: message,
      duration: 2000
    });
    toast.present();
  }

}
