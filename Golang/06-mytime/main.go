package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("Time in Go")

	presentTime := time.Now()

	fmt.Println("The present time is: ", presentTime)
	fmt.Println("The present time is: ", presentTime.Format("01-02-2006 15:04:05 Monday"))

	createdDate := time.Date(2020, time.April, 1, 0, 0, 0, 0, time.UTC)

	fmt.Println("The created date is: ", createdDate)
	fmt.Println("The created date is: ", createdDate.Format("01-02-2006 Monday"))

	// Make Builds
	// In Bash
	// For Windows - GOOS=windows GOARCH=amd64
	// For Linux - GOOS=linux GOARCH=amd64
	// For Mac - GOOS=darwin GOARCH=amd64
	// Build Command - go build <file-name>
	// In Command Prompt
	// $env:GOOS = "linux"
}
