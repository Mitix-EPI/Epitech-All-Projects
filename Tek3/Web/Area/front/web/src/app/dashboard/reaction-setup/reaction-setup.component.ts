import { ActionsService } from './../../../../../shared/src/lib/services/actions.service';
import { Component, OnInit } from '@angular/core';
import { AboutJSON } from '../../../../../shared/src/lib/interfaces/api-interface';
import { LoginService } from '../../../../../shared/src/lib/services/login.service';

@Component({
  selector: 'app-reaction-setup',
  templateUrl: './reaction-setup.component.html',
  styleUrls: ['./reaction-setup.component.scss'],
})
export class ReactionSetupComponent implements OnInit {
  public isLoading = false;
  public services: AboutJSON.ServiceDescription[] = [];

  public selectedService?: AboutJSON.ServiceDescription;
  public selectedActionTmp?: AboutJSON.Action; // Tmp is used while the user is setup-ing his action
  public selectedAction?: AboutJSON.Action;
  public selectedReaction?: AboutJSON.Reaction;

  public actionArgumentsValues: any = {};
  public reactionArgumentsValues: any = {};

  public subscriptions: any = {};

  constructor(private actionsService: ActionsService, private loginService: LoginService) {}

  ngOnInit() {
    this.actionsService.getServices().then((services) => {
      this.services = services;
      this.isLoading = false;
    });
    this.actionsService.getSubscriptions().then((subscriptions) => {
      this.subscriptions = subscriptions;
    });
  }

  scrollToElement(elementID: string, duration?: number) {
    setTimeout(() => {
      const item = document.getElementById(elementID); // the element
      if (item) {
        const itemPos = item.offsetTop - 120;
        this.scrollTo(window.document, itemPos, duration);
      }
    }, 100);
  }

  private scrollTo(element: any, to: number, duration: any, isContainer: boolean = false) {
    const increment = 20,
      that = this;
    let start: any,
      remaining: any,
      currentTime = 0,
      animateScroll: any;

    if (isContainer) {
      // for custom container element
      start = element.scrollTop;
    } else if (element.body.scrollTop > 0) {
      // for chrome
      start = element.body.scrollTop;
    } else if (element.documentElement.scrollTop > 0) {
      // for firefox
      start = element.documentElement.scrollTop;
    } else {
      start = 0;
    }

    remaining = to - start;

    animateScroll = () => {
      currentTime += increment;
      const val = that.easeInOut(currentTime, start, remaining, duration);
      if (isContainer) {
        element.scroll(0, val);
      } else {
        // to allow scroll function on different browsers both chrome and firefox
        top!.window.scroll(0, val);
      }

      if (currentTime < duration) {
        setTimeout(animateScroll, increment);
      }
    };
    animateScroll();
  }

  private easeInOut(
    currentTime: number,
    startTime: number,
    remainingTime: number,
    duration: number
  ) {
    currentTime /= duration / 2;

    if (currentTime < 1) {
      return (remainingTime / 2) * currentTime * currentTime + startTime;
    }

    currentTime--;
    return (
      (-remainingTime / 2) * (currentTime * (currentTime - 2) - 1) + startTime
    );
  }

  public selectActionTmp(action: AboutJSON.Action) {
    this.selectedActionTmp = action;
    this.scrollToElement('secondstep', 800);
  }

  public selectReaction(reaction: AboutJSON.Reaction) {
    this.selectedReaction = reaction;
    this.scrollToElement('fourthstep', 800);
  }

  public validateReaction() {
    this.actionsService.addReaction(
      this.selectedAction!,
      this.selectedReaction!,
      this.actionArgumentsValues,
      this.reactionArgumentsValues
    ).subscribe(() => {
      window.location.reload();
    });
  }

  getTokenByAuthority(token: any, serviceName: string) {
    let service: "google" | "facebook" | "office" | "epitech_intra" | "reddit" | "spotify" | null = null;
    if (serviceName == "Google")
      service = "google";
    else if (serviceName == "Facebook")
      service = "facebook";
    else if (serviceName == "Office")
      service = "office";
    else if (serviceName == "Intra Epitech")
      service = "epitech_intra";
    else if (serviceName == "Reddit")
      service = "reddit";
    else if (serviceName == "Spotify")
      service = "spotify";
    else
      alert("Internal Error" + serviceName);
    console.log(token, service);
    this.loginService.registerToken(service, token)
    .then(res => {
      console.log(res);
      // Refresh the page
      window.location.reload();
    }, err => {
      console.error(err);
      alert("Internal Error");
    });
  }
}
