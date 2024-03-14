#include <iostream>

// Context class
class HomeConnect {
public:
    // Method to connect using either WiFi or LTE based on WiFi availability
    void connect(const bool hasWiFi) const {
        if (hasWiFi) {
            std::cout << "Connecting via WiFi\n";
        } else {
            std::cout << "Connecting via LTE\n";
        }
    }
};

int main() {
    // Example usage
    HomeConnect homeConnect;
    
    // Simulate WiFi available
    homeConnect.connect(true); // Connecting via WiFi
    
    // Simulate WiFi unavailable
    homeConnect.connect(false); // Connecting via LTE

    return 0;
}
