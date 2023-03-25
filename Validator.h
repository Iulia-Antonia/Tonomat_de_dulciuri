//
// Created by asus on 5/17/2022.
//

#ifndef LABORATOR_9_10_VALIDATOR_H
#define LABORATOR_9_10_VALIDATOR_H
#include <cstring>
#include "RepoFile.h"
#include "Dulciuri.h"
#include "Exceptions/CantConvertToInt.h"
#include "Exceptions/DuplicateCode.h"
#include "Exceptions/EmptyCode.h"
#include "Exceptions/EmptyName.h"
#include "Exceptions/NegativePrice.h"
#include "Exceptions/InvalidCode.h"
#include "Exceptions/IsNotNumber.h"
#include "Unutils/NegativePrice.h"
#include "Exceptions/ProductNotExist.h"
#include "Exceptions/InsufficientMoney.h"
#include <vector>
using namespace std;


class Validator {
public:
    Validator(){};
    Validator(const RepoFile repoFile){};
    ~Validator(){};


    bool validatorConvertToInt(string &s){
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        if(!(!s.empty() && it == s.end()))throw CantConverToInt();
        return !s.empty() && it == s.end();
    }

    bool validatorDuplicateCode(string code, vector<Dulciuri> lista){
        for(int i=0;i<lista.size();i++)
            if(strcmp(lista[i].getCod(),code.c_str())==0){
                throw DuplicateCode();
                return true;
            }
        return false;
    }

    bool validatorEmptyCode(string code){
        if(code.empty()){
            throw EmptyCode();
            return true;
        }
        return false;
    }

    bool validatorEmptyName(string name){
        if(name.empty()){
            throw EmptyName();
            return true;
        }
        return false;
    }

    bool validatorIntroduceInsufficientMoney(int sumItrod, int sumNecessary){
        if(sumItrod < sumNecessary){
            throw InsufficientMoney();
            return true;
        }
        return false;
    };

    bool validatorProductNotExist(string code, string name, int price, vector<Dulciuri> lista){
        int ok= false;
        for(int i=0;i<lista.size();i++)
            if(strcmp(lista[i].getCod(),code.c_str())==0 &&
                    strcmp(lista[i].getNume(),name.c_str())==0 &&
                    lista[i].getPret()==price){
                ok = true;
            }
        if(ok == true)return true;
        else {
            throw ProductNotExist();
            return false;
        }
    };

    bool validatorNegativePrice(string price){
        if(stoi(price)<0) {
            throw NegativePrice();
            return true;
        }
        return false;
    }

    bool validatorInvalidCode(string code, vector<Dulciuri> lista){
        int ok= false;
        for(int i=0;i<lista.size();i++)
            if(strcmp(lista[i].getCod(),code.c_str())==0){
                ok = true;
            }
        if(ok == true)return true;
        else {
            throw InvalidCode();
            return false;
        }
    };

    bool validatorIsNotNumber(string &s){
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        if(!(!s.empty() && it == s.end()))throw IsNotNumber();
        return !s.empty() && it == s.end();
    }
};


#endif //LABORATOR_9_10_VALIDATOR_H
