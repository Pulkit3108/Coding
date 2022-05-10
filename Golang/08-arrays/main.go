package main

import "fmt"

func main() {

	fmt.Println("Arrays in Go")

	var fruitList [4]string
	fruitList[0] = "Apple"
	fruitList[1] = "Orange"
	fruitList[2] = "Banana"
	fruitList[3] = "Mango"

	fmt.Println("The fruitList is", fruitList)
	fmt.Println("The fruitList length is", len(fruitList))

	var vegetableList = [4]string{"Carrot", "Potato", "Onion", "Cucumber"}

	fmt.Printf("The Type of VegetableList is %T\n", vegetableList)
	fmt.Println("The vegetableList is", vegetableList)
	fmt.Println("The vegetableList length is", len(vegetableList))

}
