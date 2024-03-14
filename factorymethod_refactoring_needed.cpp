#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    void display() const {
        std::cout << "Name: " << name << ", Email: " << email << std::endl;
    }
};

class HomeconnectSystem {
public:
    static std::vector<User> readUsersFromCSV(const std::string& filename) {
        std::vector<User> users;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return users;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, email;
            if (std::getline(iss, name, ',') && std::getline(iss, email)) {
                users.emplace_back(name, email);
            }
        }

        file.close();
        return users;
    }
};

int main() {
    std::vector<User> users = HomeconnectSystem::readUsersFromCSV("users.csv");

    // Display users
    for (const auto& user : users) {
        user.display();
    }

    return 0;
}
