#include <iostream>
#include <cmath>
using namespace std;

// Method Overloading (Static Polymorphism)
class Calculator {
public:
    // Overloaded methods for addition
    int add(int a, int b) { // Adding two integers
        return a + b;
    }

    double add(double a, double b) { // Adding two doubles
        return a + b;
    }

    int add(int a, int b, int c) { // Adding three integers
        return a + b + c;
    }
};

// Base class
class Operation {
public:
    virtual void perform(int a, int b) { // Base method
        cout << "Base class: Operation not defined." << endl;
    }
};

// Derived class for addition
class Addition : public Operation {
public:
    void perform(int a, int b) override { // Overriding the base method
        cout << "Addition result: " << a + b << endl;
    }
};

// Derived class for power
class Power : public Operation {
public:
    void perform(int a, int b) override { // Overriding the base method
        cout << "Power result: " << pow(a, b) << endl;
    }
};

// Main function to compare
int main() {
    // Overloading example
    Calculator calc;
    cout << "Overloading Examples:" << endl;
    cout << "Addition of 3 and 4: " << calc.add(3, 4) << endl;
    cout << "Addition of 2.5 and 3.7: " << calc.add(2.5, 3.7) << endl;
    cout << "Addition of 1, 2, and 3: " << calc.add(1, 2, 3) << endl;

    // Overriding example
    cout << "\nOverriding Examples:" << endl;
    Operation* op;
    Addition addObj;
    Power powerObj;

    op = &addObj; // Polymorphism at runtime
    op->perform(3, 4); // Calls Addition's perform()

    op = &powerObj;
    op->perform(2, 3); // Calls Power's perform()

    return 0;
}
