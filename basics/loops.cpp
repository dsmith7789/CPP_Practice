#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

int main() {
    string quote = "I'm blue, if I were green I would die";
    // increment loop
    cout << "Increment Loop" << endl;
    for (int i = 0; i < quote.length(); i++) {
        cout << quote[i] << endl;
    }

    // iterator loop: makes copies of each character
    cout << "Iterator Loop" << endl;
    for (char c : quote) {
        cout << c << endl;
    }

    // use & to affect the original object
    cout << "Changing Variable with Pointer" << endl;
    for (char &c : quote) {
        if (c == 'I') {
            c = 'X';
        }
    }
    cout << quote << endl;

    // "auto" will figure out what type of data quote is
    quote = "I'm blue, if I were green I would die";

    // iterator loop: makes copies of each character
    cout << "Iterator Loop (with auto)" << endl;
    for (auto c : quote) {
        cout << c << endl;
    }

    // use & to affect the original object
    cout << "Changing Variable with Pointer (with auto)" << endl;
    for (auto &c : quote) {
        if (c == 'I') {
            c = 'X';
        }
    }
    cout << quote << endl;

    return 0;
}