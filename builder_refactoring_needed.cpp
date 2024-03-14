#include <iostream>
#include <string>

class Microwave {
private:
    std::string brand;
    int powerLevel;
    int cookingTime;
    bool grillMode;
    bool convectionMode;
    bool defrostMode;

public:
    Microwave(const std::string& brand, int powerLevel, int cookingTime, bool grillMode, bool convectionMode, bool defrostMode)
        : brand(brand), powerLevel(powerLevel), cookingTime(cookingTime), grillMode(grillMode), convectionMode(convectionMode), defrostMode(defrostMode) {}

    void start() {
        std::cout << "Microwave started with the following settings:" << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Power Level: " << powerLevel << std::endl;
        std::cout << "Cooking Time: " << cookingTime << " seconds" << std::endl;
        std::cout << "Grill Mode: " << (grillMode ? "On" : "Off") << std::endl;
        std::cout << "Convection Mode: " << (convectionMode ? "On" : "Off") << std::endl;
        std::cout << "Defrost Mode: " << (defrostMode ? "On" : "Off") << std::endl;
        std::cout << "Cooking..." << std::endl;
        // Simulate cooking process
    }
};

int main() {
    Microwave myMicrowave("ABC Microwave", 5, 60, true, false, true);
    myMicrowave.start();
    return 0;
}
