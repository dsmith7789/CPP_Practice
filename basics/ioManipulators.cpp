#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

int main() {
    cout << 1.0 << endl;
    cout << showpoint << 1.0 << endl;   // showpoint is enabled until we turn it off
    cout << showpos << 1.0 << endl;     // showpos is enabled until we turn it off
    cout << hex << 12345 << " " << 4567 << endl;
    cout << noshowpos;  // turns the showpos manipulator off
    cout << showbase << hex << 12345 << " " << 4567 << endl;
    cout << showbase << hex << 12345 << " " << dec << 4567 << endl;
    cout << showbase << hex << 0x12345 << " " << dec << 0x4567 << endl;
    cout << fixed << 1234.56789 << endl;
    cout << scientific << 1234.56789 << endl;
    cout << setprecision(2) << 1234.56789 << endl;

    cout << "******" << setw(8) << "" << "...." << endl;
    return 0;
}