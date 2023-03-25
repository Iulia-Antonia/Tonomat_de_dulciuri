//
// Created by asus on 5/17/2022.
//

#ifndef LABORATOR_9_10_DUPLICATECODE_H
#define LABORATOR_9_10_DUPLICATECODE_H
#pragma once
#include <exception>
#include <cstring>
#include <string>
using namespace std;

class DuplicateCode: public exception{
private:
    const char * message;
public:
    const char* what() const throw(){
        string msg = "Codul pe care l-ati dat exista deja! Codul trebuie sa fie unic!";

        char* msg_c = new char[msg.length()+1];
        strcpy_s(msg_c, msg.length() + 1, msg.c_str());

        const char* res = const_cast<char*>(msg_c);

        return res;
    }
};
#endif //LABORATOR_9_10_DUPLICATECODE_H
