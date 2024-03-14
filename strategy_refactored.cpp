#include <iostream>
#include <memory>

// Strategy interface
class ConnectivityStrategy {
public:
    virtual void connect() const = 0;
    virtual ~ConnectivityStrategy() = default;
};

// Concrete Strategy: WiFi
class WiFiStrategy : public ConnectivityStrategy {
public:
    void connect() const override {
        std::cout << "Connecting via WiFi\n";
    }
};

// Concrete Strategy: LTE
class LTEStrategy : public ConnectivityStrategy {
public:
    void connect() const override {
        std::cout << "Connecting via LTE\n";
    }
};

// Context class
class HomeConnect {
private:
    std::shared_ptr<ConnectivityStrategy> strategy;

public:
    // Constructor taking initial strategy
    explicit HomeConnect(std::shared_ptr<ConnectivityStrategy> initialStrategy) : strategy(std::move(initialStrategy)) {}

    // Setter method to change strategy dynamically
    void setConnectivityStrategy(std::shared_ptr<ConnectivityStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    // Method to connect based on the current strategy
    void connect() const {
        strategy->connect();
    }

    // Method to decide which strategy to use based on WiFi availability
    void decideConnectivity(const bool hasWiFi) {
        if (hasWiFi) {
            setConnectivityStrategy(std::make_shared<WiFiStrategy>());
        } else {
            setConnectivityStrategy(std::make_shared<LTEStrategy>());
        }
    }
};

int main() {
    // Example usage
    HomeConnect homeConnect(std::make_shared<WiFiStrategy>());
    homeConnect.connect(); // Connecting via WiFi

    // Simulate WiFi unavailable, switch to LTE
    homeConnect.decideConnectivity(false);
    homeConnect.connect(); // Connecting via LTE

    return 0;
}
