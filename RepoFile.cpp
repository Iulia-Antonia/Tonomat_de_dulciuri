//
// Created by asus on 5/4/2022.
//

#include <cstring>
#include "RepoFile.h"
#include "Dulciuri.h"
#include <iostream>
using namespace std;

RepoFile::RepoFile(char *fileName){
    if(fileName!=NULL){
        this->fileName = new char [strlen(fileName)+1];
        strcpy(this->fileName, fileName);
    }
    else{
        this->fileName=NULL;
    }
    if (this->fileName)
    {
        ifstream f(this->fileName);
        string linie;
        char nume[15], cod[10];
        int pret;
        while (!f.eof())
        {
            f >> cod;
            f >> nume;
            f >> pret;
            if (strlen(nume) > 0 && strlen(cod)>0)
            {
                Dulciuri d(cod, nume, pret);
                listaDulciuri.push_back(d);
                noDulciuri++;
//                this->addProduct(d);
            }
        }
        f.close();
    }
}

RepoFile::RepoFile(){
    fileName = NULL;
}
RepoFile::~RepoFile(){
    if(fileName){
        delete []fileName;
        fileName = NULL;
    }
}
vector<Dulciuri> RepoFile::getAll(){
    return this->listaDulciuri;
}
int RepoFile::getLenght(){
    return this->noDulciuri;
}
void RepoFile::addProduct(const Dulciuri& d){
    this->addProduct(d);
    this->saveToFile();
}
void RepoFile::updateDulce(const Dulciuri& oldD, const Dulciuri& newD){
    this->updateDulce(oldD,newD);
    this->saveToFile();
}
void RepoFile::deleteDulce(const Dulciuri& d){
    this->deleteDulce(d);
    this->saveToFile();
}
void RepoFile::loadFromFile(){
    if (this->fileName)
    {
        ifstream f(this->fileName);
        char nume[20], cod[10];
        int pret;
        while (!f.eof())
        {
            f >> cod;
            f >> nume;
            f >> pret;
            if (strlen(nume) > 0 && strlen(cod)>0)
            {
                Dulciuri d(cod, nume, pret);
                this->addProduct(d);
            }
        }
        f.close();
    }
}
void RepoFile::saveToFile(){
    if (this->fileName)
    {
        ofstream f(this->fileName);
        for (int i = 0; i < noDulciuri;i++)
        {
            f << listaDulciuri[i] << endl;
        }
        f.close();
    }
}