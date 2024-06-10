#include "Movie.h"
#include<iostream>

Movie::Movie(string name, string rating, int watch_counter)
    : name{ name }, rating{ rating }, watch_counter{ watch_counter } {
}

string Movie::get_name() {
    return this->name;
}

string Movie::get_rating() {
    return this->rating;
}

int Movie::get_watch_counter() {
    return this->watch_counter;
}

void Movie::increment_watch_counter() {
    this->watch_counter++;
}