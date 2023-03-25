//
// Created by asus on 4/20/2022.
//

#include "Dulciuri.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

Dulciuri::Dulciuri(){
    this->cod = nullptr;
    this->nume = nullptr;
    this->pret = 0;
}
Dulciuri::Dulciuri(char* cod, char* numeN, int pret){
    int nr = strlen(cod)+1;
    char* aux= new char[strlen(cod)+1];
    this->cod = new char [nr];
    strcpy(this->cod,cod);
    delete []aux;
    nr = strlen(numeN)+1;
    char* aux1 = new char [nr];
    strcpy(aux1, numeN);
    this->nume = new char[nr];
    strcpy_s(this->nume, nr, aux1);
    this->pret = pret;
}
Dulciuri::Dulciuri(const Dulciuri &c) {
    this->cod= new char [strlen(c.cod)+1];
    strcpy(this->cod, c.cod);
    this->pret=c.pret;
    this->nume= new char [strlen(c.nume)+1];
    strcpy(this->nume, c.nume);
}
Dulciuri::~Dulciuri() {
    if(this->nume){
        delete[]nume;
        nume = NULL;}
}

char* Dulciuri::getCod() const {
    return cod;
}
void Dulciuri::setCod(char* cod) {
    if(this->cod)
    {
        delete[] this->cod;
    }
    this->cod= new char [strlen(cod)+1];
    strcpy_s(this->cod, strlen(cod)+1, cod);
}

char *Dulciuri::getNume() const {
    return nume;
}
void Dulciuri::setNume(char *nume) {
    if(this->nume)
    {
        delete[] this->nume;
    }
    this->nume= new char [strlen(nume)+1];
    strcpy_s(this->nume, strlen(nume)+1, nume);

}

int Dulciuri::getPret() const {
    return pret;
}
void Dulciuri::setPret(int pret) {
    Dulciuri::pret = pret;
}

bool Dulciuri::operator==(const Dulciuri &rhs) const {
    return strcmp(cod, rhs.cod)==0 &&
           strcmp(nume, rhs.nume)==0 &&
           pret == rhs.pret;
}
bool Dulciuri::operator!=(const Dulciuri &rhs) const {
    return !(rhs == *this);
}
Dulciuri& Dulciuri::operator=(const Dulciuri& element){
    this->setCod(element.cod);
    this->setNume(element.nume);
    this->setPret(element.pret);
    return *this;
}

char* Dulciuri::toString(){
    int nr = strlen(nume) + 10 + strlen(cod) + 14 + 3 + 1;
    char* s = new char[nr];
    strcpy(s,nume);

    strcat(s," cu codul ");
    strcat(s, this->cod);
    strcat(s," si cu pretul ");
    char* aux2 = new char[4];
    _itoa(pret,aux2,10);
    strcat(s,aux2);
    delete[]aux2;
    return s;
}
char* Dulciuri::toStringForPrezentare(){
    int nr = strlen(nume) + 10 + strlen(cod) + 14 + 3 + 1;
    char* s = new char[nr];
    strcpy(s,nume);
    strcat(s," cu pretul ");
    char* aux2 = new char[4];
    _itoa(pret,aux2,10);
    strcat(s,aux2);
    delete[]aux2;
    return s;
}

istream& operator>>(istream& is, Dulciuri& d){
    cout<<"Dati codul: ";
    char * cod= new char [10];
    is>>cod;
    cout<<"Dati numele: ";
    char * nume= new char [15];
    is>>nume;
    cout<<"Dati pretul: ";
    int pret;
    is>>pret;
    d.setNume(nume);
    d.setCod(cod);
    d.setPret(pret);
    delete[]cod;
    delete[]nume;
    return is;
}
ostream& operator<<(ostream& os, Dulciuri& d){
    //os <<"|"<< left<<setw(10)<< setfill(' ')<< d.cod << "|" << setw(15) << d.nume <<"|"<< setw(5) <<setfill(' ')<< d.pret<<"|"<<endl;
    os << d.cod << " " << d.nume << " " << d.pret << endl;
    return os;
}

//    char* aux = new char[5];
//    _itoa(cod,aux,10);
//    strcat(s,aux);
//    delete[]aux;