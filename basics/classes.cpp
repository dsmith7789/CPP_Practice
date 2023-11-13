#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class PRIVATE_POINT {
    public:
        // default constructor; provided by C++, doesn't do much
        PRIVATE_POINT() {cout << "Default constructor called." << endl;};

        // custom constructor; most readable
        // PRIVATE_POINT(int x, int y=77) {
        //     cout << "Custom constructor called." << endl;
        //     this->x = x;
        //     this->y = y;
        // };

        // copy constructor; preferred for efficiency
        PRIVATE_POINT(int x_in, int y_in = 77)
            : x(x_in), y(y_in)
        {cout << "Copy constructor called." << endl;}

        void printPoint() {
            cout << "Point: (x=" << x << ", y=" << y << ")" << endl;
        }
        // getters - use "const" to tell the compiler that these cannot be used to modify
        int getX() const {
            return this->x;
        }
        int getY() const {
            return this->y;
        }

        // setters
        void setX(int x) {
            this->x = x;
        }
        void setY(int y) {
            this->y = y;
        }
    private:
        int x;
        int y;
        string name;
}; // class: data members begin as private

class POINT {
    public:
        int x;
        int y;
        void printPoint() {
            cout << "Point: (x=" << x << ", y=" << y << ")" << endl;
        }
        // getters
        int getX() {
            return this->x;
        }
        int getY() {
            return this->y;
        }

        // setters
        void setX(int x) {
            this->x = x;
        }
        void setY(int y) {
            this->y = y;
        }
    private:
        string name;
} p2, p3; // class: data members begin as private
// p2 and p3 are instances of the POINT class that are global scope

// struct POINT {};    // struct: data members begin as public

class BOX {
    public:
        POINT minCorner;
        POINT maxCorner;

        // in-line function definitions: faster but don't actually get treated as function calls
        void setCorners(POINT p1, POINT p2) {
            minCorner.x = p1.x;
            minCorner.y = p1.y;
            maxCorner.x = p2.x;
            maxCorner.y = p2.y;
        }

        void printBox() {
            minCorner.printPoint();
            maxCorner.printPoint();
        }

        void printEdgeLengths() {
            pair<int, int> e1 = edgeLengths();
            cout << "Box edge lengths: (" << e1.first << ", " << e1.second << ")" << endl;
        }

        pair<int, int> edgeLengths();

    private:
};

pair<int, int> BOX::edgeLengths() {
    pair<int, int> lengths;
    lengths.first = maxCorner.x - minCorner.x;
    lengths.second = maxCorner.y - minCorner.y;
    return lengths;
}

bool anyZeros(const vector<PRIVATE_POINT>& v);

int main() {
    system("clear");
    POINT p;
    p.x = 3;
    p.y = 6;
    // p.name = "test";    // gives error because this member is private

    // cout << "p.x = " << p.x << ", p.y = " << p.y << endl;    // inconvenient to always do this, so created printPoint method
    p.printPoint();

    p2.x = 1;
    p2.y = 2;
    p2.printPoint();

    cout << endl << "First Box: " << endl;
    BOX b;
    b.minCorner.x = 4;
    b.minCorner.y = 5;
    b.maxCorner.x = 6;
    b.maxCorner.y = 7;
    b.minCorner.printPoint();
    b.maxCorner.printPoint();

    cout << endl << "Second Box: " << endl;
    BOX b2;
    b2.setCorners(p, p2);
    b2.printBox();
    b2.printEdgeLengths();

    p2.setX(10);
    p2.printPoint();

    PRIVATE_POINT pp;
    pp.setX(1);
    pp.setY(2);
    pp.printPoint();

    vector<PRIVATE_POINT> v = {pp, pp, pp};
    cout << "Any points where x=0 in v?: " << boolalpha << anyZeros(v) << endl;;

    system("clear");
    PRIVATE_POINT p4;
    PRIVATE_POINT p5(0, 0);
    PRIVATE_POINT p6(55);
    p4.printPoint();    // undetermined behavior for what's in p4 members without a custom constructor
    p5.printPoint();
    p6.printPoint();

    return 0;
}

/**
 * @brief Checks if there are any points where x is 0 in the vector.
 * 
 * @param v a constant reference to a vector of points (to avoid unnecessary copying of the vector)
 * @return true if there are any points with x=0,
 * @return false otherwise
 */
bool anyZeros(const vector<PRIVATE_POINT>& v) {
    for (auto &e : v) {
        if (e.getX() == 0) {
            return true;
        }
    }
    return false;
}