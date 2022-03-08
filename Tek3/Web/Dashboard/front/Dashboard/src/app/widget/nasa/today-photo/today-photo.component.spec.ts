import { ComponentFixture, TestBed } from '@angular/core/testing';

import { TodayPhotoComponent } from './today-photo.component';

describe('TodayPhotoComponent', () => {
  let component: TodayPhotoComponent;
  let fixture: ComponentFixture<TodayPhotoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ TodayPhotoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(TodayPhotoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
