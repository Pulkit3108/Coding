package main

import "fmt"

func main() {
	fmt.Println("Structs in Go")

	// No inheritance in Go
	// No super or parent class in Go

	user := User{"Hunter", 21, "hunter123@gmail.com", true}
	fmt.Println("User:", user)
	fmt.Printf("User is %+v\n", user)
	fmt.Printf("User Name: %s\n", user.Name)
}

type User struct {
	Name   string
	Age    int
	Email  string
	Status bool
}
