//
// Created by asus on 4/27/2022.
//

#ifndef LABORATOR_9_10_SERVICE_H
#define LABORATOR_9_10_SERVICE_H
#include "Repo.h"
#include "RepoFile.h"
#include "Dulciuri.h"
#include "Validator.h"


class Service {
private:
    Repo reposytory;
    int money[4][2];
public:
    Service();
    Service(const Repo &reposytory);


    ~Service();
    Service& operator=(const Service& srv);

    void addDulce(char* cod, char* nume, int pret);
    void updateDulce(char* codV, char* numeV, int pretV, char* codN, char* numeN, int pretN);
    void remove(char* cod, char* nume, int pret);
    Dulciuri& getDulceFromPoz(int);
    int getPozFromDulce(char* cod, char* nume, int pret);
    int getSize();
    vector<Dulciuri> getAllDulce();
    void getAllDulciuriString();
    void getAllDulciuriStringForPrezentare();
    bool valideazaPozitie(int poz);
    bool valideazaElement(char* cod, char* nume, int pret);
    void incarcaDulciurile(vector<Dulciuri> lista);
    void produseLessThanSum(int suma);
    void getBancnoteAcceptate();
    bool canIGetRest(int rest);
    void cumparare(string cod, int suma);
    bool sumaSuficientaCumparareProdus(string cod, int suma);
    bool codValid(string cod);
    bool bancnotaAcceptata(int suma);
    void incarcaBani(vector<int> listaBancnote);
};


#endif //LABORATOR_9_10_SERVICE_H
