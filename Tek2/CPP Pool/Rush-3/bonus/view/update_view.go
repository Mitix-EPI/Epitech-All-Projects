package view

import (
	t "time"

	"github.com/rivo/tview"
)

// UpdateTextView : update text view
func UpdateTextView(updateFunc func(chan string), textView *tview.TextView, app *tview.Application) {
	text := make(chan string)
	go func() {
		for {
			updateFunc(text)
			t.Sleep(1 * t.Second)
		}
	}()
	go func() {
		for {
			textView.SetText(<-text)
			app.Draw()
			t.Sleep(1 * t.Second)
		}
	}()
}
