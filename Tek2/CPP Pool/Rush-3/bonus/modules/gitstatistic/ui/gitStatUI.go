package ui

import (
	"fmt"
	"sort"
	"time"

	"github.com/ClementBolin/topGo/modules/gitstatistic/git"
)

const (
	daySixMonths = 183
	weekSixMonths = 26
)

type column []int

func createTable(arrayPath []string, email string) map[int]int {
	commitsTable := make(map[int]int, daySixMonths)
	var etat bool = false

	for i := daySixMonths; i > 0; i-- {
		commitsTable[i] = 0
	}
	for _, e := range arrayPath {
		git.CountCommit(e, commitsTable, email, &etat)
	}
	return commitsTable
}

// print commits in last 6months
func printCommitsStat(commits map[int]int) string {
	key := sortMapIntoSlice(commits)
	cols := buildCol(key, commits)
	str := printCells(cols)
	return str
}

func buildCol(keys []int, commits map[int]int) map[int]column {
	cols := make(map[int]column)
	col := column{}

	for _, k := range keys {
		week := int(k / 7) //26,25...1
		dayinweek := k % 7 // 0,1,2,3,4,5,6

		if dayinweek == 0 { //reset
			col = column{}
		}

		col = append(col, commits[k])

		if dayinweek == 6 {
			cols[week] = col
		}
	}

	return cols
}

func sortMapIntoSlice(m map[int]int) []int {
	var key []int

	for k := range m {
		key = append(key, k)
	}
	sort.Ints(key)
	return key
}

// Display UI

// printCells prints the cells of the graph
func printCells(cols map[int]column) string {
	var str string = "\n\n\n\n\n"
	str = fmt.Sprintf("%s%s", str, printMonths())
	for j := 6; j >= 0; j-- {
		for i := weekSixMonths + 1; i >= 0; i-- {
			if i == weekSixMonths+1 {
				str = fmt.Sprintf("%s%s", str, printDayCol(j))
			}
			if col, ok := cols[i]; ok {
				//special case today
				if i == 0 && j == git.CalcOffset()-1 {
					if j >= 6 {
						j--
					}
					str = fmt.Sprintf("%s%s", str, printCell(col[j], true))
					continue
				} else {
					if len(col) > j {
						str = fmt.Sprintf("%s%s", str, printCell(col[j], false))
						continue
					}
				}
			}
			str = fmt.Sprintf("%s%s", str, printCell(0, false))
		}
		str = fmt.Sprintf("%s\n", str)
	}
	return str
}

// printMonths prints the month names in the first line, determining when the month
// changed between switching weeks
func printMonths() string {
	week := git.GetActualDate(time.Now()).Add(-(daySixMonths * time.Hour * 24))
	month := week.Month()
	str := fmt.Sprintf("         ")
	for {
		if week.Month() != month {
			str = fmt.Sprintf("%s%s ", str, week.Month().String()[:3])
			month = week.Month()
		} else {
			str = fmt.Sprintf("%s    ", str)
		}

		week = week.Add(7 * time.Hour * 24)
		if week.After(time.Now()) {
			break
		}
	}
	str = fmt.Sprintf("%s\n", str)
	return str
}

// printDayCol given the day number (0 is Sunday) prints the day name,
// alternating the rows (prints just 2,4,6)
func printDayCol(day int) string {
	out := "     "
	switch day {
	case 1:
		out = " Mon "
	case 3:
		out = " Wed "
	case 5:
		out = " Fri "
	}
	return out
}

func printCell(val int, today bool) string {
	var strReturn string
	escape := "[white]" // \033[0;37;30m
	switch {
	case val > 0 && val < 5:
		escape = "[#ABD595]" // \033[1;30;47m
	case val >= 5 && val < 10:
		escape = "[#548E2F]" // \033[1;30;43m
	case val >= 10:
		escape = "[#2C7404]" // \033[1;30;42m
	}

	if today {
		escape = "[#AE07F1]" // \033[1;37;45m
	}

	if val == 0 {
		strReturn = fmt.Sprintf(strReturn+escape + "  - " + "[white]") // \033[0m
		return strReturn
	}

	str := "  %d "
	switch {
	case val >= 10:
		str = " %d "
	case val >= 100:
		str = "%d "
	}

	strReturn = fmt.Sprintf(strReturn+escape+str+"[white]", val) // \033[0m"
	return strReturn
}

func createIndex(str *string) {
	*str = fmt.Sprintf("%s\n\n[#AE07F1]actual day[white]\t[#ABD595]less 5 commits[white]\t[#548E2F]more 5 commits[white]\t[#2C7404]more 10 commits[white]", *str)
}

// CreateTableUI : display commit in your terminal
func CreateTableUI(arrayPath []string, email string) string {
	commits := createTable(arrayPath, email)
	str := printCommitsStat(commits)
	createIndex(&str)
	return str
}