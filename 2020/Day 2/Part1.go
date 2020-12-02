package main

import (
	"io/ioutil"
	"fmt"
	"strings"
	"regexp"
	"strconv"
)

func letterFreqCounter(password string) (map[string]int) {
	freqCounter := make(map[string]int)
	for _, letter := range password {
		letter := string(letter)
		_, ok := freqCounter[letter]
		if !ok {
			freqCounter[letter] = 0
		}
		freqCounter[letter]++
	}
	return freqCounter
}

func main() {
	data, err := ioutil.ReadFile(`input.txt`)

	if err != nil {
		panic(err)
	}
	lines := strings.Split(string(data), "\n")
	counter := 0
	re := regexp.MustCompile(`(?P<min>\d+)-(?P<max>\d+) (?P<letter>\w): (?P<password>\w+)`)
	for _, line := range lines {
		lineParams := re.FindStringSubmatch(line)
		freqCounter := letterFreqCounter(lineParams[4])
		min, _ := strconv.Atoi(lineParams[1])
		max, _ := strconv.Atoi(lineParams[2])
		if freqCounter[lineParams[3]] >= min && freqCounter[lineParams[3]] <= max {
			counter++
		} else {
		}
	}
	fmt.Println(counter)
}
