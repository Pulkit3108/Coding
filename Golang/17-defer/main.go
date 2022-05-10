package main

import "fmt"

func main() {
	fmt.Println("Defer in Go")
	fmt.Println("start")
	// LIFO
	defer fmt.Println("defer1 in main")
	defer fmt.Println("defer2 in main")
	fmt.Println("end")
	myDefer()

}

func myDefer() {
	for i := 0; i < 5; i++ {
		defer fmt.Println(i)
	}
}
