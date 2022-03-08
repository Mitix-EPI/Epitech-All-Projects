import { ApplicationRef, ChangeDetectorRef, Component, OnInit } from '@angular/core';
import { ActionsService } from '../services/actions.service';
import { LoginService } from '../services/login.service';

@Component({
  selector: 'app-dashboard',
  templateUrl: 'dashboard.page.html',
  styleUrls: ['dashboard.page.scss'],
})
export class DashboardPage implements OnInit {
  public setupMode = false;
  
  public reactions: any[][] = [];

  constructor(private loginService: LoginService,
    private actionsService: ActionsService,
    private changeDetector: ChangeDetectorRef,
              private app: ApplicationRef
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

  public trackItem (index: number, item: any) {
    return item[0];
  }

  deleteAction(id: string) { // Cringe stuff to update correctly reactions
    this.setupMode = true;
    const res = this.reactions.filter((reaction) => reaction[0] !== Number(id));
    this.reactions = [];
    this.changeDetector.markForCheck();
    this.changeDetector.detectChanges();
    this.app.tick();
    this.reactions = res;
    this.changeDetector.markForCheck();
    this.changeDetector.detectChanges();
    this.app.tick();
    this.setupMode = false;
  }

  refresh(ev) {
    this.actionsService.getReactions().then((reactions) => {
      setTimeout(() => {
        this.reactions = reactions;
        ev.detail.complete();
      }, 500);
    });
  }

  logout() {
    console.log("Logout");
  }

}
