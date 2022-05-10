package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println("Welcome To Slices in Golang")
	var fruitList = []string{"Apple", "Orange", "Banana"}

	fmt.Printf("The Type of fruitList is %T\n", fruitList)
	fmt.Println("The Length of fruitList is", len(fruitList))

	fruitList = append(fruitList, "Mango")
	fmt.Println("The fruitList is", fruitList)

	fruitList = append(fruitList[2:])
	fmt.Println("New fruitList is", fruitList)

	highScores := make([]int, 4)
	highScores[0] = 10
	highScores[1] = 20
	highScores[2] = 30
	highScores[3] = 40
	highScores = append(highScores, 1, 2, 3, 4, 5, 6, 7, 8, 9)
	fmt.Println("The highScores is", highScores)

	sort.Ints(highScores)
	fmt.Println("The highScores is", highScores)
	fmt.Println(sort.IntsAreSorted(highScores))

	var coursesList = []string{"C++", "Java", "Python", "Go"}
	fmt.Println("The coursesList is", coursesList)
	var index int = 1
	coursesList = append(coursesList[:index], coursesList[index+1:]...)
	fmt.Println("The new coursesList is", coursesList)
}
