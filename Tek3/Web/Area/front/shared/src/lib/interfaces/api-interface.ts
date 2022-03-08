export declare module AboutJSON {

  export interface Option {
    name: string;
  }

  export interface Argument {
    display_name: string;
    name: string;
    type: string;
    default: any;
    options: Option[];
  }

  export interface Action {
    display_name: string;
    name: string;
    description: string;
    arguments: Argument[];
    object_blueprint: any;
  }

  export interface Reaction {
    display_name: string;
    name: string;
    description: string;
    arguments: Argument[];
    object_blueprint: any;
  }

  export interface ServiceDescription {
    display_name: string;
    name: string;
    icon: string;
    authentication_required?: string;
    actions: Action[];
    reactions: Reaction[];
  }

  export interface RootObject {
    time: number;
    services: ServiceDescription[];
  }
}
