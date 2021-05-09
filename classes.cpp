#include "classes.h"

void User::set(std::string name) {
    n = name;
    f = "/Server/Users/" + name + "/";
    i = f + "info.txt";
    s = f + "settings.txt";
    p = f + "profile.txt";
    m = f + "messages.txt";
}

void Time::getTime() {
    t = time(0);
    struct tm * now = localtime( & t );
    m = (now->tm_mon);
    d = (now->tm_mday);
    y = (now->tm_year);
    hr = (now->tm_hour);
    min= (now->tm_min);
    sec = (now->tm_sec);
    e = (now->tm_yday);
    
    e += 365 * (y - 115);
    if ((y - 116) % 4 == 0) {
        e += ((y - 116) / 4);
    }
    e *= 24 * 60 * 60;
    e += hr * 60 * 60;
    e += min * 60;
    e += sec;
    
    str_T = std::to_string(hour()) + ":" + std::to_string(minute()) + ":" + std::to_string(second());
    str_D = std::to_string(month()) + "/" + std::to_string(day()) + "/" + std::to_string(year());
    str_TD = str_T + "    " + str_D;
}
