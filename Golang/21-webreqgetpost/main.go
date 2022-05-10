package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"net/url"
	"strings"
)

func main() {
	fmt.Println("Web Requests in Go")
	//performGetRequest()
	//performPostRequest()
	performPostFormRequest()
}

func performGetRequest() {
	fmt.Println("Perform GET request")
	const myURL = "http://localhost:8000/get"

	response, err := http.Get(myURL)
	checkNilError(err)
	defer response.Body.Close()
	fmt.Println("Response Status:", response.Status)
	fmt.Println("Content Length:", response.ContentLength)

	content, err := ioutil.ReadAll(response.Body)
	checkNilError(err)
	fmt.Println("Content:", string(content))

	var responseString strings.Builder
	byteCount, err := responseString.Write(content)
	checkNilError(err)
	fmt.Println("Byte Count:", byteCount)
	fmt.Println("Response String:", responseString.String())

}

func performPostRequest() {
	fmt.Println("Perform POST request")
	const myURL = "http://localhost:8000/post"

	// JSON Payload
	jsonPayload := strings.NewReader(`{"Name":"Hunter","Age":21,"Skill":"Golang"}`)
	response, err := http.Post(myURL, "application/json", jsonPayload)
	checkNilError(err)
	defer response.Body.Close()
	fmt.Println("Response Status:", response.Status)
	fmt.Println("Content Length:", response.ContentLength)

	content, err := ioutil.ReadAll(response.Body)
	checkNilError(err)
	fmt.Println("Content:", string(content))

}

func performPostFormRequest() {
	fmt.Println("Perform POST Form request")
	const myURL = "http://localhost:8000/postform"

	// Form Data
	formData := url.Values{}
	formData.Add("Name", "Hunter")
	formData.Add("Age", "21")
	formData.Add("Skill", "Golang")
	response, err := http.PostForm(myURL, formData)
	checkNilError(err)
	defer response.Body.Close()
	fmt.Println("Response Status:", response.Status)
	fmt.Println("Content Length:", response.ContentLength)

	content, err := ioutil.ReadAll(response.Body)
	checkNilError(err)
	fmt.Println("Content:", string(content))

}

func checkNilError(err error) {
	if err != nil {
		panic(err)
	}
}
