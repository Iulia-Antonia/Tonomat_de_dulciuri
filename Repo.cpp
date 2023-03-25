//
// Created by asus on 4/20/2022.
//

#include "Repo.h"
#include <iostream>
using namespace std;

Repo::Repo(){
    this->noDulciuri = 0;
}

Repo::Repo(std::vector<Dulciuri> listaDulciuri, int noDulciuri){
    this->listaDulciuri = listaDulciuri;
    this->noDulciuri = noDulciuri;
}

Repo::Repo(const Repo &rep){
    this->listaDulciuri=rep.listaDulciuri;
    this->noDulciuri=rep.noDulciuri;
}

Repo::~Repo() {

}

const std::vector<Dulciuri> &Repo::getListaDulciuri() const {
    return listaDulciuri;
}

void Repo::setListaDulciuri(const std::vector<Dulciuri> &listaDulciuri) {
    this->listaDulciuri = listaDulciuri;
    this->noDulciuri = listaDulciuri.size();
}

int Repo::getNoDulciuri() const {
    return noDulciuri;
}

bool Repo::operator==(const Repo &rhs) const {
    return listaDulciuri == rhs.listaDulciuri &&
           noDulciuri == rhs.noDulciuri;
}

bool Repo::operator!=(const Repo &rhs) const {
    return !(rhs == *this);
}

Repo& Repo::operator=(const Repo& element){
    this->setListaDulciuri(element.listaDulciuri);
    this->noDulciuri = element.noDulciuri;
    return *this;
}

void Repo::addProduct(const Dulciuri& element){
    this->listaDulciuri.push_back(element);
    this->noDulciuri++;
}

Repo Repo::getAll(){
    return *this;
}

Dulciuri& Repo::getDulceFromPos(int pozitie){
    return this->listaDulciuri[pozitie];
}

int Repo::getPozFromDulce(const Dulciuri& element){
    for(int i=0;i<noDulciuri;i++){
        if(this->listaDulciuri[i] == element)return i;
    }
    return -1;
}

void Repo::updateDulce( Dulciuri& dulceVechi, Dulciuri& dulceNou){
//    if(this->getPozFromDulce(dulceVechi) == -1)cout<<"Produsul pe care doresti sa il modifici nu exista in lista! L-am adaugat la sfarsit!";
//    else{
//        int pozVechi = this->getPozFromDulce(dulceVechi);
//        listaDulciuri[pozVechi] = dulceNou;
//    }
    if(this->getPozFromDulce(dulceVechi) != -1){
        int pozVechi = this->getPozFromDulce(dulceVechi);
        listaDulciuri[pozVechi] = dulceNou;
    }
//    int pozVechi = this->getPozFromDulce(dulceVechi);
//    listaDulciuri[pozVechi] = dulceNou;
}
void Repo::deleteDulce(Dulciuri& element){
    int pozToDelete = this->getPozFromDulce(element);
    if(pozToDelete!=-1){
        vector<Dulciuri> listaNoua;
        for(int i=0;i<noDulciuri;i++)
            if (i!=pozToDelete)
            listaNoua.push_back(this->listaDulciuri[i]);
        noDulciuri--;
        listaDulciuri = listaNoua;
    }
}

int Repo::getSize() const{
    return noDulciuri;
}
