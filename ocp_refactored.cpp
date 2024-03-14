#include <iostream>
#include <memory>
#include <vector>

// Oven Mode interface
class OvenMode {
public:
    virtual void setMode() const = 0;
    virtual ~OvenMode() = default;
};

// Concrete Oven Mode: BAKE
class BakeMode : public OvenMode {
public:
    void setMode() const override {
        std::cout << "Setting mode to BAKE\n";
    }
};

// Concrete Oven Mode: BROIL
class BroilMode : public OvenMode {
public:
    void setMode() const override {
        std::cout << "Setting mode to BROIL\n";
    }
};

// Concrete Oven Mode: TOAST
class ToastMode : public OvenMode {
public:
    void setMode() const override {
        std::cout << "Setting mode to TOAST\n";
    }
};

// Oven class with different modes implemented using polymorphism
class Oven {
private:
    std::vector<std::shared_ptr<OvenMode>> modes;

public:
    Oven() {
        modes.push_back(std::make_shared<BakeMode>());
        modes.push_back(std::make_shared<BroilMode>());
        modes.push_back(std::make_shared<ToastMode>());
    }

    void setMode(size_t index) {
        if (index < modes.size()) {
            modes[index]->setMode();
        } else {
            std::cout << "Invalid mode index\n";
        }
    }
};

int main() {
    Oven oven;

    // Set different modes
    oven.setMode(0); // BAKE
    oven.setMode(1); // BROIL
    oven.setMode(2); // TOAST

    return 0;
}
