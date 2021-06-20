package view

import (
	"github.com/gdamore/tcell"
)

func (app *Btop) bindsInit() {
	app.app.SetInputCapture(func(event *tcell.EventKey) (*tcell.EventKey) {
		switch event.Rune() {
		case 'q':
			app.app.Stop()
		case 'Q':
			app.app.Stop()
		}
		return event
	})
}
