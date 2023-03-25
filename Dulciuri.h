//
// Created by asus on 4/20/2022.
//

#ifndef LABORATOR_9_10_DULCIURI_H
#define LABORATOR_9_10_DULCIURI_H
#include <iostream>
#include <fstream>
using namespace std;

enum productsType{
    Croissant = 0,
    Ciocolata = 1,
    Cola = 2,
    FantaPortocale = 3,
    Sprite = 4,
    Cappy = 5,
    Lays = 6,
    Chio = 7,
    Tuc = 8,
    Apa = 9
};


class Dulciuri {
private:
    char* cod;
    char* nume;
    int pret;//maxim 3 cifre
public:
    Dulciuri();
    Dulciuri(char* cod, char* nume, int pret);
    Dulciuri(const Dulciuri &c);
    virtual ~Dulciuri();

    char* getCod() const;
    void setCod(char* cod);

    int getPret() const;
    void setPret(int pret);

    char *getNume() const;
    void setNume(char *nume);

    bool operator==(const Dulciuri &rhs) const;
    bool operator!=(const Dulciuri &rhs) const;
    Dulciuri& operator=(const Dulciuri& element);

    char* toString();
    char* toStringForPrezentare();
    friend istream& operator>>(istream& is, Dulciuri& d);
    friend ostream& operator<<(ostream& os, Dulciuri& d);
};


#endif //LABORATOR_9_10_DULCIURI_H
