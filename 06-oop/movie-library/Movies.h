// These are Include Guards to guarantee the file will only be included once
#ifndef _MOVIES_H_
#define _MOVIES_H_

#include<string>
#include"Movie.h"
#include<vector>

using namespace std;

class Movies {
private:
    vector<Movie> movieCollection{};
    Movie* get_movie_by_name(const string* const name);
public:
    void add_movie(const string* name, const string* rating, int timeswatched);
    void increment_watch_times(string movieName);
    void display_all_movies();
};

#endif