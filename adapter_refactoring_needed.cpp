#include <iostream>
#include <memory>

class LiquidDetergent {
public:
    double getDetergentAmount() {
        return 30;
    }
};

// How can we wash using powder detergent?

class WashingMachine {
public:
    WashingMachine(std::unique_ptr<LiquidDetergent> detergent)
        : m_detergent(std::move(detergent)) {}

    void wash() {
        double detergentAmount = m_detergent->getDetergentAmount();
        std::cout << "Washing with " << detergentAmount << " milliliters of liquid detergent." << std::endl;
    }

private:
    std::unique_ptr<LiquidDetergent> m_detergent;
};

int main() {
    std::unique_ptr<LiquidDetergent> liquidDetergent = std::make_unique<LiquidDetergent>();
    WashingMachine washingMachine(std::move(liquidDetergent));
    washingMachine.wash();

    return 0;
}
