package main

import "fmt"

func main() {
	fmt.Println("Methods in Go")
	fmt.Println("")
	user := User{"Hunter", 21, "hunter123@gmail.com", true}
	fmt.Println(user.GetUserName())
	user.GetStatus()
	fmt.Println(user.GetEmail())

}

type User struct {
	Name   string
	Age    int
	Email  string
	Status bool
}

func (u User) GetUserName() string {
	return u.Name
}

func (u User) GetStatus() {
	if u.Status {
		fmt.Println("User is Online")
	} else {
		fmt.Println("User is Offline")
	}
}

func (u User) GetEmail() string {
	return u.Email
}
