package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("Coversion in Go")

	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Enter your name: ")

	input, _ := reader.ReadString('\n')

	fmt.Println("Hemlo, ", input)

	fmt.Println("Enter your age: ")

	age, _ := reader.ReadString('\n')

	conv, err := strconv.ParseFloat(strings.TrimSpace(age), 64)

	if err != nil {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println("Your age: ", conv+1)
	}

}
