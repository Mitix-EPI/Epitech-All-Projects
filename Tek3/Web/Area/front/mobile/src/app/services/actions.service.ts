import { ApiService } from "./api.service";
import { Injectable } from "@angular/core";
import { firstValueFrom, lastValueFrom, Observable } from "rxjs";
import { AboutJSON } from "../interfaces/api-interface";

@Injectable({
  providedIn: "root",
})
export class ActionsService {
  constructor(private apiService: ApiService) {}

  async getAboutJSON(): Promise<AboutJSON.RootObject> {
    try {
      const data = await lastValueFrom(
        this.apiService.sendGetRequest("about.json")
      );
      return data.server;
    } catch (_) {
      throw new Error();
    }
  }

  async getServices(): Promise<AboutJSON.ServiceDescription[]> {
    const aboutJSON = await this.getAboutJSON();
    return aboutJSON.services;
  }

  getActionByName(
    aboutJSON: AboutJSON.RootObject,
    name: string
  ):
    | { service: AboutJSON.ServiceDescription; item: AboutJSON.Action }
    | undefined {
    for (const service of aboutJSON.services) {
      if (service.actions) {
        for (const action of service.actions) {
          if (action.name === name) {
            return { service, item: action };
          }
        }
      }
    }
    return undefined;
  }

  getReactionByName(
    aboutJSON: AboutJSON.RootObject,
    name: string
  ):
    | { service: AboutJSON.ServiceDescription; item: AboutJSON.Reaction }
    | undefined {
    for (const service of aboutJSON.services) {
      if (service.reactions) {
        for (const reaction of service.reactions) {
          if (reaction.name === name) {
            return { service, item: reaction };
          }
        }
      }
    }
    return undefined;
  }

  fillItem(item: any, actionData: any) {
    if (!actionData) return;
    item.service = {
      name: actionData!.service.name,
      icon: actionData!.service.icon,
    };
    item.description = actionData!.item.description;
    item.display_name = actionData!.item.display_name;
    item.arguments = [];
    for (const key in item) {
      const arg = actionData.item.arguments.find(
        (arg: any) => arg.name === key
      );
      if (arg) {
        item.arguments.push({
          name: arg.name,
          display_name: arg.display_name,
          value: item[key],
        });
      }
    }
  }

  async getReactions(): Promise<any> {
    const data = await lastValueFrom(
      this.apiService.sendGetRequest("actions_reactions/retrieve")
    );
    const aboutJSON = await this.getAboutJSON();
    const reactions = data.actions_reactions;
    for (const reaction of reactions) {
      reaction[2] = JSON.parse(reaction[2]); // action
      const actionData = this.getActionByName(aboutJSON, reaction[2].name);
      this.fillItem(reaction[2], actionData);
      reaction[3] = JSON.parse(reaction[3]); // reaction
      const reactionData = this.getReactionByName(aboutJSON, reaction[3].name);
      this.fillItem(reaction[3], reactionData);
    }
    return reactions;
  }

  addReaction(
    action: AboutJSON.Action,
    reaction: AboutJSON.Reaction,
    actionArgs: any,
    reactionArgs: any
  ): Observable<any> {
    const actionBluePrint = { ...action.object_blueprint };
    for (const key in actionBluePrint) {
      if (actionBluePrint[key] != null) continue;
      actionBluePrint[key] = actionArgs[key];
    }
    const reactionBluePrint = { ...reaction.object_blueprint };
    for (const key in reactionBluePrint) {
      if (reactionBluePrint[key] != null) continue;
      reactionBluePrint[key] = reactionArgs[key];
    }
    const reactionToAdd = {
      action: actionBluePrint,
      reaction: reactionBluePrint,
    };
    return this.apiService.sendPostRequest(
      "actions_reactions/add_reaction",
      reactionToAdd
    );
  }

  deleteReaction(id: number): Promise<void> {
    return firstValueFrom(
      this.apiService.sendPostRequest("actions_reactions/delete_reaction", {
        action_id: id,
      })
    );
  }

  getSubscriptions(): Promise<any> {
    return lastValueFrom(this.apiService.sendGetRequest("subscribe"));
  }
}
