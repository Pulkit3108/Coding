package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	fmt.Println("User Input in Go")

	welcome := "Welcome to Go!"
	fmt.Println(welcome)

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter your name: ")

	// comma ok || error ok
	input, _ := reader.ReadString('\n')
	fmt.Println("Hello", input)
	fmt.Printf("Type of input is %T", input)

}
