#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class User {
private:
    std::string name;
    std::string email;

    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}

public:
    static User createUser(const std::string& name, const std::string& email) {
        // Basic validation checks
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty.");
        }
        if (email.empty()) {
            throw std::invalid_argument("Email cannot be empty.");
        }
        // Additional validation checks can be added as needed

        return User(name, email);
    }

    void display() const {
        std::cout << "Name: " << name << ", Email: " << email << std::endl;
    }
};

class HomeconnectSystem {
public:
    static std::vector<User> createUsers(const std::vector<std::pair<std::string, std::string>>& userData) {
        std::vector<User> users;
        for (const auto& data : userData) {
            try {
                users.push_back(User::createUser(data.first, data.second));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error creating user: " << e.what() << std::endl;
            }
        }
        return users;
    }
};

int main() {
    std::vector<std::pair<std::string, std::string>> userData = {
        {"John Doe", "john@example.com"},
        {"", "alice@example.com"}, // Invalid user data
        {"Bob Johnson", ""}, // Invalid user data
        {"Mary", "mary@example.com"}
    };

    std::vector<User> users = HomeconnectSystem::createUsers(userData);

    // Display valid users
    for (const auto& user : users) {
        user.display();
    }

    return 0;
}
