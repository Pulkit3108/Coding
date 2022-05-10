package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

func main() {
	fmt.Println("Files in Go")

	reader := bufio.NewReader(os.Stdin)
	// fmt.Print("Enter file name: ")
	// filename, nerr := reader.ReadString('\n')
	// checkNilError(nerr)
	fmt.Print("Enter file content: ")
	content, cerr := reader.ReadString('\n')
	checkNilError(cerr)

	file, ferr := os.Create("hello.txt")
	checkNilError(ferr)
	length, ierr := io.WriteString(file, content)
	checkNilError(ierr)
	fmt.Println("Length of content:", length)
	defer file.Close()

	readFile("hello.txt")
}

func readFile(filepath string) {
	databyte, berr := ioutil.ReadFile(filepath)
	checkNilError(berr)
	fmt.Println("Raw data in file:", databyte)
	fmt.Println("Data in file:", string(databyte))
}

func checkNilError(err error) {
	if err != nil {
		panic(err)
	}
}
