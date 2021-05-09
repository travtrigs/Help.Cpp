#ifndef classes_h
#define classes_h

#include <iostream>
#include <fstream>
#include <vector>
#include "checkInput.h"

class User {
    std::string n, f, i, s, p, m;
    
public:
    void set(std::string);
    std::string name() {return n;}
    std::string folder() {return f;}
    std::string info() {return i;}
    std::string settings() {return s;}
    std::string profile() {return p;}
    std::string messages() {return m;}
    
};

class Time {
    int m, d, y, hr, min, sec, e;
    std::string str_T, str_D, str_TD;
    time_t t;
    
public:
    void getTime();
    int month() {return m+1;}
    int day() {return d;}
    int year() {return y+1900;}
    int hour() {return hr;}
    int minute() {return min;}
    int second() {return sec;}
    int elapsed() {return e;}
    std::string strTime() {return str_T;}
    std::string strDate() {return str_D;}
    std::string str() {return str_TD;}
};


#endif
