#include "checkInput.h"

std::string checkInput(std::string request, std::vector <std::string> allowed) {
    bool check = false;
    std::string input;
    std::cout << request;
    std::cin >> input;
    
    for (int i = 0; i < allowed.size(); i++) {
        if (input == allowed.at(i)) check = true;
    }
    while (!check) {
        std::cout << "Input must be: ";
        for (int i = 0; i < allowed.size()-1; i++) {
            std::cout << allowed.at(i) << ", ";
        }
        std::cout << "or " << allowed.at(allowed.size()-1) << "." << std::endl;
        std::cout << request;
        std::cin >> input;
        for (int i = 0; i < allowed.size(); i++) {
            if (input == allowed.at(i)) check = true;
        }
    }
    return input;
}