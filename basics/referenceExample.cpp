#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// function prototypes
void modifyReference(int& x);
void modifyCopy(int x);


int main() {
    int value = 50;
    modifyCopy(value);
    cout << "value after modifyCopy: " << value << endl;    // value = 50
    modifyReference(value);
    cout << "value after modifyReference: " << value << endl;   // value = 65

    return 0;
}


/**
 * @brief References are useful for:
 * 1. Passing arguments into functions
 * 2. Conserve memory when calling functions (avoid copying)
 * 3. Returning multiple values from functions (return + modify the arguments within the function)
 * 4. Function overloading (different versions of a function depending on the reference type)
 * 5. Aliasing and simplifying syntax
 * 
 * @param x value we are changing
 */
void modifyReference(int& x) {
    x = x + 15;
}

void modifyCopy(int x) {
    x = x + 15;
}