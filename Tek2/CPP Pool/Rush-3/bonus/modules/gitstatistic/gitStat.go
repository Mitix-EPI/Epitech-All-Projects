package gitstatistic

import (
	"io/ioutil"
	"os"
	"strings"

	"github.com/ClementBolin/topGo/modules/gitstatistic/scan"
	"github.com/ClementBolin/topGo/modules/gitstatistic/ui"
)

// Deleate char at indx
func delChar(s []rune, index int) []rune {
	return append(s[0:index], s[index+1:]...)
}

// clear path string
func clearPath(path string) string {
	for i := 0; i != len(path)-2; i++ {
		c := string(path[i])
		c1 := string(path[i+1])
		if c == "/" && c1 == "/" {
			path = string(delChar([]rune(path), i))
		}
	}
	return path
}

func readEmail() string {
	home := strings.Split(os.Getenv("HOME"), "=")
	datas, err := ioutil.ReadFile(home[0] + "/.btop_config")
	if err != nil {
		return ""
	}
	return strings.Replace(string(datas), "\n", "", -1)
}

// GitStat : GitStat module
func GitStat() string {
	var emailFlag string = readEmail()

	if emailFlag == "" {
		var home = strings.Split(os.Getenv("HOME"), "=")
		return "\n\n\n\n\n\n\n\n\nCreate file name .btop_config in your [red]" + home[0] + "[white] and place email adress use by your commits"
	}

	path := scan.ScanUniqueFolderGit(os.Getenv("PWD"), emailFlag)
	if path[0] == "" {
		return "\n\n\n\n\nYou are not in git Repository, or we don't find commit from " + emailFlag
	}
	path[0] = clearPath(path[0])
	return ui.CreateTableUI(path, emailFlag)
}
