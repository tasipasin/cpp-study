// These are Include Guards to guarantee the file will only be included once
#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

using namespace std;

class Movie {
private:
    /** Movie name */
    string name;
    /** Movie rating */
    string rating;
    /** Times watched the movie */
    int watch_counter;

public:
    /**
     * Construct a new Movie object
     * @param name The name of the movie
     * @param rating The rating of the movie
     * @param watch_counter The number of times the movie has been watched
     */
    Movie(string name, string rating, int watch_counter);

    /**
     * Get the name of the movie.
     * @return The name of the movie.
     */
    string get_name();

    /**
     * Get the rating of the movie.
     * @return The rating of the movie.
     */
    string get_rating();

    /**
     * Get the number of times the movie has been watched.
     * @return The number of times the movie has been watched.
     */
    int get_watch_counter();

    /**
     * Increment the watch counter for the movie.
     */
    void increment_watch_counter();
};

#endif