package main

import (
	"io/ioutil"
	"fmt"
	"strings"
	"regexp"
	"strconv"
)

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
		letter := lineParams[3]
		left, _ := strconv.Atoi(lineParams[1])
		right, _ := strconv.Atoi(lineParams[2])
		left-- // no concept of index 0
		right--
		password := lineParams[4]
		isLeft := (left >= 0 && left < len(password)) && string(password[left]) == letter
		isRight := (right >= 0 && right < len(password)) && string(password[right]) == letter
		if isLeft != isRight { // xor
			counter++
		}
	}
	fmt.Println(counter)
}
