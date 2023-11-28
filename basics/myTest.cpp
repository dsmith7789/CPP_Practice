#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <vector>
#include "movies.h" // custom header file

using namespace std;


// function prototypes
vector<Movie> findParamountMovies(const vector<Movie> &movies);

int main() {
    vector<Movie> movies;
    movies.push_back(Movie("The Godfather", "Francis Ford Copolla", "Paramount", 1972, 175));
    movies.push_back(Movie("Titanic", "James Cameron", "Paramount", 1997, 195));
    movies.push_back(Movie("Goodfellas", "Martin Scorcese", "Warner Bros.", 1990, 146));
    movies.push_back(Movie("Batman Begins", "Christopher Nolan", "Warner Bros.", 2005, 140));
    movies.push_back(Movie("The Hangover", "Todd Phillips", "Warner Bros.", 2009, 100));

    for (auto e : movies) {
        e.printMovie();
        if (e.longMovie()) {
            cout << e.getTitle() << " is a long movie." << endl;
        } else {
            cout << e.getTitle() << " is a short movie." << endl;
        }
    }

    cout << "\nMovies produced by Paramount: " << endl;
    vector<Movie> paramountMovies = findParamountMovies(movies);
    for (auto e : paramountMovies) {
        cout << e.getTitle() << ", ";
    }
    cout << endl;
}

vector<Movie> findParamountMovies(const vector<Movie> &movies) {
    vector<Movie> paramountMovies;
    for (auto &e : movies) {
        if (e.getProductionCompany() == "Paramount") {
            paramountMovies.push_back(e);
        }
    }
    return paramountMovies;
}