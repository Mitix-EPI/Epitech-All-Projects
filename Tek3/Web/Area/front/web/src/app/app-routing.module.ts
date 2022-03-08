import { DashboardComponent } from './dashboard/dashboard/dashboard.component';
import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { LoginComponent } from './account/login/login.component';
import { RegisterComponent } from './account/register/register.component';
import { NotFoundComponent } from './not-found/not-found.component';
import { SpotifyComponent } from './auth/spotify/spotify.component';
import { RedditComponent } from './auth/reddit/reddit.component';
import { DownloadAPKComponent } from './download-apk/download-apk.component';

const routes: Routes = [
  {path: '', redirectTo: 'login', pathMatch: 'full'},
  {path: 'login', component: LoginComponent},
  {path: 'register', component: RegisterComponent},
  {path: 'dashboard', component: DashboardComponent},
  {path: 'auth/spotify', component: SpotifyComponent},
  {path: 'auth/reddit', component: RedditComponent},
  {path: 'client.apk', component: DownloadAPKComponent},
  {path: '**', pathMatch: 'full', component: NotFoundComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
