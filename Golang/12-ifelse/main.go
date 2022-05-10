package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("Welcome to the if-else program")

	var loginCount int = 0
	var result string = ""

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter User loginCount: ")
	input, _ := reader.ReadString('\n')

	loginCount, _ = strconv.Atoi(strings.TrimSpace(input))
	if loginCount < 10 {
		result = "Regular User"
	} else if loginCount < 25 {
		result = "Gold User"
	} else {
		result = "Admin"
	}
	fmt.Println("User Type:", result)

	if num := 3; num > 0 {
		fmt.Println("num is greater than 0")
	} else if num < 0 {
		fmt.Println("num is less than 0")
	} else {
		fmt.Println("num is equal to 0")
	}

	if err := recover(); err != nil {
		fmt.Println("Recovered in f", err)
	}
}
