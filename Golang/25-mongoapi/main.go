package main

import (
	"fmt"
	"log"
	router "mongoapi/routers"
	"net/http"
)

func main() {
	fmt.Println("Mongo API in GO")
	r := router.Router()
	fmt.Println("Server is getting started...")
	log.Fatal(http.ListenAndServe(":8080", r))
	fmt.Println("Listening on port 8080")

}
