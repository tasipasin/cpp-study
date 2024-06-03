#include "Movies.h"
#include <iostream>

Movie* Movies::get_movie_by_name(const string* const name) {
    for (auto& movie : movieCollection) {
        // If the strings are equals, returns 0
        if (movie.get_name().compare(*name) == 0) {
            // At first movie with same name, return true
            return &movie;
        }
    }
    return nullptr;
}

void Movies::add_movie(const string* name, const string* rating, int timeswatched) {
    if (nullptr == this->get_movie_by_name(name)) {
        this->movieCollection.push_back(Movie(*name, *rating, timeswatched));
        cout << *name << " added" << endl;
    }
}

void Movies::increment_watch_times(string movieName) {
    Movie* movie = this->get_movie_by_name(&movieName);
    if (movie != nullptr) {
        movie->increment_watch_counter();
    }
    else {
        cout << movieName << " not in collection" << endl;
    }
}

void Movies::display_all_movies() {
    cout << "====================================" << endl;
    for (auto& movie : movieCollection) {
        cout << movie.get_name() << ", " << movie.get_rating() << ", " << movie.get_watch_counter() << endl;
    }
    cout << "====================================" << endl;

}