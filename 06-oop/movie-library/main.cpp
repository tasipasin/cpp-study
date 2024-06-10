/**
 * Maintain the movies watched and how many times.
 *
 * A movie should have a name, a rating (G, PG, PG-13, R) and how many times
 * it has been watched.
 *
 * The collection of Movies should hold the movies watched, increment
 * the movie watch count by it's name and display all watched movies.
 * If a movie is already in the collection (name comparision), should
 * display the error: "%movieName already exists"
 * If count a movie not in the collection, should display the error:
 * "%movieName not in collection"
 * If asks to display all movies in the collection, should display:
 * "Sorry, no movies to display"
 */

#include "Movies.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Execute process to add new Movie.
 */
void add_new_movie();

/**
 * Execute process to increment the watch count of a Movie.
 */
void increment_movie_count();

/** Movie collection. */
Movies movies;

int main() {
    bool exit = false;
    do {
        // Display user options
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter the option: " << endl;
        cout << "1. Add a movie" << endl;
        cout << "2. Increment the watch count" << endl;
        cout << "3. Display all movies" << endl;
        cout << "4. Exit" << endl;
        // Read user options
        int option;
        cin >> option;
        // Execute user option
        switch (option) {
        case 1:
            add_new_movie();
            break;
        case 2:
            increment_movie_count();
            break;
        case 3:
            movies.display_all_movies();
            break;
        case 4:
            exit = true;
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
        cout << endl << endl;
    } while (!exit);
    return 0;
}

void add_new_movie() {
    cout << "Adding a new movie" << endl;
    // Request movie name to user
    string movie_name{};
    cout << "Enter the movie name: " << endl;
    getline(cin, movie_name);
    // Request movie rating to user
    string movie_rating{};
    cout << "Enter the movie rating: " << endl;
    getline(cin, movie_rating);
    // Request movie watch count to user
    int times_watched{};
    cin >> times_watched;
    // Add movie to collection
    movies.add_movie(&movie_name, &movie_rating, times_watched);
}

void increment_movie_count() {
    // Request movie name to user
    string movie_name{};
    cout << "Enter the movie name to increment count: " << endl;
    getline(cin, movie_name);
    // Increment movie count
    movies.increment_watch_count(&movie_name);
}