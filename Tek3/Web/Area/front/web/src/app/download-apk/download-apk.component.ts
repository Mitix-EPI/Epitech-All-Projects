import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-download-apk',
  templateUrl: './download-apk.component.html',
  styleUrls: ['./download-apk.component.scss']
})
export class DownloadAPKComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
    const path = "../../../../mobile/build/app-debug.apk";
    // Download file from path
    const link = document.createElement("a");
    link.href = path;
    link.download = "app-debug.apk";
    link.click();
  }

}
