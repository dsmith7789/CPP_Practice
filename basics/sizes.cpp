#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Function Prototypes: needed for compilation because functions are defined after being used
void typeProperties();
void typeSizes();
void integerLiterals();
void typeCasting();
void enumDemo();
int toInches(const int feet, const int inches=0); // types are required, parameter names are optional

int main() {
    typeSizes();
    typeProperties();
    integerLiterals();
    typeCasting();
    enumDemo();
    int myInches = toInches(6, 3);
    cout << "I am " << myInches << " inches tall!" << endl;
    int yourInches = toInches(6);
    cout << "You are " << yourInches << " inches tall!" << endl;
    return 0;
}

void typeSizes() {
    cout << "\nTYPE SIZES" << endl;
    cout << "Size of a bool: " << sizeof(bool) << " bytes" << endl;
    cout << "Size of a char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of an int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of a short int: " << sizeof(short int) << " bytes" << endl;
    cout << "Size of a long int: " << sizeof(long int) << " bytes" << endl;
    cout << "Size of size_t: " << sizeof(size_t) << " bytes" << endl;
    cout << "Size of signed long int: " << sizeof(signed long int) << " bytes" << endl;
    cout << "Size of unsigned long int: " << sizeof(unsigned long int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of wchar_t: " << sizeof(double) << " bytes" << endl; 
}

void typeProperties() {
    cout << "\nTYPE PROPERTIES" << endl;

    // typedef lets us assign a new name for a type
    string type = "short int";
    typedef short int T;

    std::cout << std::boolalpha; // print true/false instead of 1/0

    // use generic type and numeric_limits template to make print more re-usable
    cout << "Minimum value for " << type << " " << numeric_limits<T>::min() << endl;
    cout << "Maximum value for " << type << " " << numeric_limits<T>::max() << endl;
    cout << type << " is signed: " << numeric_limits<T>::is_signed << endl;
    cout << "Non-sign bits in " << type << ": " << numeric_limits<T>::digits << endl;
    cout << type << " has infinity: " << numeric_limits<T>::has_infinity << endl;
}

void integerLiterals() {
    int v1 = 20;
    int v2 = 024;   // octal
    int v3 = 0x82;  // hex
    long v4 = 20L;
    unsigned long v5 = 42UL;
    long long v6 = 12334567890123LL;
    short v7 = 4;

    cout << "\nInitialization" << endl;
    // no size checking
    int x1 = 0;
    int x2(0);  // "function style" initialization (x2 = 0);
    //int x3 = 123456789012345678901234567890;    // overflows the size of int --> warning when compile

    // with size checking; {} = "list initialization"
    int x4 = {0};
    int x5{0};  // "function style" works here too
    //int x6 = {123456789012345678901234567890};   // compiler won't let us do this --> error when compling

    // Data Loss when converting between data types
    cout << "DATA LOSS" << endl;
    cout << "long long: v6 = " << v6 << endl;
    v7 = v6;
    cout << "short: v7 = " << v7 << endl;
}

void typeCasting() {
    cout << "\nAutomatic Type Casting" << endl;
    
    int w1 = 25, w2 = 10;

    bool b = 42;            cout << setw(w1) << left << "bool b = 42;" << setw(w2) << ":: b = " << b << endl;
    int d = 3.14;           cout << setw(w1) << left << "int d = 3.14;" << setw(w2) << ":: d = " << d << endl;
    double p = d;           cout << setw(w1) << left << "double p = d;" << setw(w2) << ":: p = " << p << endl;
    int x1 = -1;            cout << setw(w1) << left << "int x1 = -1;" << setw(w2) << ":: x1 = " << x1 << endl;
    unsigned x2 = x1;       cout << setw(w1) << left << "unsigned int x2 = x1;" << setw(w2) << ":: x2 = " << x2 << endl;

    cout << "\nInteger Division" << endl;
    cout << "23 / 4 = " << 23 / 4 << endl;
    cout << "-23 / 4 = " << -23 / 4 << endl;
    cout << "23 % 4 = " << 23 / 4 << endl;
    cout << "-23 % 4 = " << -23 / 4 << endl;
    cout << "a == (a / b) * b + a % b" << endl; 

    cout << "\n Explicit Type Casting" << endl;
    int s1 = -1;
    unsigned ui1 = (unsigned) s1;
    unsigned ui2 = unsigned(s1);    // "function style"; the preferred way
    unsigned ui3 = static_cast<unsigned int>(s1);    // more explicit version of "function style", easy to search for; "static" happens at compile
}

void enumDemo() {
    // integer data type with named constants; these are the only types a color can take
    // this also creates the custom data type "color"
    enum color {RED, ORANGE, YELLOW};

    // creates consts like below (although we can't redeclare the enum constants; would give compiler error)
    // const int RED = 0;
    // const int ORANGE = 1;
    // const int YELLOW = 2;

    color myColor = RED;
    cout << "myColor = " << myColor << endl;    // RED = 0 so 0 will print

    enum transportation {CAR, PLANE=13, BOAT=3, BIKE};   // constants can take custom number assignments
    transportation t1 = CAR, t2 = PLANE, t3 = BOAT, t4 = BIKE;
    cout << "t1 = CAR       ::" << t1 << endl;
    cout << "t2 = PLANE(13) ::" << t2 << endl;
    cout << "t3 = BOAT(3)   ::" << t3 << endl;
    cout << "t4 = BIKE      ::" << t4 << endl; 

    for (int i = 0; i < 14; i++) {
        cout << "i = " << i << "; ";
        switch (i) {
            case CAR: {
                cout << "You have selected CAR" << endl;
                break;
            }
            case PLANE: {
                cout << "You have selected PLANE" << endl;
            }
            case BOAT: {
                cout << "No break after plane (bug)" << endl;
                cout << "You have selected PLANE or BOAT (bug)" << endl;
            }
            default: {
                cout << "You have not selected CAR, PLANE, or BOAT" << endl;
            }
        }
    }
}

/**
 * @brief converts given number of feet and inches to just inches
 * 
 * @param feet 
 * @param inches 
 * @return int
 */
int toInches(const int feet, const int inches) {
    cout << "Converting " << feet << " feet " << inches << " inches to inches" << endl;
    return feet * 12 + inches;
}