// These are Include Guards to guarantee the file will only be included once
#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<string>

using namespace std;

class Movie {
private:
    // Movie name
    string name;
    // Movie rating
    string rating;
    // Times watched the movie
    int watch_counter;
public:
    Movie(string name, string rating, int watch_counter);
    string get_name();
    string get_rating();
    int get_watch_counter();
    void increment_watch_counter();
};

#endif