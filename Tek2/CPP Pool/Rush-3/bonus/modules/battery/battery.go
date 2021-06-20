package battery

import (
	"fmt"
	"time"

	"github.com/distatus/battery"
)

// StatBattery : struct with battery stat value
type StatBattery struct {
	percentage 	float64;
	// state		bool;
	duration	string;
}

// GetPercentage : return battery percentage
func (stat StatBattery) GetPercentage() float64 {
	return stat.percentage
}

// GetDuration : return duration battery charge
func (stat StatBattery) GetDuration() string {
	return stat.duration
}

// FillStatBattery : init and fill StatBattery structure
func FillStatBattery() (*StatBattery, error) {
	var stat StatBattery
	batteries, err := battery.GetAll()

	if err != nil {
		return nil, err
	}
	for _, bat := range batteries {
		duration, err := time.ParseDuration(fmt.Sprintf("%fh", (bat.Current / bat.ChargeRate)))
		if err != nil {
			stat.duration = "failed to load duration charge"
		} else {
			stat.duration = duration.String()
		}
		stat.percentage = bat.Current / bat.Full * 100
	}
	return &stat, nil
}
