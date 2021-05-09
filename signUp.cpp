#include "signUp.h"

//create new user
void signUp(string username) {
    
    
    //opens user info file
    string fileName = "/Users/";
    fileName += username;
    fileName += "/Info/info.txt";
    fstream test;
    test.open(fileName);
    
    //checks if username already exists
    while (test.is_open()) {
        cout << "Username already exists." << endl;
        test.close();
        
        //gets username
        cout << "Username: ";
        cin >> username;
        
        //opens user info file
        fileName = "/Users/";
        fileName += username;
        fileName += "/Info/info.txt";
        test.open(fileName);
    }
    
    //closes user info file
    test.close();
    
    //creates directories for new user
    createDirectories(username);
    
    //creates info file for new user
    ofstream outFile;
    outFile.open(fileName);
    
    //gets input for password
    string password;
    cout << "Password: ";
    cin >> password;
    
    //gets input for password again
    string check;
    cout << "Re-enter password: ";
    cin >> check;
    
    //checks if passwords match
    while (password != check) {
        cout << "Passwords do not match." << endl;
        
        //gets input for password
        cout << "Password: ";
        cin >> password;
        
        //gets input for password again
        cout << "Re-enter password: ";
        cin >> check;
    }
    
    //writes password and username to info file
    outFile << password << endl << username << endl;
    
    //gets first and last name and writes to info file
    string first, last;
    cout << "Please enter your first and last name: ";
    cin >> first >> last;
    outFile << first << endl << last << endl;
    
    //gets email and writes to info file
    string email;
    cout << "Please enter your email address: ";
    cin >> email;
    outFile << email << endl;
    
    //gets phone and writes to info file
    string phone;
    cout << "Please enter your phone number: ";
    cin >> phone;
    outFile << phone << endl;
    
    //gets birthday
    string birthday;
    cout << "Please enter your birthday (mm/dd/yyyy): ";
    cin >> birthday;
    
    //formats birthday and writes to info file
    int month, day, year;
    month = stoi(birthday.substr(0,2));
    day = stoi(birthday.substr(3,2));
    year = stoi(birthday.substr(6,4));
    outFile << month << endl << day << endl << year << endl;
    
    //gets current time
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int date[3] {(now->tm_year + 1900), (now->tm_mon + 1), (now->tm_mday)};
    
    //calculates age and writes to info file
    int age = date[0] - year;
    if ((month - date[1]) > 0) age--;
    if ((month - date[1]) == 0 && (day - date[2]) > 0) age--;
    outFile << age << endl;
    
    //gets gender and writes to info file
    char gender;
    cout << "Please enter your gender (m or f): ";
    cin >> gender;
    outFile << gender << endl;
    
    //gets input to add company to info file or not
    char input;
    cout << "Enter 'y' to add a company, or 'n' to skip: ";
    cin >> input;
    
    //adds company to info file
    if (input == 'y') {
        string company;
        cout << "Please enter your company: ";
        cin.ignore();
        getline(cin,company);
        outFile << company << endl;
    }
    
    //adds blank field for company to info file
    else outFile << endl;
    
    //gets input to add organization to info file or not
    cout << "Enter 'y' to add an organization, or 'n' to skip: ";
    cin >> input;
    
    //adds organization to info file
    if (input == 'y') {
        string organization;
        cout << "Please enter your organization: ";
        cin.ignore();
        getline(cin,organization);
        outFile << organization << endl;
    }
    
    //adds blank field for organization to info file
    else outFile << endl;
    
    //gets input to add institution to info file or not
    cout << "Enter 'y' to add an institution, or 'n' to skip: ";
    cin >> input;
    
    //adds institution to info file
    if (input == 'y') {
        string institution;
        cout << "Please enter your institution: ";
        cin.ignore();
        getline(cin,institution);
        outFile << institution << endl;
    }
    
    //adds blank field for institution to info file
    else outFile << endl;
    
    //closes info file
    outFile.close();
    
    //creates settings file for new user
    fileName = "/Users/";
    fileName += username;
    fileName += "/Settings/settings.txt";
    outFile.open(fileName);
    
    
    //sets default settings
    cout << "Now you may choose which information you'd like to share in your profile." << endl;
    int settings[9] {1, 1, 1, 0, 0, 0, 1, 1, 1};
    for (int i = 0; i < 9; i++) {
        outFile << settings[i] << endl;
    }
    
    //closes settings file
    outFile.close();
    
    //allows user to set preferred settings
    editSettings(username);
    
    //
    cout << "Your account has been set up." << endl;
}
