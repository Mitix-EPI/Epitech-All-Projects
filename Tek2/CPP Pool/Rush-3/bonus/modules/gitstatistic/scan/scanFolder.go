package scan

import (
	"io/ioutil"
)

// ScanUniqueFolderGit : Scan folder not recursive
func ScanUniqueFolderGit(path string, email string) []string {
	// Read File
	file, err := ioutil.ReadDir(path)
	if err != nil {
		var mess []string
		mess = make([]string, 1)
		mess[0] = ""
		return mess
	}

	// String path
	pathReturn := make([]string, 1)

	for _, f := range file {
		if (f.Name() == ".git") {
			pathReturn[0] = path + "/" + f.Name()
		}
	}
	return pathReturn
}
