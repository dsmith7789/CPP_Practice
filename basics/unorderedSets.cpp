#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

// Unordered Set = uses hash for fast access/membership check
// Can't iterate over a range 
// no lower_bound() or upper_bound()
// Can't modify a set as we iterate through it

int main() {
    // order is alphabetical - because of set's binary tree implementation
    set<string> avengers = {"Thor", "Hulk", "Captain America", "Iron Man", "Black Widow"};
    cout << "Original Avengers Set: " << endl;
    for (auto e : avengers){
        cout << e << endl;
    }
    cout << endl;

    // order is determined by hash function - looks random to the user
    unordered_set<string> u_avengers(avengers.begin(), avengers.end());
    cout << "Unordered Avengers Set: " << endl;
    for (auto e : u_avengers){
        cout << e << endl;
    }
    cout << endl;

    vector<string> moreAvengers = {"Wasp", "Ant-Man", "Hawkeye", "Scarlet Witch"};
    u_avengers.insert(moreAvengers.begin(), moreAvengers.end());  //  iterators use pointer arithmetic (so moreAvengers.begin() + 1 is valid)

    // order is different than before, because C++ needed to re-hash (needed more memory)
    cout << "Unordered Avengers Set after adding more Avengers: " << endl;
    for (auto e : u_avengers){
        cout << e << endl;
    }
    cout << endl;

    return 0;
}