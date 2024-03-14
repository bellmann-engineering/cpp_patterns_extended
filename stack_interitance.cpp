#include <iostream>
#include <vector>

// Base List class
template<typename T>
class List {
protected:
    std::vector<T> elements;

public:
    void add(const T& item) {
        elements.push_back(item);
    }

    void print() const {
        for (const auto& item : elements) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

// Derived Stack class inheriting from List (not recommended)
template<typename T>
class Stack : public List<T> {
public:
    void push(const T& item) {
        this->add(item); // accessing the add method from the base class List
    }

    void pop() {
        if (!this->elements.empty()) {
            this->elements.pop_back();
        }
    }
};

int main() {
    Stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Printing the stack
    std::cout << "Stack: ";
    myStack.print();

    // Popping an element from the stack
    myStack.pop();

    // Printing the stack after popping
    std::cout << "Stack after popping: ";
    myStack.print();

    return 0;
}
