// These are Include Guards to guarantee the file will only be included once
#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <string>
#include <vector>

using namespace std;

class Movies {
private:
    /** Vector of pointers to Movies */
    vector<Movie> movieCollection{};

    /**
     * Finds the a movie in the collection by its name.
     * @param name The name of the movie to find.
     * @return The movie if in the collection, or null.
     */
    Movie* get_movie_by_name(const string* const name);

public:
    /**
     * Adds a movie to the collection.
     * @param name The name of the movie.
     * @param rating The rating of the movie.
     * @param watch_counter The number of times the movie has been w
     */
    void add_movie(const string* name, const string* rating, int watch_counter);

    /**
     * Increments the watch counter for a movie in the collection.
     * @param name The name of the movie.
     */
    void increment_watch_count(const string* const movieName);

    /**
     * Prints the whole movie collection.
     */
    void display_all_movies();
};

#endif