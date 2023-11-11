#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

int main() {
    // declare primitives
    int x = 3;
    int y = 5;

    // declare p as a pointer to x
    cout << endl << "** Declare variables **" << endl;
    int* p = &x;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "y = " << y << "; address of y = " << &y << endl;
    cout << "p = " << p << "; address of p = " << &p << endl;

    // modify x
    cout << endl << "** Modify x **" << endl;
    x += 4;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "y = " << y << "; address of y = " << &y << endl;
    cout << "p = " << p << "; address of p = " << &p << endl;

    // modify x through *p
    cout << endl << "** Reassign p to point to y **" << endl;
    *p += 2;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "y = " << y << "; address of y = " << &y << endl;
    cout << "p = " << p << "; address of p = " << &p << endl;

    // reassign p to point to y
    cout << endl << "** Reassign p to point to y **" << endl;
    p = &y;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "y = " << y << "; address of y = " << &y << endl;
    cout << "p = " << p << "; address of p = " << &p << endl;

    // modify *p again
    cout << endl << "** Modify *p **" << endl;
    *p = 6;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "y = " << y << "; address of y = " << &y << endl;
    cout << "p = " << p << "; address of p = " << &p << endl;

    // reference
    cout << endl << "** REFERENCES **" << endl;
    int& r = x;
    cout << "x = " << x << "; address of x = " << &x << endl;
    cout << "r = " << r << "; address of r = " << &r << endl;

    // primitive arrays
    cout << endl << "** Primitive Arrays **" << endl;
    int a[] = {0, 1, 2, 3, 4};
    int* pa = a;

    cout << "a = " << a << "; address of a = " << &a << endl;   // array pointer doesn't get its own address
    cout << "a[0] = " << a[0] << "; address of a[0] = " << &a[0] << endl;
    cout << "a[1] = " << a[1] << "; address of a[1] = " << &a[1] << endl;
    cout << "pa = " << pa << "; address of pa = " << &pa << endl;

    // dynamically allocated arrays
    cout << endl << "** Dynamically Allocated Arrays on the Heap **" << endl;
    int *da = new int[3] {5, 6 ,7}; // dynamically allocated ("new") arrays require pointers
    cout << "da = " << da << "; *da = " << *da << "; address of da = " << &da << endl;
    cout << "da[0] = " << da[0] << "; address of da[0] = " << &da[0] << endl;
    cout << "da[1] = " << da[1] << "; address of da[1] = " << &da[1] << endl;    
    delete []da;    // when deallocating arrays, need to use []

    // character arrays are special
    cout << endl << "** Character Arrays are Special **" << endl;
    char c1[] = {'C', 'S', '3', '6', '8'};  // leaving off the null terminating character causes us to read more than we want
    char c2[] = {'C', 'S', '3', '6', '8', '\0'};    // correct
    char c3[] = "CS368";    // also correct
    // char c4[5] = "CS368";   // error becase "CS368" actually has 6 characters (including the null)
    cout << c1 << endl
        << c2 << endl
        << c3 << endl;


    return 0;
}