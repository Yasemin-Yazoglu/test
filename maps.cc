#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

bool createUser (std::unordered_map<std::string, size_t>& datenbank, std::string nutzername, size_t hpassword) {
    if (datenbank.count(nutzername) == false) {
        datenbank.insert({nutzername, hpassword});
        return true;
    }
    else {
        return false;
    }
}

bool authenticateUser(const std::unordered_map<std::string, size_t> datenbank, std::string nutzername, size_t hpassword) {
    if (datenbank.count(nutzername) == true) {
        size_t value = datenbank.at(nutzername);
        if (value == hpassword) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

size_t hashpassword (std::string password) {
    size_t hashed;
    std::hash<std::string> hash_fn;
    hashed = hash_fn(password);
    return hashed;
}

void listUsers(const std::unordered_map<std::string, size_t> datenbank) {
    for (auto x : datenbank) {
        std::cout << x.first << " " << x.second << std::endl;
    }
}


int main() {
    std::unordered_map<std::string, size_t> datenbank;

    std::string user;
    std::string password;

    while (true) {
        std::cout << "Choose an option: Press: (1) Registration, (2) Login, (3) Close" << std::endl;
        int a;
        std::cin >> a;
        if (a == 1) {
            std::cout << "Enter username and password to create an account." << std::endl;
            std::cin >> user;
            std::cin >> password;
            size_t hpassword = hashpassword(password);
            bool us = createUser(datenbank, user, hpassword);
            if (us == true) {
                std::cout << "Success! Your account was registered." << std::endl;
                std::cout << hpassword << std::endl;
            }
            else {
                std::cout << "This username already exists!" << std::endl;
                continue;
            }
        }
        else if (a == 2) {
            std::cout << "Enter username and password. " << std::endl;
            std::cin >> user;
            std::cin >> password;
            size_t hpassword = hashpassword(password);
            bool auth = authenticateUser(datenbank, user, hpassword);
            if (auth == false) {
                std::cout << "Wrong username or passowrd!" << std::endl;
                continue;
            }
            else {
                std::cout << "You logged in successfully!" << std::endl;
                listUsers(datenbank);
                std::cout << "Do you want to change your password? (1) Yes (2) No " << std::endl;
                int b;
                std::cin >> b;
                if (b == 1) {
                    std::string newPassword;
                    std::cout << "Enter new password: " << std::flush;
                    std::cin >> newPassword;
                    size_t hpassword = hashpassword(newPassword);
                    datenbank.at(user) = hpassword;
                }
                else {
                    continue;
                }
            }
        }
        else if (a == 3) {
            break;
        }
        else {
            std::cout << "INVALID NUMBER!" << std::endl;
        }
    }
    
    return 0;

}
