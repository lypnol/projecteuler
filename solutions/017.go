package main

import (
	"fmt"

	"github.com/divan/num2words"
)

func letters(s string) int {
	var c int
	for _, a := range s {
		if a != ' ' && a != '-' {
			c++
		}
	}
	return c
}

func solve() int {
	var count int
	for i := 1; i <= 1000; i++ {
		count += letters(num2words.ConvertAnd(i))
	}

	return count
}

func main() {
	fmt.Println(solve())
}
