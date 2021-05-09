#include "myMessages.h"

//messages main menu
void myMessages(User user) {
    
    //opens messages file
    std::ifstream inFile;
    inFile.open(user.messages());
    
    //gets message threads
    std::vector <std::string> users;
    std::string line;
    while (!inFile.eof()) {
        getline(inFile, line);
        users.push_back(line);
    }

    //closes messages file
    inFile.close();
    
    //displays message threads
    std::cout << std::endl;
    for (int i = 0; i < users.size(); i++) {
        std::cout << users.at(i);
    }
    
    //view message thread or return to main menu
    std::string request = "Enter 1 to view a message thread or 2 to return to the main menu: ";
    std::vector <std::string> allowed = {"1", "2"};
    std::string input = checkInput(request, allowed);
    
    //view message thread
    if (input == "1") {
        std::cout << std::endl << "Enter a username to view a message thread: ";
        std::cin >> input;
        User toUser;
        toUser.set(input);
        viewMessage(user, toUser);
    }
    
    //return to main menu
    if (input == "2") return;
    
}