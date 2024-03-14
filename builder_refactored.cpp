#include <iostream>
#include <string>

class MicrowaveBuilder;

class Microwave {
private:
    std::string brand;
    int powerLevel;
    int cookingTime;
    bool grillMode;
    bool convectionMode;
    bool defrostMode;

    // Set default values in the constructor
    Microwave()
        : brand("Generic Microwave"), powerLevel(5), cookingTime(60), grillMode(false), convectionMode(false), defrostMode(false) {}

    Microwave(const std::string& brand, int powerLevel, int cookingTime, bool grillMode, bool convectionMode, bool defrostMode)
        : brand(brand), powerLevel(powerLevel), cookingTime(cookingTime), grillMode(grillMode), convectionMode(convectionMode), defrostMode(defrostMode) {}

public:
    friend class MicrowaveBuilder;

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

class MicrowaveBuilder {
private:
    std::string brand;
    int powerLevel;
    int cookingTime;
    bool grillMode;
    bool convectionMode;
    bool defrostMode;

public:
    MicrowaveBuilder()
        : brand("Generic Microwave"), powerLevel(5), cookingTime(60), grillMode(false), convectionMode(false), defrostMode(false) {}

    MicrowaveBuilder& setBrand(const std::string& brand) {
        this->brand = brand;
        return *this;
    }

    MicrowaveBuilder& setPowerLevel(int powerLevel) {
        this->powerLevel = powerLevel;
        return *this;
    }

    MicrowaveBuilder& setCookingTime(int cookingTime) {
        this->cookingTime = cookingTime;
        return *this;
    }

    MicrowaveBuilder& setGrillMode(bool grillMode) {
        this->grillMode = grillMode;
        return *this;
    }

    MicrowaveBuilder& setConvectionMode(bool convectionMode) {
        this->convectionMode = convectionMode;
        return *this;
    }

    MicrowaveBuilder& setDefrostMode(bool defrostMode) {
        this->defrostMode = defrostMode;
        return *this;
    }

    Microwave build() {
        return Microwave(brand, powerLevel, cookingTime, grillMode, convectionMode, defrostMode);
    }
};

int main() {
    MicrowaveBuilder builder;
    Microwave myMicrowave = builder.build();
    myMicrowave.start();
    return 0;
}
