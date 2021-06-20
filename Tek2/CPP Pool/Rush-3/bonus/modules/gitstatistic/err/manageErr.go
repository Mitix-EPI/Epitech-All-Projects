package err

import (
	"log"
	"fmt"
)

// MangeErrExit : Check error and display error and kill program
func MangeErrExit(err error) {
	if (err != nil) {
		log.Fatal(err)
	}
}

// MangeErr : Check error and displauy error
func MangeErr(err error) {
	if (err != nil) {
		fmt.Println(err)
	}
}
