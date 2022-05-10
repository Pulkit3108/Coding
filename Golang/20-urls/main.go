package main

import (
	"fmt"
	"net/url"
)

const myURL string = "https://lco.dev:3000/learn?coursename=reactjs&courseid=1"

func main() {
	fmt.Println("Handling URLs in Go")
	fmt.Println("URL:", myURL)

	// Parsing URL
	result, _ := url.Parse(myURL)
	fmt.Println("Scheme:", result.Scheme)
	fmt.Println("Host:", result.Host)
	fmt.Println("Path:", result.Path)
	fmt.Println("RawQuery:", result.RawQuery)
	fmt.Println("Port:", result.Port())

	qparams := result.Query()
	fmt.Printf("Type of qparams: %T\n", qparams)
	fmt.Println("Query params:", qparams)
	fmt.Println("Query param:", qparams.Get("coursename"))
	fmt.Println("Query param:", qparams["courseid"])

	partsOfURL := &url.URL{
		Scheme:   "https",
		Host:     "lco.dev",
		Path:     "/tutcss",
		RawQuery: "user=hunter",
	}
	fmt.Println("URL:", partsOfURL.String())

}
