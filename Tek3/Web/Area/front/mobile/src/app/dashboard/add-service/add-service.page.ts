import { Component, OnInit, ViewChild } from '@angular/core';
import { IonContent, NavController } from '@ionic/angular';
import { AboutJSON } from 'src/app/interfaces/api-interface';
import { ActionsService } from 'src/app/services/actions.service';

@Component({
  selector: 'app-add-service',
  templateUrl: './add-service.page.html',
  styleUrls: ['./add-service.page.scss'],
})
export class AddServicePage implements OnInit {
    @ViewChild(IonContent) content: IonContent;

    scrollTo(elementId: string) {
        setTimeout(() => {
            let y = document.getElementById(elementId).offsetTop;
            this.content.scrollToPoint(0, y, 1000);
        }, 50);
    }

  public isLoading = false;
  public services: AboutJSON.ServiceDescription[] = [];

  public selectedService?: AboutJSON.ServiceDescription;
  public selectedActionTmp?: AboutJSON.Action; // Tmp is used while the user is setup-ing his action
  public selectedAction?: AboutJSON.Action;
  public selectedReaction?: AboutJSON.Reaction;

  public actionArgumentsValues: any = {};
  public reactionArgumentsValues: any = {};

  constructor(private actionsService: ActionsService,
    private navCtrl: NavController) {}

  ngOnInit() {
    this.actionsService.getServices().then((services) => {
      this.services = services;
      this.isLoading = false;
    });
  }

  public validateReaction() {
    this.actionsService.addReaction(
      this.selectedAction!,
      this.selectedReaction!,
      this.actionArgumentsValues,
      this.reactionArgumentsValues
    ).subscribe(() => {
      window.location.href = '/dashboard';
    });
  }

  public selectActionTmp(action: AboutJSON.Action) {
    this.selectedActionTmp = action;
    console.log("Scroll to the second step");
    this.scrollTo('secondstep');
    // Scroll to the second step
  }

  public selectReaction(reaction: AboutJSON.Reaction) {
    this.selectedReaction = reaction;
    console.log("Scroll to the third step");
    this.scrollTo('thirdstep');
    // this.scrollToElement('fourthstep', 800);
  }

}
