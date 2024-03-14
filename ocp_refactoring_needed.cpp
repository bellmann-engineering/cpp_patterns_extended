#include <iostream>

// Oven class with different modes implemented using switch-case
class Oven {
public:
    enum class Mode { BAKE, BROIL, TOAST };

    void setMode(Mode mode) {
        switch (mode) {
            case Mode::BAKE:
                std::cout << "Setting mode to BAKE\n";
                break;
            case Mode::BROIL:
                std::cout << "Setting mode to BROIL\n";
                break;
            case Mode::TOAST:
                std::cout << "Setting mode to TOAST\n";
                break;
        }
    }
};

int main() {
    Oven oven;
    
    // Set different modes
    oven.setMode(Oven::Mode::BAKE);
    oven.setMode(Oven::Mode::BROIL);
    oven.setMode(Oven::Mode::TOAST);

    return 0;
}
