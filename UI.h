//
// Created by asus on 4/27/2022.
//

#ifndef LABORATOR_9_10_UI_H
#define LABORATOR_9_10_UI_H
#include "Service.h"
#include "Validator.h"


class UI {
private:
    Service service;
    Validator validator;
public:
    UI();
    UI(Service &service);
    virtual ~UI();
    void runMenu();

private:
    void addElem(string cod, string nume, string pret);
    void updateDulce(string codV, string numeV, string pretV, string codN, string numeN, string pretN);
    void remove(string cod, string nume, string pret);
    void showAll();
    void showProduseClient();
    static void citireElem(string &cod, string &nume, string &pret, bool &ok);
    void produseLessThanSum(string suma);
    void canIGetRest(string rest);
    void bancnoteAcceptate();
    void cumparare();
};


#endif //LABORATOR_9_10_UI_H
