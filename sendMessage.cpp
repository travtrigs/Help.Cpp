#include "sendMessage.h"

void sendMessage(User fromUser, User toUser) {
    
    //opens sender message thread file
    
    std::string input = "2";
    while (input == "2") {
        
        std::string message;
        std::cout << std::endl << fromUser.name() << ": ";
        std::cin.ignore();
        std::getline(std::cin, message);
        
        std::string request = "\nPress 1 to send message, 2 to edit, or 3 to return to main menu: ";
        std::vector <std::string> allowed = {"1", "2", "3"};
        std::string input = checkInput(request, allowed);
        
        if (input == "1") {
            
            std::string line;
            
            //saves from users message file
            std::ifstream inFile_from;
            inFile_from.open(fromUser.messages());
            std::vector <std::string> threads_from;
            while (!inFile_from.eof()) {
                getline(inFile_from, line);
                threads_from.push_back(line);
            }
            inFile_from.close();
            
            //updates from users message file
            std::ofstream outFile_from;
            outFile_from.open(fromUser.messages());
            outFile_from << toUser.name();
            for (int i = 0; i < threads_from.size(); i++) {
                if (threads_from.at(i) != toUser.name()) {
                    outFile_from << std::endl << threads_from.at(i);
                }
            }
            outFile_from.close();
            
            //updates from users message thread
            outFile_from.open(fromUser.folder() + toUser.name() + ".txt", std::ofstream::app);
            outFile_from << std::endl << fromUser.name() << ": " << message;
            outFile_from.close();
            
            //saves to users message file
            std::ifstream inFile_to;
            inFile_to.open(toUser.messages());
            std::vector <std::string> threads_to;
            while (!inFile_to.eof()) {
                getline(inFile_to, line);
                threads_to.push_back(line);
            }
            inFile_to.close();
            
            //updates to users message file
            std::ofstream outFile_to;
            outFile_to.open(toUser.messages());
            outFile_to << fromUser.name();
            for (int i = 0; i < threads_to.size(); i++) {
                if (threads_to.at(i) != fromUser.name()) {
                    outFile_to << std::endl << threads_to.at(i);
                }
            }
            outFile_to.close();
            
            //updates to users message thread
            outFile_to.open(toUser.folder() + fromUser.name() + ".txt", std::ofstream::app);
            outFile_to << std::endl << fromUser.name() << ": " << message;
            outFile_to.close();
        }
        if (input == "3") return;
    }
}
    
    

