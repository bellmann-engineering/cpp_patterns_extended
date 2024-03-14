#include <iostream>
#include <vector>

// Implementation of a List using composition
template<typename T>
class List {
private:
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

// Implementation of a Stack using composition
template<typename T>
class Stack {
private:
    List<T> elements; // Using List to store stack elements

public:
    void push(const T& item) {
        elements.add(item);
    }

    void print() const {
        elements.print();
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

    return 0;
}
