#include "giveHelp.h"

void giveHelp(User user) {
    std::string request = "\nEnter 1 for local help, 2 for global help, or 3 to return to main menu: ";
    std::vector <std::string> allowed = {"1", "2", "3"};
    std::string input = checkInput(request, allowed);
    std::string location;
    
    if (input == "1") {
        
        
    }
    
    if (input == "2") {
        
        
    }
    
    if (input == "3") return;
    
}