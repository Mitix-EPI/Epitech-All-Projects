import { ApplicationRef, ChangeDetectorRef, Component, EventEmitter, Input, OnInit, Output } from '@angular/core';
import { ActionsService } from '../services/actions.service';

@Component({
  selector: 'app-action',
  templateUrl: './action.component.html',
  styleUrls: ['./action.component.scss'],
})
export class ActionComponent implements OnInit {
  @Input() reaction: any;
  @Output() newItemEvent = new EventEmitter();

  constructor(private actionsService: ActionsService,
              private changeDetector: ChangeDetectorRef,
              private app: ApplicationRef) { }

  ngOnInit() {}

  public deleteReaction(id: number) {
    console.log("clicked");
    this.actionsService.deleteReaction(id).then(() => {
      console.log("deleted");
      this.newItemEvent.emit(id.toString());
      this.changeDetector.detectChanges();
      this.app.tick();
    });
  }

}
