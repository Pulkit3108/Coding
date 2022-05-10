package main

import "fmt"

func main() {
	fmt.Println("Maps in Go")

	languages := make(map[string]string)

	languages["Go"] = "Static typed"
	languages["Python"] = "Dynamic typed"
	languages["Java"] = "Static typed"
	languages["C++"] = "Static typed"

	fmt.Println("List of all languages:", languages)
	fmt.Println("Go is a", languages["Go"])
	delete(languages, "Go")
	fmt.Println("List of all languages:", languages)

	for key, value := range languages {
		fmt.Println(key, "is", value)
	}
}
