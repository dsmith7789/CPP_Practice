#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    // list initialization
    vector<string> colors = {"red", "green", "blue"};
    vector<string> colors2{"red", "green", "blue"};     // something like "function style"
    // vector<string> colors3("red", "green", "blue"); // doesn't work

    // element access with []
    cout << "The first color is: " << colors[0] << endl;
    cout << "The second color is: " << colors2[1] << endl;

    // length or size of a vector
    cout << "There are " << colors.size() << " colors in the vector." << endl;

    // print out all the elements of a vector (accessing index)
    cout << "The elements of the vector are: " << "";
    for (int i = 0; i < colors.size(); i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    // print out all the elements of a vector (iterating through elements)
    cout << "The elements of the vector are: " << "";
    for (string color : colors) {
        cout << color << " ";
    }
    cout << endl;

    // adding elements to a vector
    colors.push_back("purple");    
     cout << "There are now " << colors.size() << " colors in the vector." << endl;
    cout << "The elements of the vector are now: " << "";
    for (string color : colors) {
        cout << color << " ";
    }
    cout << endl;

// Other ways to initialize vectors
    // initialize an empty array, to add data
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // parameterized vector construction
    // vector<type> variableName(size, defaultValue=0)
    vector<int> numbers2(10, -2);
    vector<int> numbers3(10);
    numbers3.push_back(8);

    vector<int> numbers4{10, -2};   // This is list initialization, not parameterized vector construction

    cout << "The elements of the vector 'numbers' are: " << "";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The elements of the vector 'numbers2' are: " << "";
    for (int num : numbers2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The elements of the vector 'numbers3' are: " << "";
    for (int num : numbers3) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The elements of the vector 'numbers4' are: " << "";
    for (int num : numbers4) {
        cout << num << " ";
    }
    cout << endl;

    // copying contents of one vector to another
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2(v1);
    vector<int> v3 = v1;

    cout << "The elements of the vector 'v1' are: " << "";
    for (int num : v1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The elements of the vector 'v2' are: " << "";
    for (int num : v2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The elements of the vector 'v3' are: " << "";
    for (int num : v3) {
        cout << num << " ";
    }
    cout << endl;

    v2[4] = 999;
    // v1 is not changed
    cout << "The elements of the vector 'v1' are: " << "";
    for (int num : v1) {
        cout << num << " ";
    }
    cout << endl;

    // v2 is changed
    cout << "The elements of the vector 'v2' are: " << "";
    for (int num : v2) {
        cout << num << " ";
    }
    cout << endl;

// Range Iterator and References
    system("clear");
    vector<int> v = {1, 2, 3, 4};
    cout << "original v: "; 
    for (int num : v) {
        cout << num << " "; 
    }
    cout << endl;

    // This DOESN'T update the elements in the array (updates copies of the element)
    for (auto element : v) {
        element *= 2;
    }
    cout << "Doubled v? (not reference): ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << endl;

    // This DOES update the elements in the array (updating reference)
    for (auto &element : v) {
        element *= 2;
    }
    cout << "Doubled v? (using reference): ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << endl;

    system("clear");

// Advanced Element Access
    for (string color : colors) {
        cout << color << " ";
    }
    cout << endl;

    // access by index
    cout << "colors[1] = " << colors[1] << endl;    // no bounds checking (undefined behavior with out of bounds access)

    // access with vector function "front()" or "back()" or "at(index)"
    cout << "colors.front() = " << colors.front() << endl;
    cout << "colors.back() = " << colors.back() << endl;
    cout << "colors.at(0) = " << colors.at(0) << endl;  // automatic bounds checking (so can crash with out of bounds access), but is slower

    // .front() returns a reference, so we can use the reference to update the original
    colors.front() = "white";
    cout << "Updated colors: " << " ";
    for (string color : colors) {
        cout << color << " ";
    }
    cout << endl;

    // vector of vectors (like a matrix)
    vector<int> row;
    vector< vector<int> > matrix;  // the spaces between ">" characters is necessary, otherwise C++ might mistake for stream extraction operator (ex. cin >> x;)

    // relational operators: work element-wise
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {1, 2, 3};
    vector<int> n3 = {2, 3, 4};
    vector<int> n4 = {0, 5, 2};

    cout << boolalpha;

    cout << "n1 == n2: " << (n1 == n2) << endl;
    cout << "n1 == n3: " << (n1 == n3) << endl;
    cout << "n1 < n3: " << (n1 < n3) << endl;
    cout << "n1 < n4: " << (n1 < n4) << endl;

    return 0; 
}