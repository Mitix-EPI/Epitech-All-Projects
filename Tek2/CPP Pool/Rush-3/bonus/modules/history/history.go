package history

import (
	"fmt"
	"os"
	"os/user"
	"strings"
	"io/ioutil"
)

// History :
type History struct {
	cmd []string
}

// GetHistoryCmd :
func (h *History) GetHistoryCmd() {
	shell := os.Getenv("SHELL")
	tab := strings.Split(shell, "/")
	if len(tab) != 3 {
		h.cmd = make([]string, 1)
		h.cmd[0] = "Failed to load history"
		return
	}
	user, err := user.Current()
	if h.checkError(err) { return }
	switch tab[2] {
	case "zsh":
		datas, err := ioutil.ReadFile(user.HomeDir + "/.zsh_history")
		if h.checkError(err) {
			return
		}
		data := string(datas)
		tabData := strings.Split(data, "\n")
		h.cmd = make([]string, 25)
		j := 0
		i := 0
		if len(tabData) - 25 <= 0 {
			i = len(tabData)
		} else {
			i = len(tabData) - 25
		}
		for ; i != len(tabData) - 1; i++ {
			if tabData[i] == "" {
				return
			}
			h.cmd[j] = getNameCmdZSH(tabData[i])
			j++
		}
	case "bash":
		h.cmd = make([]string, 1)
		h.cmd[0] = "\n\n\n\nBash history in development"
	case "fish":
		h.cmd = make([]string, 1)
		h.cmd[0] = "\n\n\n\nfish history in development"
	default:
		h.cmd = make([]string, 1)
		h.cmd[0] = "Failed to load history"
		return
	}
}

// GetCmd : return string with all cmd
func (h *History) GetCmd() string {
	var str string = "\n\n"

	for _, item := range h.cmd {
		str = fmt.Sprintf("%s%s\n", str, item)
	}
	return str
}

func (h *History) checkError(err error) (bool) {
	if err != nil {
		h.cmd = make([]string, 1)
		h.cmd[0] = "Failed to load history"
		return true
	}
	return false
}

func getNameCmdZSH(cmd string) string {
	var new string
	for i := 0; cmd[i] != ';'; i++ {
		new = cmd[i+2:]		
	}
	return new
}
