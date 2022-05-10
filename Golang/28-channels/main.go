package main

import (
	"fmt"
	"sync"
)

func main() {
	fmt.Println("Channels and Deadlock in Go")
	myChannel := make(chan int, 3)
	wg := &sync.WaitGroup{}

	wg.Add(2)
	go func(ch <-chan int, wg *sync.WaitGroup) {
		defer wg.Done()
		fmt.Println("Receiving data from channel")
		val, isChannelOpen := <-ch
		if isChannelOpen {
			fmt.Println("Received data from channel: ", val)
		} else {
			fmt.Println("Channel is closed")
		}
	}(myChannel, wg)
	go func(ch chan<- int, wg *sync.WaitGroup) {
		defer wg.Done()
		fmt.Println("Sending data to channel")
		ch <- 1
		ch <- 2
		close(ch)
	}(myChannel, wg)
	wg.Wait()
}
