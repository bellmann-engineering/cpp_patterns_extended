#include <iostream>
#include <memory>
#include <string>
#include <sstream>

class GPS {
private:
    double latitude;
    double longitude;

   // TODO: Make a constructor

public:
    // TODO: Static factory method to create GPS from a coordinate string


    // Method to display the coordinates
    void printCoordinates() const {
        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }
};

int main() {
    // TODO: Create a GPS object from a valid coordinates string
    

    return 0;
}
