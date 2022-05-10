package main

import (
	"fmt"
	"math/big"

	// "math/rand"
	"crypto/rand"
	// "time"
)

func main() {
	fmt.Println("Welcome To Maths!")

	var mynumberOne int = 10
	var mynumberTwo float64 = 10.5

	fmt.Println("The Sum is : ", mynumberOne+int(mynumberTwo))

	// Random Number
	// rand.Seed(time.Now().UnixNano())
	// fmt.Println("Random Number : ", rand.Intn(100))

	// Random using Crypto
	myRandomNumber, _ := rand.Int(rand.Reader, big.NewInt(100))

	fmt.Println("My Random Number : ", myRandomNumber)
}
