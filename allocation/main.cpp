#include <iostream>

using namespace std;

// a simple class
class Class1 {
private:
    string name;
public:
    Class1(string n) {
        name = n;
        cout << "constructor: " << n << endl;}
    void someFunc() {cout << "function: " << name << endl;}
    ~Class1() {cout << "destructor: " << name << endl;}
};


int main() {

    Class1 c1 = Class1("c1"); // c1 stack allocation -> constructor called
    c1.someFunc();

    {
        Class1 c2 = Class1("c2"); // c2 stack allocation -> constructor called
        c2.someFunc();

    } // c1 destructor called as class c1 goes out of scope

    Class1 *cp1 = new Class1("cp1"); // heap allocation cp1 -> constructor called
    cp1->someFunc();

    Class1 *cp2 = new Class1("cp2"); // heap allocation cp2 -> constructor called
    cp2->someFunc();
    delete(cp2); // explicit deletion of cp2 ->  -> destructor called


    return 0; // c1 destructor called as class c1 goes out of scope
    // cp1 is never freed -> memory leak!
}
