package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

const url = "https://lco.dev"

func main() {
	fmt.Println("Handling Web Requests in Go")

	response, err := http.Get(url)
	checkNilError(err)

	fmt.Printf("Type: %T\n", response)
	fmt.Println("Status:", response.Status)
	fmt.Println("Status Code:", response.StatusCode)
	fmt.Println("Content Length:", response.ContentLength)

	databytes, err := ioutil.ReadAll(response.Body)
	checkNilError(err)
	fmt.Println("Response Body:", string(databytes))

	defer response.Body.Close()
}

func checkNilError(err error) {
	if err != nil {
		panic(err)
	}
}
