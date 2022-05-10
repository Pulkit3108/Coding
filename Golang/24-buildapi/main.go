package main

import (
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"strconv"
	"time"

	"github.com/gorilla/mux"
)

// Model For Course: File
type Course struct {
	CourseID   string  `json:"courseID"`
	CourseName string  `json:"courseName"`
	CourseFee  int     `json:"courseFee"`
	Author     *Author `json:"author"`
}

type Author struct {
	FullName string `json:"fullName"`
	Email    string `json:"email"`
	Website  string `json:"website"`
}

// Database
var courses []Course

// Middleware, Helper: File
func (c *Course) IsEmpty() bool {
	return c.CourseName == "" && c.CourseFee == 0 && c.Author == nil
}

func main() {
	fmt.Println("APIs in Golang")
	r := mux.NewRouter()
	// Seeding Database
	courses = append(courses, Course{CourseID: "1", CourseName: "Go", CourseFee: 1000, Author: &Author{FullName: "John Doe", Email: "doejohn@gmail.com ", Website: "www.doejohn.com"}})
	courses = append(courses, Course{CourseID: "2", CourseName: "Python", CourseFee: 2000, Author: &Author{FullName: "Jane Doe", Email: "doejane@gmail.com ", Website: "www.doejane.com"}})
	courses = append(courses, Course{CourseID: "3", CourseName: "ReactJS", CourseFee: 2000, Author: &Author{FullName: "Hunter", Email: "admin123@gmail.com ", Website: "www.admin123.com"}})
	// Handle Routers
	r.HandleFunc("/", serveHome).Methods("GET")
	r.HandleFunc("/courses", getAllCourses).Methods("GET")
	r.HandleFunc("/course/{id}", getOneCourse).Methods("GET")
	r.HandleFunc("/course", createCourse).Methods("POST")
	r.HandleFunc("/course/{id}", updateCourse).Methods("PUT")
	r.HandleFunc("/course/{id}", deleteCourse).Methods("DELETE")
	r.HandleFunc("/course/delete", deleteAllCourses).Methods("DELETE")
	// Listen on port 8000
	log.Fatal(http.ListenAndServe(":8000", r))

}

// Controller: File
// Serve Home Route
func serveHome(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1>Welcome to the Home Page!</h1>"))
}

func getAllCourses(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: getAllCourses")
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(courses)
}

func getOneCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: getOneCourse")
	w.Header().Set("Content-Type", "application/json")
	// Grab ID from Request
	params := mux.Vars(r)
	// Loop over Courses and find one with the ID
	for _, item := range courses {
		if item.CourseID == params["id"] {
			json.NewEncoder(w).Encode(item)
			return
		}
	}
	json.NewEncoder(w).Encode("Course not found")
	return
}

// Create Course
func createCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: createCourse")
	w.Header().Set("Content-Type", "application/json")

	// Body is Empty
	if r.Body == nil {
		json.NewEncoder(w).Encode("Please send a request body")
		return
	}
	var course Course
	// Decode JSON
	err := json.NewDecoder(r.Body).Decode(&course)
	checkNilError(err)
	// Check if Empty
	if course.IsEmpty() {
		json.NewEncoder(w).Encode("No course data found")
		return
	}
	// Check if Course already exists
	for _, item := range courses {
		if item.CourseName == course.CourseName {
			json.NewEncoder(w).Encode("Course already exists")
			return
		}
	}
	// Generate Unique ID
	rand.Seed(time.Now().UnixNano())
	course.CourseID = strconv.Itoa(rand.Intn(100000))
	// Add to Database
	courses = append(courses, course)
	json.NewEncoder(w).Encode(course)
	return

}

// Update Course
func updateCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: updateCourse")
	w.Header().Set("Content-Type", "application/json")
	// Grab ID from Request
	params := mux.Vars(r)
	// Loop over Courses and find one with the ID
	for index, item := range courses {
		if item.CourseID == params["id"] {
			// Update
			courses = append(courses[:index], courses[index+1:]...)
			var course Course
			err := json.NewDecoder(r.Body).Decode(&course)
			checkNilError(err)
			course.CourseID = params["id"]
			courses = append(courses, course)
			json.NewEncoder(w).Encode(course)
			return
		}
	}
	json.NewEncoder(w).Encode("Course not found")
	return
}

// Delete Course
func deleteCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: deleteCourse")
	w.Header().Set("Content-Type", "application/json")
	// Grab ID from Request
	params := mux.Vars(r)
	// Loop over Courses and find one with the ID
	for index, item := range courses {
		if item.CourseID == params["id"] {
			// Delete
			courses = append(courses[:index], courses[index+1:]...)
			json.NewEncoder(w).Encode(courses)
			return
		}
	}
	json.NewEncoder(w).Encode("Course not found")
	return
}

// Delete All Courses
func deleteAllCourses(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: deleteAllCourses")
	w.Header().Set("Content-Type", "application/json")
	courses = nil
	json.NewEncoder(w).Encode(courses)
	return
}

func checkNilError(err error) {
	if err != nil {
		panic(err)
	}
}
