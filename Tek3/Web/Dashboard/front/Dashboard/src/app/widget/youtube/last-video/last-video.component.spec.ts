import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LastVideoComponent } from './last-video.component';

describe('LastVideoComponent', () => {
  let component: LastVideoComponent;
  let fixture: ComponentFixture<LastVideoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ LastVideoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(LastVideoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
