package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name     string   `json:"name"`
	Age      int      `json:"age"`
	Email    string   `json:"email"`
	Password string   `json:"-"`
	Skill    []string `json:"skills,omitempty"`
}

func main() {
	fmt.Println("JSON in Go")
	//encodeJSON()
	decodeJSON()
}

func encodeJSON() {
	team := []Person{
		{"John", 32, "john123@dev.go", "john123", []string{"Golang", "Java"}},
		{"Jane", 30, "jane123@gmail.com", "jane123", nil},
		{"Jack", 28, "jack123@hotmail.com", "jack123", []string{"Javascript", "Java"}},
		{"Jill", 26, "jill56@Hots.com", "jill56", []string{"Python", "Angular"}},
	}

	// Packing the data to JSON
	jsonData, err := json.MarshalIndent(team, "", "\t")
	checkError(err)
	fmt.Println("JSON data: ", string(jsonData))

}

func decodeJSON() {
	jsonData := []byte(`
		{
			"name":"John",
			"age":32,
			"email":"john123@dev.go",
			"skill":["Golang","Java"]
		}
	`)

	var person Person // Declare a variable of type Person
	checkValid := json.Valid(jsonData)
	if checkValid {
		fmt.Println("JSON is Valid..")
		err := json.Unmarshal(jsonData, &person)
		checkError(err)
		fmt.Println("Name: ", person.Name)
		fmt.Printf("JSON data: %#v\n", person)
	} else {
		fmt.Println("JSON is Invalid...")
	}
	var myData map[string]interface{}
	err := json.Unmarshal(jsonData, &myData)
	checkError(err)
	fmt.Printf("JSON data: %#v\n", myData)

	for key, value := range myData {
		fmt.Println(key, ":", value)
	}
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
