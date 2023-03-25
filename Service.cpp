//
// Created by asus on 4/27/2022.
//

#include "Service.h"
#include <iostream>
using namespace std;

Service::Service(const Repo &reposytory){
    this->reposytory = reposytory;
    money[0][0] = 1;
    money[1][0] = 5;
    money[2][0] = 10;
    money[3][0] = 50;
    money[0][1] = 30;
    money[1][1] = 10;
    money[2][1] = 8;
    money[3][1] = 2;

}
Service::Service() {
    money[0][0] = 1;
    money[1][0] = 5;
    money[2][0] = 10;
    money[3][0] = 50;
    money[0][1] = 30;
    money[1][1] = 10;
    money[2][1] = 8;
    money[3][1] = 2;

}
Service::~Service(){

}

Service& Service::operator=(const Service& srv){
    this->reposytory=srv.reposytory;
    return *this;
}

void Service::addDulce(char* cod, char* numeN, int pret){
    int ok=0;
    Dulciuri d(cod,numeN,pret);

//    Dulciuri d;
//    d.setCod(cod);
//    d.setNume(numeN);
//    d.setPret(pret);
    this->reposytory.addProduct(d);
}

void Service::updateDulce(char* codV, char* numeV, int pretV, char* codN, char* numeN, int pretN){
    Dulciuri dV(codV,numeV,pretV);
    Dulciuri dN(codN,numeN,pretN);
    this->reposytory.updateDulce(dV, dN);
}

void Service::remove(char* cod, char* nume, int pret){
    Dulciuri d(cod,nume,pret);
    this->reposytory.deleteDulce(d);
}

Dulciuri& Service::getDulceFromPoz(int pozitie){
    return this->reposytory.getDulceFromPos(pozitie);
}

int Service::getPozFromDulce(char* cod, char* nume, int pret){
    Dulciuri d(cod,nume,pret);
    return this->reposytory.getPozFromDulce(d);
}

int Service::getSize(){
    return reposytory.getSize();
}

void Service::getAllDulciuriString(){
    //vector<Dulciuri>lista = this->reposytory.getAll().getListaDulciuri();
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    for(int i=0;i<lista.size();i++){
        cout<<i+1<<". "<<lista[i].toString()<<"; "<<endl;
    }
}

void Service::getAllDulciuriStringForPrezentare(){
    //vector<Dulciuri>lista = this->reposytory.getAll().getListaDulciuri();
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    for(int i=0;i<lista.size();i++){
        cout<<lista[i].getCod()<<" -> "<<lista[i].toStringForPrezentare()<<"; "<<endl;
    }
}

vector<Dulciuri> Service::getAllDulce(){
    return this->reposytory.getListaDulciuri();
}

bool Service::valideazaPozitie(int poz){
    if(poz<0 || poz>= this->getSize())return false;
    return true;
}

//verifica dace elementul exista
bool Service::valideazaElement(char* cod, char* nume, int pret){
    Dulciuri d(cod, nume, pret);
    for(int i=0;i< this->getSize();i++){
        if(this->getAllDulce()[i]==d)return true;
    }
    return false;
}

void Service::incarcaDulciurile(vector<Dulciuri> lista){
    this->reposytory.setListaDulciuri(lista);
}

void Service::produseLessThanSum(int suma){
    bool gasit = false;
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    for(int i=0;i<lista.size();i++){
        if(lista[i].getPret()<=suma){
            cout<<lista[i].getCod()<<" -> "<<lista[i].toStringForPrezentare()<<"; "<<endl;
            gasit = true;
        }
    }
    if(!gasit)cout<<"Nu exista produse pe care poti sa le cumperi cu suma data!"<<endl;
}

void Service::getBancnoteAcceptate(){
    cout<<"Bancnote acceptate: ";
    for(int i=0;i<=3;i++)
        if(money[i][1]!=0)cout<<money[i][0]<<" ";
    cout<<endl;
}

bool Service::canIGetRest(int rest){
    int calculareRest = 0;
    for(int i=3;i>=0;i--){
        ///MAI EFICIENT
        int nrBancnote = money[i][1];
        while (calculareRest<rest && nrBancnote>0){
            calculareRest = calculareRest + money[i][0];
            nrBancnote--;
        }
        if(calculareRest>rest)calculareRest = calculareRest - money[i][0];
        if(calculareRest == rest)return true;
    }
    return false;
}

void Service::cumparare(string cod, int suma){
    int rest[4][2], i=0, sumaRest;
    bool isRest = true;
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    while (i<lista.size()){
        if(lista[i].getCod()==cod) {
            if(lista[i].getPret() == suma)isRest = false;
            else {
                sumaRest = suma - lista[i].getPret();
                for (int j = 3; j >= 0; j--) {
                    rest[j][0] = money[j][0];
                    int nrBancnote = money[j][1], k = 0;
                    while (k <= nrBancnote) {
                        if (money[j][0] * k <= sumaRest){rest[j][1] = k;money[j][1]--;}
                        k++;
                    }
                    sumaRest = sumaRest - (money[j][0] * rest[j][1]);
                }
                break;
            }
        }
        i++;
    }
    if(isRest){
        cout<<"Restul dumneavoastra este in valoare de "<<suma - lista[i].getPret() - sumaRest<<" ron, iar bancnotele primite ca rest: "<<endl;
        for(int i =0 ;i<=3;i++){
            if(rest[i][1]!=0) cout<<rest[i][0]<<" lei->"<<rest[i][1]<<" bancnote"<<endl;
        }
        cout<<"VA MULTUMIM!";
    }
    if(!isRest)cout<<"Restul dumneavoastra este in valoare de 0 lei. VA MULTUMIM!";
}

bool Service::sumaSuficientaCumparareProdus(string cod, int suma){
    int i = 0;
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    while (lista[i].getCod()!=cod){
        i++;
    }
    if(lista[i].getPret() > suma)return false;
    return true;
}

bool Service::codValid(string cod){
    int i = 0;
    vector<Dulciuri>lista = this->reposytory.getListaDulciuri();
    while (i<lista.size()){
        if(lista[i].getCod()==cod)
            return true;
        i++;
    }
    return false;
}

bool Service::bancnotaAcceptata(int suma){
    for(int i=0;i<=3;i++)
        if(money[i][0]==suma)return true;
    return false;
}

void Service::incarcaBani(vector<int> listaBancnote){
    for(int i=0;i<listaBancnote.size();i++)
        for(int j=0;j<=3;j++)
            if(money[j][0]== listaBancnote[i])money[j][1]++;
}
