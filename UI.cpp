//
// Created by asus on 4/27/2022.
//

#include "UI.h"
#include <iostream>
#include "FunctiiAjutatoare.h"
#include <cstring>
#include "Validator.h"
#include "Exceptions/CantConvertToInt.h"
#include "Exceptions/DuplicateCode.h"
#include "Exceptions/EmptyCode.h"
#include "Exceptions/EmptyName.h"
#include "Unutils/NegativePrice.h"
#include "Exceptions/ProductNotExist.h"
#include "Exceptions/InsufficientMoney.h"
using namespace std;
UI::UI() {}



UI::~UI() {

}

void showMenuAdministrator(){
    cout<<endl<<"OBTIUNI PENTRU ADMINISTRATOR:"<<endl;
    cout<<"adauga - adauga un produs in lista"<<endl;
    cout<<"modifica - modifica un produs in lista"<<endl;
    cout<<"sterge - sterge un produs din lista"<<endl;
    cout<<"afiseaza - afiseaza lista cu produsele existente"<<endl;
    cout<<"x - iesire"<<endl;
    cout<<"Obtiunea aleasa: ";
}

void showMenuUser(){
    cout<<endl<<"OBTIUNI:"<<endl;
    cout<<endl<<"1. Vezi lista de produse";
    cout<<endl<<"2. Vezi ce produse au pretul mai mic sau egal cu o suma data";
    cout<<endl<<"3. Pot primi rest n RON (tonomatul dispune de aceasta suma)?";
    cout<<endl<<"4. Cumparare";
    cout<<endl<<"x - iesire"<<endl;
    cout<<"Obtiunea aleasa: ";
}

void UI::runMenu(){
    string userChoice;
 //   char* cod = new char[10]; char* nume = new char[15]; int pret;

 string cod, nume, pret;
    service.incarcaDulciurile(service.getAllDulce());
    bool go = true, ok = true, personVerification = true;//ok - pentru validarea citirii
    while (personVerification) {
        string persoana, continuare;
        cout<<"administrator/user: ";cin>>persoana;
        if (persoana == "administrator") {
            go= true;
            while (go) {
                showMenuAdministrator();
                cin >> userChoice;

                if (userChoice == "adauga") {
                    ok = true;
                    UI::citireElem(cod, nume, pret, ok);
                    if (ok) { UI::addElem(cod, nume, pret); }
                    continue;
                }
                if (userChoice == "modifica") {
//                    char *codN = new char[10];
//                    char *codV = new char[10];
//                    char *numeN = new char[15];
//                    char *numeV = new char[10];
//                    int pretV, pretN;
                    string codV, numeV, pretV,codN, numeN, pretN;
                    ok = true;
                    cout << "Elementul pe care doriti sa il modificati (cel vechi):" << endl;
                    UI::citireElem(codV, numeV, pretV, ok);
                    if (ok) {
                        cout << "Elementul nou:";
                        UI::citireElem(codN, numeN, pretN, ok);
                    }
                    if (ok) { UI::updateDulce(codV, numeV, pretV, codN, numeN, pretN); }
                    continue;
                }
                if (userChoice == "sterge") {
                    ok = true;
                    UI::citireElem(cod, nume, pret, ok);
                    if (ok) { UI::remove(cod, nume, pret); }
                    continue;
                }
                if (userChoice == "afiseaza") {
                    UI::showAll();
                    continue;
                }
                if (userChoice == "x") {
                    go = false;
                    continue;
                }
                cout << "Obtiune invalida! Mai incearca!" << endl;

            }
            cout << "Doriti sa continuati? (da/nu): ";
            cin >> continuare;
            if (continuare != "da")personVerification = false;
            else personVerification = true;
            continue;
        }
        if (persoana == "user") {
            go= true;
            while (go) {
                showMenuUser();
                cin >> userChoice;

                if (userChoice == "1") {
                    UI::showProduseClient();
                    continue;
                }
                if(userChoice == "2"){
                    string suma;
                    cout<<"Dati suma: ";
                    cin>>suma;
                    UI::produseLessThanSum(suma);
                    continue;
                }
                if(userChoice == "3"){
                    string rest;
                    cout<<"n(rest)=";cin>>rest;
                    UI::canIGetRest(rest);
                    continue;
                }
                if(userChoice == "4"){
                    UI::cumparare();
                    continue;
                }
                if (userChoice == "x") {
                    go = false;
                    continue;
                }
                cout << "Obtiune invalida! Mai incearca!" << endl;

            }
            cout<<"Doriti sa continuati? (da/nu): ";cin>>continuare;
            if(continuare != "da")personVerification = false;
            else personVerification = true;
            continue;
        }
        personVerification = true;
        cout << "Obtiunile valabile sunt doar administrator sau user! Mai incercati!" << endl;
    }
}

