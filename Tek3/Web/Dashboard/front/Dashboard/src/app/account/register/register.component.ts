import { ANALYZE_FOR_ENTRY_COMPONENTS, Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})
export class RegisterComponent implements OnInit {
  form: FormGroup = new FormGroup({});
  loading = false;
  submitted = false;

  constructor(
      private formBuilder: FormBuilder,
      private router: Router,
      private userService: UserService,
      private route: ActivatedRoute
  ) { }

  ngOnInit() {
      this.form = this.formBuilder.group({
          email: ['', Validators.required],
          password: ['', [Validators.required, Validators.minLength(6)]]
      });
  }

  // convenience getter for easy access to form fields
  get f() { return this.form.controls; }

  onSubmit() {
      this.submitted = true;

      // stop here if form is invalid
      if (this.form.invalid) {
          return;
      }
      this.loading = true;
      const email = this.f.email.value;
      const password = this.f.password.value;
      this.userService.register(email, password)
      .subscribe((res: any) => {
        this.loading = true;
        if (res.error) {
          alert(res.error);
        } else {
          this.router.navigate(['../login'], { relativeTo: this.route });
        }
      });
      // TODO Register
      // this.userService.register(this.f.email.value, this.f.password.value)
      // this.router.navigate(['../login'], { relativeTo: this.route });
  }

}
