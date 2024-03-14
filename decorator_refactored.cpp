#include <iostream>
#include <memory>

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

// Decorator for marking a mode as favorite
class FavoriteModeDecorator : public DishwasherMode {
protected:
    std::shared_ptr<DishwasherMode> mode;

public:
    explicit FavoriteModeDecorator(std::shared_ptr<DishwasherMode> mode) : mode(std::move(mode)) {}

    virtual void run() const override {
        mode->run();
    }

    virtual void runAsFavorite() const = 0;
};

// Concrete Favorite Mode Decorator: Favorite Normal Mode
class FavoriteNormalMode : public FavoriteModeDecorator {
public:
    explicit FavoriteNormalMode(std::shared_ptr<DishwasherMode> mode) : FavoriteModeDecorator(std::move(mode)) {}

    void runAsFavorite() const override {
        std::cout << "Running in favorite normal mode\n";
    }
};

// Concrete Favorite Mode Decorator: Favorite Eco Mode
class FavoriteEcoMode : public FavoriteModeDecorator {
public:
    explicit FavoriteEcoMode(std::shared_ptr<DishwasherMode> mode) : FavoriteModeDecorator(std::move(mode)) {}

    void runAsFavorite() const override {
        std::cout << "Running in favorite eco mode\n";
    }
};

// Concrete Favorite Mode Decorator: Favorite Intensive Mode
class FavoriteIntensiveMode : public FavoriteModeDecorator {
public:
    explicit FavoriteIntensiveMode(std::shared_ptr<DishwasherMode> mode) : FavoriteModeDecorator(std::move(mode)) {}

    void runAsFavorite() const override {
        std::cout << "Running in favorite intensive mode\n";
    }
};

// Dishwasher class
class Dishwasher {
private:
    std::shared_ptr<DishwasherMode> mode;

public:
    Dishwasher(std::shared_ptr<DishwasherMode> initialMode) : mode(std::move(initialMode)) {}

    // Set mode as favorite
    void setFavoriteMode(std::shared_ptr<DishwasherMode> mode) {
        this->mode = mode;
    }

    // Run the dishwasher
    void run() const {
        mode->run();
    }
};

int main() {
    // Create dishwasher with normal mode
    Dishwasher dishwasher(std::make_shared<NormalMode>());
    dishwasher.run(); // Running in normal mode

    std::cout << "\n";

    // Switch to favorite eco mode
    dishwasher.setFavoriteMode(std::make_shared<FavoriteEcoMode>(std::make_shared<EcoMode>()));
    dishwasher.run(); // Running in eco mode
    std::cout << "Favorite mode: ";
    std::dynamic_pointer_cast<FavoriteModeDecorator>(dishwasher.mode)->runAsFavorite(); // Running in favorite eco mode

    return 0;
}
