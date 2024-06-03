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

int main() {
    Movies collection{};
    string moviename{ "Tasi" };
    string moviert{ "PR" };
    collection.add_movie(&moviename, &moviert, 4);
    collection.increment_watch_times(moviename);
    collection.display_all_movies();
    return 0;
}