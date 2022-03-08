import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { BoardComponent } from './board/board.component';
import { AuthGuard } from './auth'
import { SpotifyAuthModule } from 'spotify-auth';
import { RedirectComponent } from './widget/spotify/redirect/redirect.component';

const accountModule = () => import('./account/account.module').then(x => x.AccountModule);

const routes: Routes = [
  { path: '', component: BoardComponent, canActivate: [AuthGuard] }, // TODO unset commentaries
  { path: 'account', loadChildren: accountModule },
  { path: 'spotify/authorized', component: RedirectComponent },
  { path: '**', redirectTo: '' },
  SpotifyAuthModule.authRoutes()[0]
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
