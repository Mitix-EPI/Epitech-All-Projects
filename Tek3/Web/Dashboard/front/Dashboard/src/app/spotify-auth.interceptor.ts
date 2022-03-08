import { Injectable } from  '@angular/core';
import  'rxjs/add/operator/do';
import { TokenService, SpotifyAuthInterceptor } from  'spotify-auth';

@Injectable()
export  class  SpotifyAuthInterceptor2  extends  SpotifyAuthInterceptor {

  doOnError(err:  any):  void {}

  constructor(tokenSvc:  TokenService) {
    super(tokenSvc);
  }
}
