package main

import (
	"fmt"
)

func solve() {
	var n int64
	fmt.Scan(&n)
	if n%3 == 0 {
		fmt.Println(0)
	} else {
		fmt.Println(3 - n%3)
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}
}