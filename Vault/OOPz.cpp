#include <iostream>
using namespace std;

class Animal {
    public:
        void Talk() {
            cout << "animal talking...\n";
        }
};

class Cat: public Animal {
    public:
        void Talk() {
            cout << "meow meow\n";
        }
};

int main() {
	Animal *tom = new Cat();
	tom->Talk();
	return 0;
}
