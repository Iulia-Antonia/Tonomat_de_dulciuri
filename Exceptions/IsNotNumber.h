//
// Created by asus on 5/24/2022.
//

#ifndef LABORATOR_9_10_ISNOTNUMBER_H
#define LABORATOR_9_10_ISNOTNUMBER_H
#pragma once
#include <exception>
#include <cstring>
#include <string>
using namespace std;

class IsNotNumber: public exception{
private:
    const char * message;
public:
    const char* what() const throw(){
        string msg = "Numarul de bamcnote trebuie sa fie un numar intreg!";

        char* msg_c = new char[msg.length()+1];
        strcpy_s(msg_c, msg.length() + 1, msg.c_str());

        const char* res = const_cast<char*>(msg_c);

        return res;
    }
};
#endif //LABORATOR_9_10_ISNOTNUMBER_H
