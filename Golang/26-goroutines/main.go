package main

import (
	"fmt"
	"net/http"
	"sync"
	"time"
)

var signals = []string{
	"test",
}

var wg sync.WaitGroup // pointer
var mut sync.Mutex    // pointer

func main() {
	fmt.Println("Go routines")
	go greeter("Hello")
	greeter("Hi")
	websiteList := []string{"https://www.google.com", "https://www.facebook.com", "https://www.youtube.com"}
	for _, website := range websiteList {
		go getStatusCode(website)
		wg.Add(1)
	}
	wg.Wait()
	fmt.Println("All websites are checked")
	fmt.Println("Signals:", signals)
}

func greeter(s string) {
	for i := 0; i < 3; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func getStatusCode(endpoint string) {
	defer wg.Done()
	res, err := http.Get(endpoint)
	if err != nil {
		panic(err)
	}
	fmt.Println("Status code of ", endpoint, "is", res.StatusCode)
	mut.Lock()
	signals = append(signals, endpoint)
	mut.Unlock()
	defer res.Body.Close()
}
