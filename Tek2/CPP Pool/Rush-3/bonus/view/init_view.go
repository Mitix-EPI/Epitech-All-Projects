package view

import (
	"fmt"
	"log"
	"strconv"
	"os"
	"runtime"

	"github.com/rivo/tview"
	"github.com/gdamore/tcell"
	"github.com/ClementBolin/topGo/modules/process"
	"github.com/ClementBolin/topGo/modules/battery"
	"github.com/ClementBolin/topGo/modules/time"
	"github.com/ClementBolin/topGo/modules/gitstatistic"
	"github.com/ClementBolin/topGo/modules/docker"
	"github.com/ClementBolin/topGo/modules/system"
	"github.com/ClementBolin/topGo/modules/history"
)

// Btop : struct who 
type Btop struct {
	app			*tview.Application;
	flex		*tview.Flex;
	process 	*tview.TextView;
	battery 	*tview.TextView;
	gitStat 	*tview.TextView;
	dockerStat 	*tview.TextView;
	system 		*tview.TextView;
	history 	*tview.TextView;
}

/*------------- Export Function ----------------*/

// Init : init app
func (app *Btop) Init() {
	app.app = tview.NewApplication()
	app.flex = tview.NewFlex()
	app.process = nil
	app.battery = nil
	app.dockerStat = nil
	app.bindsInit()
}

// InitHistoryTextView : init history widget textView
func (app *Btop) InitHistoryTextView() {
	var history history.History

	history.GetHistoryCmd()
	buffer := history.GetCmd()

	app.history = tview.NewTextView()
	app.history.SetBorder(true)
	app.history.SetText(buffer)
	app.history.SetTextAlign(tview.AlignLeft)
	app.history.SetTitle("History")
	app.history.SetBorderColor(tcell.ColorBurlyWood)
	app.history.SetWrap(true)
	app.history.SetDynamicColors(true)
	UpdateTextView(refreshHistory, app.history, app.app)
}

//InitSystemText : init system widget TextView
func (app *Btop) InitSystemText() {
	var sys system.SysInfo

	buffer := sys.Init()

	app.system = tview.NewTextView()
	app.system.SetBorder(true)
	app.system.SetText(buffer)
	app.system.SetTextAlign(tview.AlignCenter)
	app.system.SetTitle("System")
	app.system.SetBorderColor(tcell.ColorRed)
	app.system.SetWrap(true)
	app.system.SetDynamicColors(true)
}

// InitGitStatText : init git stat text view
func (app *Btop) InitGitStatText() {
	gitStat := gitstatistic.GitStat()

	app.gitStat = tview.NewTextView()
	app.gitStat.SetBorder(true)
	app.gitStat.SetText(gitStat)
	app.gitStat.SetTextAlign(tview.AlignCenter)
	app.gitStat.SetTitle("Git Stat " + os.Getenv("PWD"))
	app.gitStat.SetBorderColor(tcell.ColorBlue)
	app.gitStat.SetWrap(true)
	app.gitStat.SetDynamicColors(true)
}

// InitDockerStatText : init Docker widget TextView
func (app *Btop) InitDockerStatText() {
	var docker docker.DockerWidget

	docker.Init()
	docker.GetSystemInfo()
	docker.GetContainerInfo()

	app.dockerStat = tview.NewTextView()
	app.dockerStat.SetBorder(true)
	app.dockerStat.SetText(docker.GetBuffer())
	app.dockerStat.SetTextAlign(tview.AlignCenter)
	app.dockerStat.SetTitle("Docker Stat")
	app.dockerStat.SetBorderColor(tcell.ColorAquaMarine)
	app.dockerStat.SetWrap(true)
	app.dockerStat.SetDynamicColors(true)
}

// InitProcessText : init text view with process
func (app *Btop) InitProcessText() {
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

	app.process = tview.NewTextView()
	app.process.SetDynamicColors(true)
	app.process.SetText(processList)
	app.process.SetTextAlign(tview.AlignLeft)
	app.process.SetBorder(true)
	app.process.SetTitle("top")
	app.process.SetBorderColor(tcell.ColorBlue)
	app.flex.AddItem(app.process, 0, 2, false)
	UpdateTextView(refreshTextProcess, app.process, app.app)
}

// CreateBatteryTextView : create, update Battery TextView
func (app *Btop) CreateBatteryTextView() {
	var durateList string = ""
	var uptime time.Uptime

	uptime.InitUptime()
	u := uptime.GetAll()
	header := fmt.Sprintf("[red]%s[white]\nLoad average : %2.2f %2.2f %2.2f\nUptime : %s", u.Now ,u.AvgOne, u.AvgFive, u.AvgFifteen, u.Up)

	statBattery, err := battery.FillStatBattery()
	if err != nil {
		log.Fatalln("je te baise")
	}

	durateList = fmt.Sprintf("%s\n\nPerceantage : %2.2f\nDuration : %s\n", header, statBattery.GetPercentage(), statBattery.GetDuration())
	app.battery = tview.NewTextView()
	app.battery.SetBorder(true)
	app.battery.SetText(durateList)
	app.battery.SetTextAlign(tview.AlignCenter)
	app.battery.SetTitle("Power System")
	app.battery.SetBorderColor(tcell.ColorBlueViolet)
	app.battery.SetDynamicColors(true)
	UpdateTextView(refreshTextBattery, app.battery, app.app)

}

// InitMidpView : init mid view with 3 empty box
func (app *Btop) InitMidpView() {
	app.flex.AddItem(tview.NewFlex().SetDirection(tview.FlexRow).
					AddItem(app.battery, 0, 1, false).
					AddItem(app.system, 0, 1, true).
					AddItem(app.history, 0, 2, false), 0, 1, false)
}

// InitNotifView : Init notification view
func (app *Btop) InitNotifView() {
	app.flex.AddItem(tview.NewFlex().SetDirection(tview.FlexRow).
					AddItem(app.gitStat, 0, 1, false).
					AddItem(app.dockerStat, 0, 1, true), 0, 3, false)
}

/*------------- Export Function ----------------*/

func calculSpaceProcessList(str string) string {
	var totalSpace = 25;
	for i := 0; i != len(str) - 1; i++ { totalSpace-- }
	var spaceStr = ""
	for i := 0; i != totalSpace; i++ { spaceStr = spaceStr + " " }
	return spaceStr
}
