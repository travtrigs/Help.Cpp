#include "viewMessage.h"

//displays a message thread
void viewMessage(User fromUser, User toUser) {
    
    //opens message thread file
    std::ifstream inFile;
    std::string fileName = fromUser.folder() + toUser.name() + ".txt";
    inFile.open(fileName);
    
    //checks for filename error
    while (!inFile.is_open()) {
        std::cout << "You do not have any messages with " << toUser.name() << std::endl;
        std::cout << "Enter a username to view a message thread: ";
        std::string username;
        std::cin >> username;
        fileName = fromUser.folder() + toUser.name() + ".txt";
        inFile.open(fileName);
    }
    
    //gets and displays message thread
    std::string line;
    while (!inFile.eof()) {
        getline(inFile, line);
        std::cout << line << std::endl;
    }
    
    //reply or return to main menu
    std::string request = "\nEnter 1 to reply, or 2 to return to the main menu: ";
    std::vector <std::string> allowed = {"1", "2"};
    std::string input = checkInput(request, allowed);
    
    //reply
    if (input == "1") sendMessage(fromUser, toUser);
    
    //return to main menu
    if (input == "2") return;
    
}
