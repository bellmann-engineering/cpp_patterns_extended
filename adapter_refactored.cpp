#include <iostream>
#include <memory>

class LiquidDetergent {
public:
    virtual double getDetergentAmount() {
        return 30;
    }
};

class PowderDetergent {
public:
    double getDetergentAmountInGrams() {
        return 50;
    }
};

// Adapter class to adapt PowderDetergent to LiquidDetergent interface
class PowderDetergentAdapter : public LiquidDetergent {
private:
    PowderDetergent m_powderDetergent;

public:
    virtual double getDetergentAmount() override {
        // Assuming 1 gram of powder detergent equals 1 milliliter of liquid detergent
        return m_powderDetergent.getDetergentAmountInGrams();
    }
};

class WashingMachine {
public:
    WashingMachine(std::unique_ptr<LiquidDetergent> detergent)
        : m_detergent(std::move(detergent)) {}

    void wash() {
        double detergentAmount = m_detergent->getDetergentAmount();
        std::cout << "Washing with " << detergentAmount << " milliliters of detergent." << std::endl;
    }

private:
    std::unique_ptr<LiquidDetergent> m_detergent;
};

int main() {
    // Using LiquidDetergent
    std::unique_ptr<LiquidDetergent> liquidDetergent = std::make_unique<LiquidDetergent>();
    WashingMachine washingMachine(std::move(liquidDetergent));
    washingMachine.wash();

    // Using PowderDetergent via Adapter
    std::unique_ptr<LiquidDetergent> powderAdapter = std::make_unique<PowderDetergentAdapter>();
    WashingMachine washingMachine2(std::move(powderAdapter));
    washingMachine2.wash();

    return 0;
}
