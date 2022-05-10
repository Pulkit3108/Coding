package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	fmt.Println("Switch Case in Go")

	rand.Seed(time.Now().UnixNano())
	diceNumber := rand.Intn(6) + 1
	fmt.Println("You rolled a", diceNumber)

	switch diceNumber {
	case 1:
		fmt.Println("You got a one! You can Start!")
	case 2:
		fmt.Println("You got a two! You can move 2 steps forward!")
	case 3:
		fmt.Println("You got a three! You can move 3 steps forward!")
	case 4:
		fmt.Println("You got a four! You can move 4 steps forward!")
	case 5:
		fmt.Println("You got a five! You can move 5 steps forward!")
	case 6:
		fmt.Println("You got a six! You can move 6 steps forward! You can roll again!")
	default:
		fmt.Println("You got a wrong number!")
	}

}
