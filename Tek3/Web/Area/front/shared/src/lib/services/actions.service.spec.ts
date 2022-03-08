/* tslint:disable:no-unused-variable */

import { TestBed, async, inject } from '@angular/core/testing';
import { ActionsService } from './actions.service';

describe('Service: Actions', () => {
  beforeEach(() => {
    TestBed.configureTestingModule({
      providers: [ActionsService]
    });
  });

  it('should ...', inject([ActionsService], (service: ActionsService) => {
    expect(service).toBeTruthy();
  }));
});
