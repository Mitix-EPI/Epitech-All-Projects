import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DownloadAPKComponent } from './download-apk.component';

describe('DownloadAPKComponent', () => {
  let component: DownloadAPKComponent;
  let fixture: ComponentFixture<DownloadAPKComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DownloadAPKComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DownloadAPKComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
