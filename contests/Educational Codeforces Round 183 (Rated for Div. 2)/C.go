package main

import (
	"fmt"
)

func solve() {
	var n int
	var s string
	fmt.Scan(&n, &s)

	cntA, cntB := 0, 0
	for _, x := range s {
		if x == 'a' {
			cntA++
		} else {
			cntB++
		}
	}

	diff := cntA - cntB
	if diff == 0 {
		fmt.Println("0")
		return
	}

	mp := make(map[int]int)
	mp[0] = 0

	balance := 0
	ans := n

	for i := 1; i <= n; i++ {
		if s[i-1] == 'a' {
			balance++
		} else {
			balance--
		}

		aim := balance - diff
		if val, ok := mp[aim]; ok {
			tmp := i - val
			if tmp < ans {
				ans = tmp
			}
		}

		mp[balance] = i
	}

	if ans >= n {
		fmt.Println("-1")
	} else {
		fmt.Println(ans)
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}
}