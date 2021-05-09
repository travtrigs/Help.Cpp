#include "makeProfile.h"

//create user profile
void makeProfile(string username) {
    //opens settings file
    ifstream inFile;
    string fileName = "/Users/";
    fileName += username;
    fileName += "/Settings/settings.txt";
    inFile.open(fileName);
    
    //writes settings to array
    int settings[9];
    for (int i = 0; i < 9; i++) {
        string setting;
        getline(inFile,setting);
        settings[i] = stoi(setting);
    }
    
    //closes settings file
    inFile.close();
    
    //opens info file
    fileName = "/Users/";
    fileName += username;
    fileName += "/Info/info.txt";
    inFile.open(fileName);
    ofstream outFile;
    
    //opens profile file
    fileName = "/Users/";
    fileName += username;
    fileName += "/Info/profile.txt";
    outFile.open(fileName);
    
    //gets and discards password
    string line;
    getline(inFile,line);
    
    //gets username
    getline(inFile,line);
    
    //prints username to profile
    outFile << "Username: " << line << endl;
    
    //gets first name
    getline(inFile,line);
    
    //prints first name to profile
    if (settings[0] == 1) {
        outFile << "Name: " << line;
        
        //gets last name
        getline(inFile,line);
        
        //prints last name to profile
        outFile << " " << line << endl;
    }
    
    //gets and discards first and last name
    else getline(inFile,line);
    
    //gets email
    getline(inFile,line);
    
    //prints email to profile
    if (settings[1] == 1) {
        outFile << "Email: " << line << endl;
    }
    
    //gets phone
    getline(inFile,line);
    
    //prints phone to profile
    if (settings[2] == 1) {
        outFile << "Phone: " << line << endl;
    }
    
    //gets month of birthday
    getline(inFile,line);
    
    //prints month of birthday to profile
    if (settings[3] == 1) {
        outFile << "Birthday: ";
        
        //converts month of birthday from number to word
        int month = stoi(line);
        switch (month) {
            case 1: outFile << "January ";
                break;
            case 2: outFile << "February ";
                break;
            case 3: outFile << "March ";
                break;
            case 4: outFile << "April ";
                break;
            case 5: outFile << "May ";
                break;
            case 6: outFile << "June ";
                break;
            case 7: outFile << "July ";
                break;
            case 8: outFile << "August ";
                break;
            case 9: outFile << "September ";
                break;
            case 10: outFile << "October ";
                break;
            case 11: outFile << "November ";
                break;
            case 12: outFile << "December ";
                break;
        }
        
        //gets day of birthday
        getline(inFile,line);
        
        //prints day of birthday to profile
        int day = stoi(line);
        outFile << day << " ";
        
        //gets year of birthday
        getline(inFile,line);
        
        //prints year of birthday to profile
        int year = stoi(line);
        outFile << year << endl;
    }
    
    //gets and discards birthday
    else {
        getline(inFile,line);
        getline(inFile,line);
    }
    
    //gets age
    getline(inFile,line);
    
    //prints age to profile
    if (settings[4] == 1) {
        outFile << "Age: " << line << endl;
    }
    
    //gets gender
    getline(inFile,line);
    
    //prints gender to profile
    if (settings[5] == 1) {
        outFile << "Gender: " << line << endl;
    }
    
    //gets company
    getline(inFile,line);
    
    //prints company to profile
    if (settings[6] == 1) {
        outFile << "Company: " << line << endl;
    }
    
    //gets organization
    getline(inFile,line);
    
    //prints organization to profile
    if (settings[7] == 1) {
        outFile << "Organization: " << line << endl;
    }
    
    //gets institution
    getline(inFile,line);
    
    //prints institution to profile
    if (settings[8] == 1) {
        outFile << "Institution: " << line << endl;
    }
    
    //closes profile file
    outFile.close();
}
