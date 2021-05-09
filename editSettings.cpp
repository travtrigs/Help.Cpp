//
//  editSettings.cpp
//  Help
//
//  Created by Travis Triglianos on 9/10/15.
//  Copyright © 2015 Travis Triglianos. All rights reserved.
//

#include "editSettings.h"

void editSettings(string username) {
    //opens settings file
    string fileName = "/Users/";
    fileName += username;
    fileName += "/Settings/settings.txt";
    ifstream inFile;
    inFile.open(fileName);
    
    //sets labels for settings
    string labels[9] {
        "Name: ",
        "Email: ",
        "Phone: ",
        "Birthday: ",
        "Age: ",
        "Gender: ",
        "Company: ",
        "Organization: ",
        "Institution: "
    };
    
    //displays current settings
    string settings [9];
    cout << endl << "Current settings (0 = hidden, 1 = shown): " << endl;
    for (int i = 0; i < 9; i++) {
        inFile >> settings[i];
        cout << labels[i] << settings[i] << endl;
    }
    
    //allows user to edit settings or return
    char input;
    cout << "Enter 'y' to edit, or 'n' to return: ";
    cin >> input;
    
    //checks if input is valid
    while (input != 'y' && input != 'n') {
        cout << "Input must be either 'y' or 'n'." << endl;
        cout << "Enter 'y' to edit, or 'n' to return: ";
        cin >> input;
    }
    
    //closes settings file
    inFile.close();
    
    //returns to menu
    if (input == 'n') {
        return;
    }
    
    //opens settings file
    ofstream outFile;
    outFile.open(fileName);
    
    //allows user to edit settings and writes to file
    cout << "Enter 1 to share, or 0 to hide." << endl;
    for (int i = 0; i < 9; i++) {
        cout << labels[i];
        cin >> settings[i];
        outFile << settings[i] << endl;
    }
    
    //closes settings file
    outFile.close();
    
    //creates user profile
    makeProfile(username);
}
