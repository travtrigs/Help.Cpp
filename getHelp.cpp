#include "getHelp.h"

void getHelp(User user) {
    
    std::ifstream inFile;
    std::string folderName = "/Server/Tags/";
    std::string fileName = "/Server/Tags/tags.txt";
    bool opened = false;
    std::string input, username,line, category;
    
    std::vector <std::string> allowed = {"1", "2", "3"};
    std::string request = "Enter 1 to browse categories, 2 to ask a question, or 3 to return to main menu: ";
    switch (std::stoi(checkInput(request, allowed))) {
        case 1:
            inFile.open(fileName);
            std::cout << std::endl;
            while (!inFile.eof()) {
                getline(inFile, line);
                std::cout << line << std::endl;
            }
            inFile.close();
            
            while (opened == false) {
                std::cout << std::endl << "Enter a category to view its subcategories or see specialists: ";
                std::cin >> category;
                std::cout << std::endl;
                
                folderName += category;
                folderName += "/";
                fileName = folderName + category + ".txt";
                
                inFile.open(fileName);
                if (inFile.is_open()) {
                    while (!inFile.eof()) {
                        getline(inFile, line);
                        std::cout << line << std::endl;
                    }
                    std::cout << std::endl;
                    inFile.close();
                    std::cout << "Enter a username to view their profile, or 1 return to main menu: ";
                    std::cin >> username;
                    std::cout << std::endl;
                    
                    if (username == "1") return;
                    else {
                        User toUser;
                        toUser.set(username);
                        inFile.open(toUser.profile());
                        while (!inFile.eof()) {
                            getline(inFile, line);
                            std::cout << line << std::endl;
                            
                        }
                        inFile.close();
                        
                        request = "Enter 1 to send " + toUser.name() + " a message, or 2 to return to main menu: ";
                        std::vector <std::string> allowed = {"1", "2"};
                        input = checkInput(request, allowed);
                        if (input == "1") {
                            sendMessage(user, toUser);
                        }
                        else return;
                    }
                    opened = true;
                }
                else {
                    inFile.close();
                    fileName = folderName + "tags.txt";
                    inFile.open(fileName);
                    while (!inFile.eof()) {
                        getline(inFile, line);
                        std::cout << line << std::endl;
                    }
                    inFile.close();
                }
            }
            break;
        case 2:
            break;
        case 3:
            break;
    }
    return;
}