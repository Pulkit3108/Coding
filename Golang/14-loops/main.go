package main

import "fmt"

func main() {
	fmt.Println("Loops in Go")

	days := []string{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}

	fmt.Println("For Loop")
	for i := 0; i < len(days); i++ {
		fmt.Println(days[i])
	}
	fmt.Println("For Loop range based")
	for i := range days {
		fmt.Println(days[i])
	}
	fmt.Println("For Loop range based with index")
	for i, day := range days {
		fmt.Println(i, day)
	}

	rougueValue := 1
	for rougueValue < 10 {
		if rougueValue == 2 {
			rougueValue++
			continue
		}
		if rougueValue == 5 {
			goto lco
		}
		if rougueValue == 8 {
			break
		}

		fmt.Println("Rougue value is", rougueValue)
		rougueValue++
	}
lco:
	fmt.Println("Goto Statement in Golang")

}
