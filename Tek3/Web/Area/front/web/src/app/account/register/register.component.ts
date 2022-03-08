import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { LoginService } from '../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})
export class RegisterComponent implements OnInit {

  form: FormGroup = new FormGroup({});
  loading: boolean = false;
  private formSubmitAttempt: boolean = false;

  constructor(private formBuilder: FormBuilder, private route: Router,
              private loginService: LoginService) { }

  ngOnInit() {
    this.form = this.formBuilder.group({
        email: ['', Validators.required],
        password: ['', Validators.required]
    },{updateOn:'submit'});
  }

  // convenience getter for easy access to form fields
  get f() { return this.form.controls; }

  isFieldValid(field: string) {
    if (this.form) {
      if (this.form.get(field)) {
        return (!this.form.get(field)!.valid && this.form.get(field)!.touched)
        || (this.form.get(field)!.untouched && this.formSubmitAttempt);
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  register(): void {
    console.log("register");
    if (this.form.valid) {
      this.loading = true;
      console.log("register success", this.f);
      this.loginService.register(this.f["email"].value, this.f["password"].value)
      .then(() => {
        this.loading = false;
        this.login();
      });
    }
  }

  login(): void {
    this.route.navigateByUrl('/login');
  }

}
