package main

import "fmt"

const Token string = "abc123" // public

func main() {
	fmt.Println("Variables in Go :")

	var username string = "Hunter"
	fmt.Println(username)
	fmt.Printf("Variable username is of type : %T \n", username)

	var age int = 32
	fmt.Println(age)
	fmt.Printf("Variable age is of type : %T \n", age)

	var isCool bool = true
	fmt.Println(isCool)
	fmt.Printf("Variable isCool is of type : %T \n", isCool)

	var smallVal uint8 = 255
	fmt.Println(smallVal)
	fmt.Printf("Variable smallVal is of type : %T \n", smallVal)

	var smallFloat float32 = 3.14
	fmt.Println(smallFloat)
	fmt.Printf("Variable smallFloat is of type : %T \n", smallFloat)

	var largeFloat float64 = 3.14159265359
	fmt.Println(largeFloat)
	fmt.Printf("Variable largeFloat is of type : %T \n", largeFloat)

	// Default values

	var defaultVar int
	fmt.Println(defaultVar)
	fmt.Printf("Variable defaultVar is of type : %T \n", defaultVar)

	var defaultVar2 string
	fmt.Println(defaultVar2)
	fmt.Printf("Variable defaultVar2 is of type : %T \n", defaultVar2)

	// Implicit

	var implicitVar = "Implicit"
	fmt.Println(implicitVar)

	// no var keyword

	implicitVar2 := 3000
	fmt.Println(implicitVar2)

	fmt.Println(Token)

}
