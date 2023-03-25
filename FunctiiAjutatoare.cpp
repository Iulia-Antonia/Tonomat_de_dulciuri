//
// Created by asus on 4/27/2022.
//

#include "FunctiiAjutatoare.h"

#include <string>
using namespace std;


bool isNumber(string &s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}