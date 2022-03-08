import { ActionsService } from './services/actions.service';
import { LoginService } from './services/login.service';
import { ApiService } from "./services/api.service";
import { NgModule } from "@angular/core";
import { SharedComponent } from "./shared.component";

@NgModule({
  declarations: [SharedComponent],
  imports: [],
  exports: [SharedComponent],
  providers: [ApiService, LoginService, ActionsService],
})
export class SharedModule {}
