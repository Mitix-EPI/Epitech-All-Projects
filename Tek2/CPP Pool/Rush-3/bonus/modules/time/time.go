package time

import (
	"time"

	"github.com/cloudfoundry/gosigar"
)

// Uptime : structure who save days, hours and sec of your system is runing
type Uptime struct {
	up			string
	now			string
	avgOne		float64
	avgFive		float64
	avgFifteen	float64
}

// AllUptime : for GetAll methode
type AllUptime struct {
	Up			string
	Now			string
	AvgOne		float64
	AvgFive		float64
	AvgFifteen	float64
}

// InitUptime : Update value in Uptime structure
func (u *Uptime) InitUptime() {
	uptime := sigar.Uptime{}
	uptime.Get()

	avg := new(sigar.LoadAverage)
	avg.Get()

	u.up = uptime.Format()
	u.now = time.Now().Format("Mon Jan 15:04:05")
	u.avgOne = avg.One
	u.avgFive = avg.Five
	u.avgFifteen = avg.Fifteen
}

// GetAll : get all fields in Uptime
func (u Uptime) GetAll() AllUptime {
	return AllUptime {
		Up: u.up,
		Now: u.now,
		AvgOne: u.avgOne,
		AvgFive: u.avgFive,
		AvgFifteen: u.avgFifteen,
	}
}

// UpdateUptime : update value in Uptime
func (u *Uptime) UpdateUptime() {
	uptime := sigar.Uptime{}
	uptime.Get()

	avg := new(sigar.LoadAverage)
	avg.Get()

	u.up = uptime.Format()
	u.now = time.Now().Format("Mon Jan 15:04:05")
	u.avgOne = avg.One
	u.avgFive = avg.Five
	u.avgFifteen = avg.Fifteen
}
