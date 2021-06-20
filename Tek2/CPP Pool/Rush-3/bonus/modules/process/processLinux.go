package process

import (
	"os"
	"io"
	"io/ioutil"
	"strings"
	"strconv"
)

// MyProccess : interface for process structure
type MyProccess interface {
	// get pid value
	GetPid() int;
	// get ppid value
	GetPpid() int;
	// get name value
	GetName() string
}

// UnixProcess : structure who defined unique process
type UnixProcess struct {
	name 	string;
	pid 	int;
	ppid 	int;
}

// GetPid : return value of pid process
func (p *UnixProcess) GetPid() int {
	return p.pid
}

// GetPpid : return value of ppid process
func (p *UnixProcess) GetPpid() int {
	return p.ppid
}

// GetName : return value of name process
func (p *UnixProcess) GetName() string {
	return p.name
}

// SetPid : set value pid
func (p *UnixProcess) SetPid(pid int) {
	p.pid = pid
}

// SetPpid : set value ppid
func (p *UnixProcess) SetPpid(ppid int) {
	p.ppid = ppid
}

// SetName : set value name
func (p *UnixProcess) SetName(name string) {
	p.name = name
}

// ListProcessLinux : return an list of all process runing in your system
// ListProcessLinux or return an error if we can't read data, in your /proc folder
func ListProcessLinux() ([]UnixProcess, error) {
	var processes []UnixProcess
	d, err := os.Open("/proc")
	if err != nil { return nil, err }
	defer d.Close()

	// processes = make([]UnixProcess, 20, 20)
	for {
		names, err := d.Readdirnames(10)
		if err == io.EOF {
			break
		}
		if err != nil {
			return nil, err
		}
		for _, name := range names {
			// We only care if the name starts with a numeric
			if name[0] < '0' || name[0] > '9' {
				continue
			}
			p, err := newLinuxProcess("/proc/" + name)
			if err != nil {
				continue
			}
			processes = append(processes, *p)
		}
	}

	return processes, nil
}

func newLinuxProcess(path string) (*UnixProcess, error) {
	
	lastPathChar := string(path[len(path)-1])
	if lastPathChar == "/" {
	path = path + "status"
	} else {
		path = path + "/status"
	}
	bufferByte, err := ioutil.ReadFile(path)
	if err != nil { return nil, err }
		
	arrayBuffer := strings.Split(string(bufferByte), "\n")
	p := new(UnixProcess)

	for _, item := range arrayBuffer {
		lineSplit := strings.Split(item, ":\t")
		if lineSplit[0] ==  "Name" { p.name = lineSplit[1] }
		if lineSplit[0] == "Pid" { p.pid, err = strconv.Atoi(lineSplit[1]) }
		if lineSplit[0] == "PPid" { p.ppid, err = strconv.Atoi(lineSplit[1]) }
	}
	return p, err
}
