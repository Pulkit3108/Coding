package controller

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	model "mongoapi/models"
	"net/http"

	"github.com/gorilla/mux"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

const connectionString = "mongodb+srv://test:test@cluster0.pzq4z.mongodb.net/myFirstDatabase?retryWrites=true&w=majority"
const dbName = "Netflix"
const collectionName = "watchlist"

var collection *mongo.Collection

// Connect
func init() {
	// Set client options
	clientOptions := options.Client().ApplyURI(connectionString)
	// Connect to MongoDB
	client, err := mongo.Connect(context.TODO(), clientOptions)
	if err != nil {
		log.Fatal(err)
	}
	err = client.Ping(context.TODO(), nil)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Connected to MongoDB!")
	collection = client.Database(dbName).Collection(collectionName)
	fmt.Println("Collection instance created!")
}

// MongoDB helpers - file

// Insert one record
func insertOneMovie(movie model.Netflix) {
	// Insert One
	insertResult, err := collection.InsertOne(context.Background(), movie)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Inserted a Single Record ", insertResult.InsertedID)
}

// Update an existing record
func updateOneMovie(movieId string) {
	id, err := primitive.ObjectIDFromHex(movieId)
	if err != nil {
		log.Fatal(err)
	}
	filter := bson.M{"_id": id}
	update := bson.M{"$set": bson.M{"watched": true}}
	updateResult, err := collection.UpdateOne(context.Background(), filter, update)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Matched %v documents and updated %v documents.\n", updateResult.MatchedCount, updateResult.ModifiedCount)
}

// Delete an existing record
func deleteOneMovie(movieId string) {
	id, err := primitive.ObjectIDFromHex(movieId)
	if err != nil {
		log.Fatal(err)
	}
	filter := bson.M{"_id": id}
	deleteResult, err := collection.DeleteOne(context.Background(), filter)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Deleted %v documents in the trainers collection\n", deleteResult)
}

// Delete all records
func deleteAllMovies() {
	deleteResult, err := collection.DeleteMany(context.Background(), bson.D{{}})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Deleted %v documents in the trainers collection\n", deleteResult.DeletedCount)
}

// Get All Movies
func getAllMovies() []primitive.M {
	cursor, err := collection.Find(context.Background(), bson.D{{}})
	if err != nil {
		log.Fatal(err)
	}
	var movies []primitive.M
	for cursor.Next(context.Background()) {
		var movie primitive.M
		err := cursor.Decode(&movie)
		if err != nil {
			log.Fatal(err)
		}
		movies = append(movies, movie)

	}
	defer cursor.Close(context.Background())
	return movies
}

// MongoDB controllers - file

// Get Movies
func GetMyAllMovies(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: Get All Movies")
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	allMovies := getAllMovies()
	json.NewEncoder(w).Encode(allMovies)

}

// Create Movie
func CreateMovie(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: Create Movie")
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Access-Control-Allow-Methods", "POST")
	var movie model.Netflix
	_ = json.NewDecoder(r.Body).Decode(&movie)
	insertOneMovie(movie)
	json.NewEncoder(w).Encode(movie)
}

// Mark Watched
func MarkAsWatched(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: Mark Movie as Watched")
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Access-Control-Allow-Methods", "PUT")
	params := mux.Vars(r)
	movieId := params["id"]
	updateOneMovie(movieId)
	json.NewEncoder(w).Encode(movieId)
}

// Delete Movie
func DeleteMovie(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: Delete Movie")
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Access-Control-Allow-Methods", "DELETE")
	params := mux.Vars(r)
	movieId := params["id"]
	deleteOneMovie(movieId)
	json.NewEncoder(w).Encode(movieId)
}

// Delete All Movies
func DeleteAllMovies(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Endpoint Hit: Delete All Movies")
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Access-Control-Allow-Methods", "DELETE")
	deleteAllMovies()
	json.NewEncoder(w).Encode(getAllMovies())
}
