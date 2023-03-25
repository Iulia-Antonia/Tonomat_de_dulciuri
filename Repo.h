//
// Created by asus on 4/20/2022.
//

#ifndef LABORATOR_9_10_REPO_H
#define LABORATOR_9_10_REPO_H
#include <vector>
#include "Dulciuri.h"
using namespace std;


class Repo {
protected:
    std::vector<Dulciuri> listaDulciuri;
    int noDulciuri;
public:

    Repo();
    Repo(vector<Dulciuri> listaDulciuri, int noDulciuri);
    Repo(const Repo &rep);
    ~Repo();
    bool operator==(const Repo &rhs) const;
    bool operator!=(const Repo &rhs) const;
    int getNoDulciuri() const;
    const vector<Dulciuri> &getListaDulciuri() const;

    void setListaDulciuri(const std::vector<Dulciuri> &listaDulciuri);
    Repo& operator=(const Repo& element);

    void addProduct(const Dulciuri& element);
    Repo getAll();
    Dulciuri& getDulceFromPos(int pozitie);//VALIDARE
    int getPozFromDulce(const Dulciuri& element);
    void updateDulce( Dulciuri& dulceVechi, Dulciuri& dulceNou);//VALIDARE
    void deleteDulce(Dulciuri& element);//VALIDARE
    int getSize() const;
};


#endif //LABORATOR_9_10_REPO_H
