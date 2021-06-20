package git

import (
	"time"

	git "gopkg.in/src-d/go-git.v4"
	"gopkg.in/src-d/go-git.v4/plumbing/object"
)

const (
	outOfRange = 99999
	daySixMonths = 183
	weekSixMonths = 26
)

// GetActualDate : get actual day
func GetActualDate(t time.Time) time.Time {
	year, month, day := t.Date();
	actualDay := time.Date(year, month, day, 0, 0, 0, 0, t.Location())
	return actualDay
}

// countDaysSinceDate counts how many days passed since the passed `date`
func countDaysSinceDate(date time.Time) int {
	days := 0
	now := GetActualDate(time.Now())
	for date.Before(now) {
		date = date.Add(time.Hour * 24)
		days++
		if days > daySixMonths {
			return outOfRange
		}
	}
	return days
}

// CalcOffset :  calcul offset
func CalcOffset() int {
	var offset int
	weekday := time.Now().Weekday()

	switch weekday {
	case time.Sunday:
		offset = 7
	case time.Monday:
		offset = 6
	case time.Tuesday:
		offset = 5
	case time.Wednesday:
		offset = 4
	case time.Thursday:
		offset = 3
	case time.Friday:
		offset = 2
	case time.Saturday:
		offset = 1
	}

	return offset
}

// CountCommit : return number of Commit that <email> create
func CountCommit(path string, commits map[int]int, email string, etat *bool) map[int]int {
	// instantiate a git repo object from path
	repo, err := git.PlainOpen(path)
	if err != nil {
		panic(err)
	}
	// get the HEAD reference
	ref, err := repo.Head()
	if err != nil {
		panic(err)
	}
	// get the commits history starting from HEAD
	iterator, err := repo.Log(&git.LogOptions{From: ref.Hash()})
	if err != nil {
		panic(err)
	}
	// iterate the commits
	offset := CalcOffset()
	err = iterator.ForEach(func(c *object.Commit) error {
		daysAgo := countDaysSinceDate(c.Author.When) + offset
		if (string(c.Author.Email) == email) {
			if daysAgo != outOfRange {
				commits[daysAgo]++
				*etat = true
			}
		}
		return nil
	})
	if err != nil {
		panic(err)
	}
	return commits
}
