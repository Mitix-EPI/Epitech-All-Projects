package view

import (
	"fmt"
	"log"
	"strconv"
	"runtime"

	"github.com/ClementBolin/topGo/modules/time"
	"github.com/ClementBolin/topGo/modules/battery"
	"github.com/ClementBolin/topGo/modules/process"
	"github.com/ClementBolin/topGo/modules/history"
)

// refreshTextBattery : function who refresh text battery
func refreshTextBattery(text chan string) {
	var uptime time.Uptime
	var durateList string

	uptime.UpdateUptime()
	u := uptime.GetAll()

	statBattery, err := battery.FillStatBattery()
	if err != nil {
		log.Fatalln(err)
	}

	header := fmt.Sprintf("[red]%s[white]\nLoad average : %2.2f %2.2f %2.2f\nUptime : %s", u.Now ,u.AvgOne, u.AvgFive, u.AvgFifteen, u.Up)
	durateList = fmt.Sprintf("%s\n\nPerceantage : %2.2f\nDuration : %s\n", header, statBattery.GetPercentage(), statBattery.GetDuration())
	text <- durateList
}

// refreshTextProcess : function who refresh process list text
func refreshTextProcess(text chan string) {
	var processList string = fmt.Sprintf("[green]Name[white]%s[red]Pid[white]%s[yellow]Ppid[white]\n\n", calculSpaceProcessList("Name"), calculSpaceProcessList("pid  "))
	var processL []process.UnixProcess
	var err error

	if runtime.GOOS == "linux" {
		processL = process.ListProcessUnix()
	} else {
		processL = process.ListProcessUnix()
	}

	if err != nil {
		processList = fmt.Sprintf("[green]Name[white]%s[red]Pid[white]%s[yellow]Ppid[white]\n\n", calculSpaceProcessList("Name"), calculSpaceProcessList("pid  "))
	} else {
		for _, item := range processL {
			processList = processList + fmt.Sprintf("[green]%s[white]%s[red]%d[white]%s[yellow]%d[white]\n", item.GetName(), calculSpaceProcessList(item.GetName()) ,item.GetPid(), calculSpaceProcessList(strconv.Itoa(item.GetPid())), item.GetPpid())
		}
	}
	text <- processList
}

func refreshHistory(text chan string) {
	var history history.History

	history.GetHistoryCmd()
	buffer := history.GetCmd()
	text <- buffer
}
