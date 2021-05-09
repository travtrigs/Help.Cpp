#include "createDirectories.h"

//create directories for new user
void createDirectories(string username) {
    //creates home directory for new user
    string fileName = "/Server/Users/";
    fileName += username;
    mkdir(fileName.c_str(), S_IRWXU);
    
    //creates info directory for new user
    string info  = fileName;
    info += "/Info";
    mkdir(info.c_str(), S_IRWXU);
    
    //creates messages directory for new user
    string messages = fileName;
    messages += "/Messages";
    mkdir(messages.c_str(), S_IRWXU);
    
    //creates read messages directory for new user
    string read = messages;
    read += "/Read";
    mkdir(read.c_str(), S_IRWXU);
    
    //creates unread messages directory for new user
    string unread = messages;
    unread += "/Unread";
    mkdir(unread.c_str(), S_IRWXU);
    
    //creates sent messages directory for new user
    string sent = messages;
    sent += "/Sent";
    mkdir(sent.c_str(), S_IRWXU);
    
    //creates settings directory for new user
    string settings = fileName;
    settings += "/Settings";
    mkdir(settings.c_str(), S_IRWXU);
}