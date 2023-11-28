#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <vector>
#include "movies.h"

using namespace std;

// classes
class Movie {
    public:
        // constructor
        Movie(string title, string director, string productionCompany, int releaseYear, int lengthMinutes) {
            this->title = title;
            this->director = director;
            this->productionCompany = productionCompany;
            this->releaseYear = releaseYear;
            this->lengthMinutes = lengthMinutes;
        }

        // getters
        string getTitle() const {return this->title;}
        string getDirector() const {return this->director;}
        string getProductionCompany() const {return this->productionCompany;}
        int getReleaseYear() const {return this->releaseYear;}
        int getLengthMinutes() const {return this->lengthMinutes;}

        // setters
        void setTitle(string title) {this->title = title;}
        void setDirector(string director) {this->director = director;}
        void setProductionCompany(string productionCompany) {this->productionCompany = productionCompany;}
        void setReleaseYear(int releaseYear) {this->releaseYear = releaseYear;}
        void setTitle(int lengthMinutes) {this->lengthMinutes = lengthMinutes;}

        // methods
        void printMovie() {
            cout << "Movie: [title=" << this->title
            << ", director=" << this->director
            << ", productionCompany=" << this->productionCompany
            << ", releaseYear=" << this->releaseYear
            << ", lengthMinutes=" << this->lengthMinutes
            << "]" << endl;
        }

        bool longMovie() {
            if (this->lengthMinutes >= 120) { return true; } 
            else { return false; }
        }
        
    private:
        // members
        string title;
        string director;
        string productionCompany;
        int releaseYear;
        int lengthMinutes;
};