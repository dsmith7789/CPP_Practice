#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class Student {
    public:
        // members
        string name;
        string major;
        double gpa;

        // constructor
        Student(string name, string major, double gpa) {
            this->name = name;
            this->major = major;
            this->gpa = gpa;
        }

        // methods
        void printStudent() {
            cout << "Student: [name=" << this->name << ", major=" << this->major << ", gpa=" << this->gpa << "]" << endl;
        }

        bool honorRoll() {
            if (this->gpa >= 3.5) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    Student Jim("Jim", "Business", 2.4);
    Student Pam("Pam", "Art", 3.6);
    Jim.printStudent();
    Pam.printStudent();

    cout << "Is Jim on the honor roll? " << boolalpha << Jim.honorRoll() << endl; 
    cout << "Is Pam on the honor roll? " << boolalpha << Pam.honorRoll() << endl;
    
    return 0;
}