package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/gorilla/mux"
)

func main() {
	fmt.Println("Go Mod")
	greeter()
	r := mux.NewRouter()
	r.HandleFunc("/", serveHome).Methods("GET")
	log.Fatal(http.ListenAndServe(":8080", r))

}

func greeter() {
	fmt.Println("Welcome to Go Mod")
}

func serveHome(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Serving Home")
	w.Write([]byte("<h1> Welcome to Go Mod </h1>"))

}
