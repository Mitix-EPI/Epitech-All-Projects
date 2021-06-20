package system

import (
	"os/exec"
	"runtime"
	"strings"
	"bytes"
	"fmt"
)

// SysInfo : 
type SysInfo struct {
	name			string
	version 		string
	buildVersion	string
	buffer 			string
}

func execCommand(cmd *exec.Cmd) string {
	if cmd == nil {
		return ""
	}
	buf := &bytes.Buffer{}
	cmd.Stdout = buf

	if err := cmd.Run(); err != nil {
		return err.Error()
	}

	return buf.String()
}

// Init : init sysInfo struct
func (sys *SysInfo) Init() string {
	m := make(map[string]string)

	arg := []string{}

	var cmd *exec.Cmd
	switch runtime.GOOS {
	case "linux":
		arg = append(arg, "-a")
		cmd = exec.Command("lsb_release", arg...)
	case "darwin":
		cmd = exec.Command("sw_vers", arg...)
	default:
		cmd = exec.Command("sw_vers", arg...)
	}

	raw := execCommand(cmd)

	for _, row := range strings.Split(raw, "\n") {
		parts := strings.Split(row, ":")
		if len(parts) < 2 {
			continue
		}

		m[strings.TrimSpace(parts[0])] = strings.TrimSpace(parts[1])
	}

	var sysInfo *SysInfo
	switch runtime.GOOS {
	case "linux":
		sysInfo = &SysInfo{
			name:    m["Distributor ID"],
			version: m["Description"],
			buildVersion:   m["Release"],
		}
	default:
		sysInfo = &SysInfo{
			name:    m["ProductName"],
			version: m["ProductVersion"],
			buildVersion:   m["BuildVersion"],
		}

	}
	sys = sysInfo
	sys.buffer = fmt.Sprintf("\n\n\n\nName : %s\nversion : %s\nbuild version : %s\n", sys.name, sys.version, sys.buildVersion)
	return sys.buffer
}
