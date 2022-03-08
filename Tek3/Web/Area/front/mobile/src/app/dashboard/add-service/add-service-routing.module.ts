import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { AddServicePage } from './add-service.page';

const routes: Routes = [
  {
    path: '',
    component: AddServicePage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class AddServicePageRoutingModule {}
