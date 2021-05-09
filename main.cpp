#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "signIn.h"
#include "signUp.h"
#include "createDirectories.h"
#include "editSettings.h"
#include "makeProfile.h"
using namespace std;

void findSpecialist();
void searchQuestions();
void askQuestion();
void viewMessages(string);

void signOut();

int main() {
    //gets input to sign in or create new user
    string input;
    cout << "Enter 1 to sign in or 2 to sign up: ";
    cin >> input;
    
    //checks if input is valid
    while (input != "1" && input != "2") {
        cout << "Input must be either 1 or 2." << endl;
        cout << "Enter 1 to sign in or 2 to create an account: ";
        cin >> input;
    }
    
    //gets input for username
    string username;
    cout << "Username: ";
    cin >> username;
    
    //signs user in
    if (input == "1") signIn(username);
    
    //creates user
    if (input == "2") signUp(username);
    
    //main menu
    while (input != "7") {
        cout << "Main Menu" << endl;
        cout << "Enter 1 to find a specialist" << endl;
        cout << "Enter 2 to search for questions" << endl;
        cout << "Enter 3 to ask a question" << endl;
        cout << "Enter 4 to view/send messages" << endl;
        cout << "Enter 5 to edit your settings" << endl;
        cout << "Enter 6 to sign out" << endl;
        cout << "Enter 7 to exit" << endl;
        cin >> input;
        
        //checks if input is valid
        while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7") {
            cout << "Input must be 1, 2, 3, 4, 5, 6, or 7." << endl;
            cin >> input;
        }
        
        //calls selected menu function
        switch (stoi(input)) {
            case 1: findSpecialist();
                break;
            case 2: searchQuestions();
                break;
            case 3: askQuestion();
                break;
            case 4: viewMessages(username);
                break;
            case 5: editSettings(username);
                break;
            case 6: signOut();
                break;
        }
    }
    return 0;
}
  
//finds users with a specialty
void findSpecialist() {
    //gets specialty
    string specialty;
    cout << "Please enter the specialty you are looking for, or enter 'r' to return: ";
    cin >> specialty;
    
    //returns to menu
    if (specialty == "r") return;
    
    //opens specialty file
    string fileName = "/Specialties/";
    fileName += specialty;
    fileName += "/users.txt";
    ifstream inFile;
    inFile.open(fileName);
    
    //checks if specialty file exists
    while (!inFile.is_open()) {
        cout << "There are no users with that specialty. Maybe you made a spelling mistake?" << endl;
        
        //gets specialty
        cout << "Please enter the specialty you are looking for, or enter 'r' to return: ";
        cin >> specialty;
        
        //returns to menu
        if (specialty == "r") return;
        
        //opens specialty file
        fileName = "/Specialties/";
        fileName += specialty;
        fileName += "/users.txt";
        inFile.open(fileName);
    }
    
    //displays users with specialty
    cout << "Users that specialize in " << specialty << ":" << endl;
    while (!inFile.eof()) {
        string user;
        getline(inFile,user);
        cout << user << endl;
    }
    
    //closes specialty file
    inFile.close();
    
    //gets user
    string user;
    cout << "Enter a username to view their profile, or enter 'r' to return: ";
    cin >> user;
    
    //returns to menu
    if (user == "r") return;
    
    //opens user profile
    fileName = "/Users/";
    fileName += user;
    fileName += "/Info/profile.txt";
    inFile.open(fileName);
    
    //checks if user exists
    while (!inFile.is_open()) {
        cout << "This user does not exist. Maybe you made a spelling mistake?" << endl;
        
        //gets user
        cout << "Enter a username to view their profile, or enter 'r' to return: ";
        cin >> user;
        
        //returns to menu
        if (user == "r") return;

        //opens user profile
        fileName = "/Users/";
        fileName += user;
        fileName += "/Info/profile.txt";
        inFile.open(fileName);
    }
    
    //prints user profile
    while (!inFile.eof()) {
        string profile;
        getline(inFile,profile);
        cout << profile << endl;
    }
    
    //returns to menu
    cout << "Press enter to return.";
    cin.get();
}
//search questions*
void searchQuestions() {
    
}
//ask question*
void askQuestion() {
    
}
//display messages*
void viewMessages(string username) {
    
}

//sign out user
void signOut() {
    
}




