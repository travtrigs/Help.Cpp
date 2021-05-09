#include "signIn.h"

//sign in user
void signIn(string username) {
    
    //opens users info file
    string fileName = "/Users/";
    fileName += username;
    fileName += "/Info/info.txt";
    ifstream inFile;
    inFile.open(fileName);
    
    //gets password from user
    string password;
    cout << "Password: ";
    cin >> password;
    
    //gets password from file
    string check;
    getline(inFile,check);
    
    //check password
    while ((password != check) || (!inFile.is_open())) {
        cout << "Username or password is incorrect." << endl;
        inFile.close();
        
        //gets username
        cout << "Username: ";
        cin >> username;
        
        //opens users info file
        fileName = "Users/";
        fileName += username;
        fileName += "/Info/info.txt";
        inFile.open(fileName);
        
        //gets password from user
        cout << "Password: ";
        cin >> password;
        
        //gets password from file
        getline(inFile,check);
    }
    
    //closes users info file
    inFile.close();
}
