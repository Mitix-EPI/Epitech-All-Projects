package process

import (

	ps "github.com/mitchellh/go-ps"
)

// ListProcessUnix : display your all process running on your system
func ListProcessUnix() []UnixProcess {
	var unixListProcess []UnixProcess

	listProcess, _ := ps.Processes()

	for item := range listProcess {
		var process ps.Process
		var myProcess UnixProcess
		process = listProcess[item]
		myProcess.SetName(process.Executable())
		myProcess.SetPid(process.Pid())
		myProcess.SetPpid(process.PPid())
		unixListProcess = append(unixListProcess, myProcess)
	}
	return unixListProcess
}
