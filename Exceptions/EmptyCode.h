//
// Created by asus on 5/17/2022.
//

#ifndef LABORATOR_9_10_EMPTYCODE_H
#define LABORATOR_9_10_EMPTYCODE_H
#pragma once
#include <exception>
#include <cstring>
#include <string>
using namespace std;

class EmptyCode: public exception{
private:
    const char * message;
public:
    const char* what() const throw(){
        string msg = "codul nu poate fi gol!";

        char* msg_c = new char[msg.length()+1];
        strcpy_s(msg_c, msg.length() + 1, msg.c_str());

        const char* res = const_cast<char*>(msg_c);

        return res;
    }
};
#endif //LABORATOR_9_10_EMPTYCODE_H
