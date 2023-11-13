#include <iostream>

using namespace std;

// parent class / super class
class Chef {
    public:
        void makeChicken() {cout << "The chef makes chicken." << endl;}
        void makeSalad() {cout << "The chef makes salad." << endl;}
        void makeSpecialDish() {cout << "The chef makes their special dish." << endl;}
    private:
};

// ItalianChef (child class) inherits from Chef
class ItalianChef : public Chef {
    public:
        void makeChicken() {cout << "The chef cooks chicken." << endl;}
        void makePasta() {cout << "The chef cooks pasta." << endl;}
};

int main() {
    Chef ramsay;
    ramsay.makeChicken();
    ItalianChef batali;
    batali.makeChicken();
    batali.makePasta();
    return 0;
}
