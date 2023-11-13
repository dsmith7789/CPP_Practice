#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

int main() {
    // pairs
    // pair<type1, type2> myPair;

    pair<string, int> class_to_number;
    class_to_number.first = "C++";
    class_to_number.second = 368;

    pair<string, int> class_to_number2("Data Programming", 220);
    pair<string, int> class_to_number3 = make_pair("Machine Programming", 354);

    cout << class_to_number.first << " " << class_to_number.second << endl;
    cout << class_to_number2.first << " " << class_to_number2.second << endl;
    cout << class_to_number3.first << " " << class_to_number3.second << endl;

    // constructing maps; always made of pairs
    map<string, int> classes_to_number; // empty map
    map<string, int> number_to_int{make_pair("one", 1), pair<string, int>("two", 2)};   // list initialization


    // inserting into maps
    number_to_int["three"] = 3; // similar to Python dict
    number_to_int.insert(make_pair("four", 4)); // insert() won't update if the value is already in the map

    // check if a key exists in the map
    // find returns an iterator either pointing to the matching pair in the map, or the end of the map (means the key's not there)
    if (number_to_int.find("four") != number_to_int.end()) {
        cout << "The key 'four' exists." << endl;
    }

    // get the value associated with a key
    cout << number_to_int["three"] << endl; // value exists
    cout << number_to_int["seven"] << endl; // value doesn't already exist --> C++ adds a pair of ("seven", 0), since 0 is the default value for int

    // erasing a key, value pair
    number_to_int.erase("seven");   // seven does exist in the map
    number_to_int.erase("nine"); // C++ ignores the key to erase if it's not in the map (no error)

    // balanced binary tree - pairs are sorted in alphabetical order by key
    for (auto e : number_to_int) {
        cout << e.first << " , " << e.second << endl;
    }

    // iteration through map
    for (auto iter = number_to_int.begin(); iter != number_to_int.end(); iter++) {
        string key = (*iter).first; // get the pair (dereference the pointer), and then extract first
        string key2 = iter->first;  // access members of an object pointed to with a pointer/iterator using "->"
        int value = iter->second;
        cout << "key: " << key << ", " << "value: " << value << endl;
    }

    // use count to check membership in a map
    if (number_to_int.count("four") > 0) {
        cout << "The key 'four' exists." << endl;
    } 
    
    return 0;
}