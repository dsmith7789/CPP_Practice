#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Function Prototypes
void arrays();
void pointers();
void doublePointers();

/**
 * @brief 
 * 
 * @param argc count of arguments
 * @param argv list of arguments
 * @return int 
 */
int main(int argc, char** argv) {
    // arrays();
    // pointers();
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    // references = aliases that give a variable a second name
    // similar to pointers
        // never null
        // can't be changed to "point" to another object
        // no need to dereference
    int x = 1;
    int &y = x; // y refers to the int x

    x = 2;      // both x and y are 2
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    y = 3;      // both x and y are 3
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

void arrays() {
    // arrays
    int data[100];  // int array must be known length at compile time
    char text[] = "array";  // C++ can figure out how much to allocate for a string/char array
    int limits[] = {10, 12, 14, 17, 20};    // C++ doesn't keep track of the length; lets us access outside the array

    cout << "limits[0] = " << limits[0] << endl;
    cout << "limits[-1] = " << limits[-1] << endl;  // out of bounds, prints out garbage
    cout << "limits[10] = " << limits[10] << endl;  // out of bounds, prints out garbage

    double cost[5] = {2.31, 5.35, 3.84};
    for (int i = 0; i < 5; i++) {
        cout << "cost[" << i << "] = " << cost[i] << endl;  // unassigned slots default to 0
    }

    string names[9] = {"Ironman" ,"Thor"};
    names[8] = "Spider-Man";
    for (int i = 0; i < 9; i++) {
        cout << "names[" << i << "] = " << names[i] << endl;    // unassigned slots default to ""
    }

    // no copy or assign arrays directly
    // int limits2[5] = limits;    // can't point one array to another
    int limits2[5];
    // limit2 = limits;    // invalid array assignment 
    cout << boolalpha << "limits2 == limits: " << (limits2 == limits) << endl;   // compares address of the arrays
}

void pointers() {
    // all valid declarations
    int* x1;    // my personal favorite
    int * x2;
    int *x3;    // best if you do multi-line assignment

    // all valid initialization to null
    int* y1 = 0;
    int* y2 = NULL; // my favorite
    int* y3 = nullptr;

    // useful pointers
    int x = 3;
    x1 = &x;
    cout << "x1 = " << x1 << endl;
    cout << "*x1 = " << *x1 << endl;

    int y = 11;
    x1 = &y;
    cout << "x1 = " << x1 << endl;
    cout << "*x1 = " << *x1 << endl;

    // dereference with [] like arrays
    cout << "x1[0] == " << x1[0] << endl;

    // assign pointers to dynamically allocated data with new operators
    string* ps = new string("Hello World!");    // points to an address on the heap
    cout << *ps << endl;
    delete ps;  // need to remember to delete from the heap when no longer needed so it can be reassigned

    // pointers to arrays
    int arr[] = {0, 1, 2, 3, 4, 5}; // arrays are CONSTANT pointers, you can't change where they point
    int* parr = arr;                
    for (int i = 0; i < 6; i++) {
        cout << i << "; arr[i] = " << arr[i] << endl;
        cout << i << "; parr[i] = " << parr[i] << endl;
    }

    // pointer arithmetic
    for (int i = 0; i < 6; i++) {
        cout << i << "; *(arr + " << i << ") = " << *(arr + i) << endl;
        cout << i << "; *(parr + " << i << ") = " << *(parr + i) << endl;
    }    

    // double delete error: common gotcha
    int* a = new int;
    *a = 5;
    int* b;
    b = a;
    delete a;   // marks anything that points to this address as stale
    // delete b;   // so this line will give a double free error
}