void UI::addElem(string cod, string nume, string pret){
    try{
        this->validator.validatorDuplicateCode(cod, service.getAllDulce());
        this->validator.validatorEmptyCode(cod);
        this->validator.validatorEmptyName(nume);
        this->validator.validatorConvertToInt(pret);
        this->validator.validatorNegativePrice(pret);
        this->service.addDulce(const_cast<char *>(cod.c_str()), const_cast<char *>(nume.c_str()), stoi(pret));
        cout<<"Element adaugat cu succes!"<<endl;
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (DuplicateCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyName &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (NegativePrice &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (ProductNotExist &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void UI::updateDulce(string codV, string numeV, string pretV, string codN, string numeN, string pretN){
    try{
        this->validator.validatorConvertToInt(pretV);
        this->validator.validatorNegativePrice(pretV);
        this->validator.validatorConvertToInt(pretN);
        this->validator.validatorNegativePrice(pretN);
        this->validator.validatorDuplicateCode(codN, service.getAllDulce());
        this->validator.validatorEmptyCode(codV);
        this->validator.validatorEmptyCode(codN);
        this->validator.validatorEmptyName(numeV);
        this->validator.validatorEmptyName(numeN);
        this->validator.validatorProductNotExist(codV,numeV,stoi(pretV),service.getAllDulce());
        this->service.updateDulce(const_cast<char *>(codV.c_str()), const_cast<char *>(numeV.c_str()), stoi(pretV),
                                  const_cast<char *>(codN.c_str()), const_cast<char *>(numeN.c_str()), stoi(pretN));
        cout<<"Element modificat cu succes!"<<endl;
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (DuplicateCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyName &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (NegativePrice &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (ProductNotExist &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void UI::remove(string cod, string nume, string pret){
    try {
        this->validator.validatorConvertToInt(pret);
        this->validator.validatorNegativePrice(pret);
        this->validator.validatorEmptyCode(cod);
        this->validator.validatorEmptyName(nume);
        this->validator.validatorProductNotExist(cod,nume, stoi(pret),service.getAllDulce());
        this->service.remove(const_cast<char *>(cod.c_str()), const_cast<char *>(nume.c_str()), stoi(pret));
        cout<<"Elementul a fost sters cu succes!"<<endl;
    }
    catch (ProductNotExist &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (DuplicateCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (NegativePrice &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyName &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void UI::showAll(){
    this->service.getAllDulciuriString();
}

void UI::showProduseClient(){
    this->service.getAllDulciuriStringForPrezentare();
}

void UI::citireElem(string &cod, string &nume, string &pret, bool &ok) {
    string  pretS, codS, numeS;
    cout<<"Dati codul produsului: ";cin>>cod;
    cout<<"Dati numele produsului: ";cin>>nume;
    cout<<"Dati pretul produsului: ";cin>>pret;
}

void UI::produseLessThanSum(string suma){
    try {
        validator.validatorNegativePrice(suma);
        validator.validatorConvertToInt(suma);
        service.produseLessThanSum(stoi(suma));
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (NegativePrice &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void UI::bancnoteAcceptate(){
    service.getBancnoteAcceptate();
}

void UI::canIGetRest(string rest){
    try {
        validator.validatorNegativePrice(rest);
        validator.validatorConvertToInt(rest);
        if (service.canIGetRest(stoi(rest)) == true)cout << "Da, poti primi rest!" << endl;
        else cout << "Nu poti primi rest intreg!" << endl;
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (NegativePrice &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

void UI::cumparare(){
    try {
        string cod;
        int suma = 0;
        cout << "Dati codul produsului pe care doriti sa il cumparati: ";
        cin >> cod;
        validator.validatorEmptyCode(cod);
        validator.validatorInvalidCode(cod,service.getAllDulce());
        service.getBancnoteAcceptate();
        cout << "Dati numarul de bancnote pe care doriti sa le introduceti: ";
        string nrBancnote_s, bancnota_s;
        int nrBancnote, bancnota;
        vector<int> listaBancnote;
        cin >> nrBancnote_s;
        validator.validatorIsNotNumber(nrBancnote_s);
        nrBancnote = stoi(nrBancnote_s);
        suma = 0;
        for (int i = 0; i < nrBancnote; i++) {
            cout << "Dati urmatoarea bancnota: ";
            cin >> bancnota_s;
            validator.validatorConvertToInt(bancnota_s);
            bancnota = stoi(bancnota_s);
            if (service.bancnotaAcceptata(bancnota)) {
                listaBancnote.push_back(bancnota);
                suma = suma + bancnota;
            }
            else {
                cout << "Bancnota neacceptata! Introduceti alta in locul ei!";
                i--;
            }
        }
        int i = 0;
        vector<Dulciuri>lista = this->service.getAllDulce();
        while (lista[i].getCod()!=cod){
            i++;
        }
        validator.validatorIntroduceInsufficientMoney(suma, lista[i].getPret());
        service.incarcaBani(listaBancnote);
        service.cumparare(cod, suma);
    }
    catch (ProductNotExist &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (InvalidCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (DuplicateCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (EmptyCode &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (InsufficientMoney &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (CantConverToInt &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (IsNotNumber &e){
        cout<<"Exceptie: "<<e.what();
    }
    catch (...){
        cout<<"Eroare!";
    }
}

UI::UI(Service &service) {
    this->service = service;
}
