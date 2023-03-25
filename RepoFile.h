//
// Created by asus on 5/4/2022.
//

#ifndef LABORATOR_9_10_REPOFILE_H
#define LABORATOR_9_10_REPOFILE_H
#include "Repo.h"
#include <fstream>


class RepoFile: public Repo{
private:
    char* fileName;
public:
    RepoFile();
    RepoFile(char *fileName);
    ~RepoFile();
    vector<Dulciuri> getAll();
    int getLenght();
    void addProduct(const Dulciuri& d);
    void updateDulce(const Dulciuri& oldD, const Dulciuri& newD);
    void deleteDulce(const Dulciuri& d);
private:
    void loadFromFile();
    void saveToFile();
};


#endif //LABORATOR_9_10_REPOFILE_H
