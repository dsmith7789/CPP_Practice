#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {4, 3, 6, 2, 7, 5, 3};
    //vector<int>::iterator beginning = numbers.begin();   // begin() gives a pointer to front element

    // .end() points to the element after the last in the vector
    //auto end = numbers.end();   // auto will figure out that end is type vector<int>::iterator

    // Example: use iterators to loop over the vector and print elements
    for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
        cout << *iter << " ";   // dereference the pointer to get the element
    }
    cout << endl;

    // use iterators to copy parts of vectors
    vector<int> numbers2(numbers.begin(), numbers.end());   // copy whole vector
    vector<int> numbers3(numbers.begin() + 1, numbers.end() - 2);   // copy parts of vector using pointer arithmetic
    for (auto iter = numbers2.begin(); iter < numbers2.end(); iter++) {
        cout << *iter << " ";   // dereference the pointer to get the element
    }
    cout << endl;
    for (auto iter = numbers3.begin(); iter < numbers3.end(); iter++) {
        cout << *iter << " ";   // dereference the pointer to get the element
    }
    cout << endl;

    // sorting using iterators (and algorithms library)
    sort(numbers.begin(), numbers.end());
    cout << "Sorted numbers: ";
    for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
        cout << *iter << " ";   // dereference the pointer to get the element
    }
    cout << endl;

    // insert: vector.insert(position, data)
    cout << "numbers: ";
    for (auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    cout << "numbers2: ";
    for (auto n : numbers2) {
        cout << n << " ";
    }
    cout << endl;

    numbers.insert(numbers.begin() + 2, numbers2.begin(), numbers2.end());
    cout << "numbers: ";
    for (auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}