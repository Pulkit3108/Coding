package main

import "fmt"

func main() {
	fmt.Println("Pointers in Go")
	var a int = 10
	var ptr *int = &a
	fmt.Println("Value of a is", a)
	fmt.Println("Address of a is", ptr)
	fmt.Println("Value at address of a is", *ptr)
	*ptr = 20
	fmt.Println("New Value of a is", a)
}
