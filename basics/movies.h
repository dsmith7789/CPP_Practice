#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <vector>

using namespace std;

// classes
class Movie {
    public:
        // constructor
        Movie(string title, string director, string productionCompany, int releaseYear, int lengthMinutes);
        // getters
        string getTitle() const;
        string getDirector() const;
        string getProductionCompany() const;
        int getReleaseYear() const;
        int getLengthMinutes() const;

        // setters
        void setTitle(string title);
        void setDirector(string director);
        void setProductionCompany(string productionCompany);
        void setReleaseYear(int releaseYear);
        void setTitle(int lengthMinutes);

        // methods
        void printMovie();

        bool longMovie();
        
    private:
        // members
        string title;
        string director;
        string productionCompany;
        int releaseYear;
        int lengthMinutes;
};
