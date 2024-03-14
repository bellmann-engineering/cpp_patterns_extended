#include <iostream>
#include <memory>

// Interface
class DetergentInterface {
public:
    virtual double getDetergentAmount() = 0;
    virtual ~DetergentInterface() = default;
};

// Concrete implementation
class PowderDetergent : public DetergentInterface {
public:
    double getDetergentAmount() override {
        return 50;
    }
};

// Legacy component
class LiquidDetergent {
public:
    double getLiquidDetergentAmount() {
        return 30;
    }
};

// Adapter class
class LiquidDetergentAdapter : public DetergentInterface {
public:
    LiquidDetergentAdapter(std::unique_ptr<LiquidDetergent> liquidDetergent)
        : m_liquidDetergent(std::move(liquidDetergent)) {}

    double getDetergentAmount() override {
        double liquidDetergentAmount = m_liquidDetergent->getLiquidDetergentAmount();
        return liquidDetergentAmount * 1.67; // Convert liquid detergent amount to powder detergent amount
    }

private:
    std::unique_ptr<LiquidDetergent> m_liquidDetergent;
};

int main() {
    std::unique_ptr<LiquidDetergent> liquidDetergent = std::make_unique<LiquidDetergent>();
    std::unique_ptr<DetergentInterface> di = std::make_unique<LiquidDetergentAdapter>(std::move(liquidDetergent));
    std::cout << di->getDetergentAmount() << std::endl;

    return 0;
}
