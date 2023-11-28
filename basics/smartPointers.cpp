#include <iostream>
#include <string>
#include <memory>   // gives access to smart pointers (unique, shared, weak)

using namespace std;

class Entity {
    public:
        // constructor
        Entity() {
            cout << "Created Entity!" << endl;
        }

        // destructor
        ~Entity() {
            cout << "Destroyed Entity!" << endl;
        }

        void printEntity() {
            cout << "Printing Entity." << endl;
        }
};

int main() {
    // one way to make a unique pointer
    unique_ptr<Entity> u_entity1(new Entity);
    u_entity1->printEntity();

    // preferred way to make a unique pointer; avoid dangling pointers
    unique_ptr<Entity> u_entity2 = make_unique<Entity>();
    // unique_ptr<Entity> u_entity3 = u_entity2;   // gives an error because we can't copy unique pointers
    u_entity2->printEntity();

    // one way to make a shared pointer
    shared_ptr<Entity> s_entity1(new Entity);

    // preferred way to make a shared pointer
    shared_ptr<Entity> s_entity2 = make_shared<Entity>();
    shared_ptr<Entity> s_entity3 = s_entity2;

    shared_ptr<int> test = make_shared<int>(5);
    cout << *(test) << endl;
}

