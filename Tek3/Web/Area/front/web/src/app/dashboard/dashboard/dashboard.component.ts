import { ActionsService } from './../../../../../shared/src/lib/services/actions.service';
import { LoginService } from './../../../../../shared/src/lib/services/login.service';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss'],
})
export class DashboardComponent implements OnInit {
  public setupMode = false;

  public reactions: any[][] = [];

  constructor(
    private loginService: LoginService,
    private actionsService: ActionsService
  ) {}

  async ngOnInit() {
    await this.loginService.getUser().catch((err) => {
      window.location.href = '/login';
    });
    this.actionsService.getReactions().then((reactions) => {
      this.reactions = reactions;
    }).catch((err) => {
      window.location.href = '/login';
    });
  }

  public deleteReaction(id: number) {
    this.actionsService.deleteReaction(id).then(() => {
      this.reactions = this.reactions.filter((reaction) => reaction[0] !== id);
    });
  }
}
