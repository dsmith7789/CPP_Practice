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
    set<string> avengers = {"Thor", "Hulk", "Captain America", "Iron Man", "Black Widow"};
    vector<string> moreAvengers = {"Wasp", "Ant-Man", "Hawkeye", "Scarlet Witch"};

    multiset<string> m_avengers(avengers.begin(), avengers.end());
    cout << "Original Multi Avengers: " << endl;
    for (auto e : m_avengers) {
        cout << e << endl;
    }
    m_avengers.insert(avengers.begin(), avengers.end());

    cout << "Multi Avengers after duplicate Avengers: " << endl;
    for (auto e : m_avengers) {
        cout << e << endl;
    }

    m_avengers.insert(avengers.begin(), avengers.end());

    cout << "Multi Avengers after triplicate Avengers: " << endl;
    for (auto e : m_avengers) {
        cout << e << endl;
    }

    // count
    cout << "Thor count: " << m_avengers.count("Thor") << endl;

    // process each key with the same value using iterators
    cout << "All instances of Hawkeye in the multiset: " << endl;
    for (auto iter = m_avengers.lower_bound("Thor"); iter != m_avengers.upper_bound("Thor"); iter++) {
        cout << *(iter) << endl;
    }
    
}