import { CdkDragEnd } from '@angular/cdk/drag-drop';
import { Component, OnInit, Input, Output, EventEmitter, OnChanges, SimpleChanges } from '@angular/core';
import { ServiceWidget } from '../interfaces/servicewidget.interface';
import { WidgetService } from '../service/widget.service';

@Component({
  selector: 'app-widget',
  templateUrl: './widget.component.html',
  styleUrls: ['./widget.component.scss']
})
export class WidgetComponent implements OnChanges {

  @Output() closeWidget = new EventEmitter<boolean>();

  @Input() service: ServiceWidget = {
    id: 0,
    service: 'NASA',
    title: "Today's photo",
    icon: 'fa fa-space-shuttle',
    color: '#0b3d91',
    coords: {x: 0, y: 0},
    city: '',
    date: '',
    urlProfile: '',
  };

  @Input() position: number = 0;

  dragPosition = {x: 0, y: 0};

  constructor(private widgetService: WidgetService) { }

  ngOnChanges(changes: SimpleChanges) {
    // only run when property "service" changed
    if (changes['service']) {
      console.log('changes', this.service);
      this.dragPosition.x = this.service.coords.x;
      this.dragPosition.y = this.service.coords.y;
    }
  }

  closeWidgetFct() {
    this.closeWidget.emit(true);
  }

  dragEnd($event: CdkDragEnd) {
    const position = $event.source.getFreeDragPosition()
    this.widgetService.saveWidgetPosition(this.service.id, position);
  }

}
