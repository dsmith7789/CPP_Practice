#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Function Prototypes: needed because functions are defined after being used
void typeProperties();
void typeSizes();
void integerLiterals();

int main() {
    typeSizes();
    typeProperties();
    integerLiterals();
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
    string type = "unsigned int";
    typedef unsigned int T;

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
    int x1 = 0; // no size checking
    int x2(0);  // "function style" initialization (x2 = 0); no size checking
    int x3 = 123456789012345678901234567890;    // overflows the size of int, no size checking --> error when compile

    cout << x3 << endl;
}