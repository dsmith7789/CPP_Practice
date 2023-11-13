#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    // Set construction
    set<int> s1;    // creates an empty set
    set<string> Avengers = {"Thor", "Captain America", "Hulk", "Iron Man", "Black Widow"};

    // insertion - elements are inserted in-order
    Avengers.insert("Spider-Man");
    Avengers.insert("Vision");

    // iterator options for insertion
    vector<string> moreAvengers = {"Wasp", "Ant-Man", "Hawkeye", "Scarlet Witch"};
    Avengers.insert(moreAvengers.begin(), moreAvengers.end());  //  iterators use pointer arithmetic (so moreAvengers.begin() + 1 is valid)

    // Avengers are alphabetized, the set uses a binary search tree to store elements and prints out in-order
    cout << "Avengers: ";
    for (auto element : Avengers) {
        cout << element << ", ";
    }
    cout << endl;

    // iterator options for creation
    set<string> s2(moreAvengers.begin() + 1, moreAvengers.end());
    cout << "s2: ";
    for (auto element : s2) {
        cout << element << ", ";
    }
    cout << endl;

    // copy constructor
    set<string> s3(s2);
    s3.insert("Doctor Strange");

    cout << "s3: ";
    for (auto element : s3) {
        cout << element << ", ";
    }
    cout << endl;

    // Iterator: to the new element inserted
    // Bool: was the element inserted (ex. duplicate will give False)
    pair<set<string>::iterator, bool> success = Avengers.insert("Black Panther");
    cout << *(success.first) << " " << boolalpha << success.second << endl;

    pair<set<string>::iterator, bool> failure = Avengers.insert("Black Panther");
    cout << *(failure.first) << " " << boolalpha << failure.second << endl;

    // finding an element in a set
    // dereference iterator to get the actual value
    set<string>::iterator it1 = Avengers.find("Captain America");   // .find() returns an iterator (basically a pointer that points to elements in the set)
    cout << "Found: " << *(it1) << endl;
    set<string>::iterator it2 = Avengers.find("Spider-Man");
    cout << "Found: " << *(it2) << endl;

    cout << "Finding in a set:" << endl;
    for ( ; it1 != it2; it1++) {
        cout << *(it1) << " ";
    }
    cout << endl;

    // lower bound and upper bound
    cout << "Lower and Upper Bound" << endl;
    // lower_bound(value) -> first item not less than value
    // upper_bound(value) -> first item that is greater than value
    for (auto iter = Avengers.lower_bound("C"); iter != Avengers.upper_bound("S"); iter++) {
        cout << *(iter) << ", ";
    }
    cout << endl;

    // erase: delete elements from a set
    int num_erased1 = Avengers.erase("Captain America");    // returns 1 because Captain America was in the set
    int num_erased2 = Avengers.erase("War Machine");        // returns 0 because we never added War Machine to the set
    cout << "Number Erased: " << num_erased1 << " " << num_erased2 << endl;

    // use iterator to delete elements from a set
    Avengers.erase(Avengers.lower_bound("C"), Avengers.upper_bound("S"));   // clear out everything that starts with C - R in the set

    cout << "Avengers: ";
    for (auto element : Avengers) {
        cout << element << ", ";
    }
    cout << endl;

    // stuff that works for all containers
    cout << "size: " << Avengers.size() << endl;
    cout << "empty: " << boolalpha << Avengers.empty() << endl;
    cout << "clear" << endl;
    Avengers.clear();   // set still exists but now it's empty
    cout << "size: " << Avengers.size() << endl;
    cout << "empty: " << boolalpha << Avengers.empty() << endl;

    return 0;
}