import { ComponentFixture, TestBed } from '@angular/core/testing';

import { XDayPhotoComponent } from './x-day-photo.component';

describe('XDayPhotoComponent', () => {
  let component: XDayPhotoComponent;
  let fixture: ComponentFixture<XDayPhotoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ XDayPhotoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(XDayPhotoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
