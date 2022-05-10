package main

import "fmt"

func main() {
	fmt.Println("Functions in Go")
	fmt.Println("----------------")
	fmt.Println("")
	fmt.Println("Greet function")
	greet()
	result := add(10, 20)
	fmt.Println("Addition of 10 and 20 is", result)
	result, _ = moreadd(10, 20, 30, 40, 50)
	fmt.Println("Addition of 10, 20, 30, 40 and 50 is", result)
}
func greet() {
	fmt.Println("Welcome to Go")
}
func add(x int, y int) int {
	return x + y
}
func moreadd(x ...int) (int, string) {
	var sum int = 0
	for _, v := range x {
		sum += v
	}
	return sum, "test"
}
