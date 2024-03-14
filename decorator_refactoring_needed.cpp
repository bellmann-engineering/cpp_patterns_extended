#include <iostream>
#include <memory>
#include <vector>

// Dishwasher Mode interface
class DishwasherMode {
public:
    virtual void run() const = 0;
    virtual ~DishwasherMode() = default;
};

// Concrete Dishwasher Mode: Normal Mode
class NormalMode : public DishwasherMode {
public:
    void run() const override {
        std::cout << "Running in normal mode\n";
    }
};

// Concrete Dishwasher Mode: Eco Mode
class EcoMode : public DishwasherMode {
public:
    void run() const override {
        std::cout << "Running in eco mode\n";
    }
};

// Concrete Dishwasher Mode: Intensive Mode
class IntensiveMode : public DishwasherMode {
public:
    void run() const override {
        std::cout << "Running in intensive mode\n";
    }
};

// Dishwasher class using bool to mark favorite mode
class Dishwasher {
private:
    std::vector<std::shared_ptr<DishwasherMode>> modes;
    bool isFavoriteModeSet;
    size_t favoriteModeIndex;

public:
    Dishwasher() : isFavoriteModeSet(false), favoriteModeIndex(0) {
        modes.push_back(std::make_shared<NormalMode>());
        modes.push_back(std::make_shared<EcoMode>());
        modes.push_back(std::make_shared<IntensiveMode>());
    }

    // Set mode as favorite
    void setFavoriteMode(size_t index) {
        if (index < modes.size()) {
            isFavoriteModeSet = true;
            favoriteModeIndex = index;
        } else {
            std::cout << "Invalid mode index\n";
        }
    }

    // Run the dishwasher
    void run() const {
        if (isFavoriteModeSet) {
            std::cout << "Running favorite mode: ";
            modes[favoriteModeIndex]->run();
        } else {
            std::cout << "No favorite mode set. Running normal mode: ";
            modes[0]->run();
        }
    }
};

// Dishwasher class using decorator pattern to mark favorite mode
class DishwasherDecorator {
private:
    std::vector<std::shared_ptr<DishwasherMode>> modes;
    std::shared_ptr<DishwasherMode> favoriteMode;

public:
    DishwasherDecorator() {
        modes.push_back(std::make_shared<NormalMode>());
        modes.push_back(std::make_shared<EcoMode>());
        modes.push_back(std::make_shared<IntensiveMode>());
    }

    // Set mode as favorite
    void setFavoriteMode(size_t index) {
        if (index < modes.size()) {
            favoriteMode = std::make_shared<FavoriteDecorator>(modes[index]);
        } else {
            std::cout << "Invalid mode index\n";
        }
    }

    // Run the dishwasher
    void run() const {
        if (favoriteMode) {
            std::cout << "Running favorite mode: ";
            favoriteMode->run();
        } else {
            std::cout << "No favorite mode set. Running normal mode: ";
            modes[0]->run();
        }
    }

private:
    // Decorator for marking a mode as favorite
    class FavoriteDecorator : public DishwasherMode {
    private:
        std::shared_ptr<DishwasherMode> mode;

    public:
        explicit FavoriteDecorator(std::shared_ptr<DishwasherMode> mode) : mode(std::move(mode)) {}

        void run() const override {
            mode->run();
        }
    };
};

int main() {
    // Example usage of Dishwasher
    Dishwasher dishwasher;
    dishwasher.setFavoriteMode(2); // Set Intensive mode as favorite
    dishwasher.run();

    std::cout << "\n";

    // Example usage of DishwasherDecorator
    DishwasherDecorator dishwasherDecorator;
    dishwasherDecorator.setFavoriteMode(1); // Set Eco mode as favorite
    dishwasherDecorator.run();

    return 0;
}
