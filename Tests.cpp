//
// Created by asus on 4/20/2022.
//

#include "Tests.h"
#include "Dulciuri.h"
#include "Repo.h"
#include "Service.h"
#include "assert.h"
#include <cstring>
#include <iostream>
using namespace std;

void testDulciuriConstructorSiGetteri(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);

    assert(strcmp(d1.getCod(),"12")==0);
    assert(strcmp(d2.getCod(), "54")==0);
    assert(strcmp(d1.getNume(), "Apa")==0);
    assert(strcmp(d2.getNume(), "Croissant")==0);
    assert(d1.getPret() == 4);
    assert(d2.getPret() == 6);
}

void testDulciuriSetteri(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    d1.setPret(d2.getPret());
    d1.setNume(d2.getNume());
    d1.setCod(d2.getCod());
    assert(strcmp(d1.getCod(), d2.getCod())==0);
    assert(strcmp(d1.getNume(), d2.getNume())==0);
    assert(d1.getPret() == d2.getPret());
}

void testDulciuriOperatori(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    assert(d1!=d2);
    d2 = d3;
    d4 = d2;
    assert(d2 == d3);
    assert(d4 == d3);
}

void testDulciuri(){
    testDulciuriConstructorSiGetteri();
    testDulciuriSetteri();
    testDulciuriOperatori();
}

void testRepoConstructor(){
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Dulciuri d1("12", "Cappy", 4);
    d1.setNume("Cappy");
    vector<Dulciuri> lista;
    lista.push_back(d1);
    lista.push_back(d2);
    lista.push_back(d3);
    lista.push_back(d4);

    Repo rep, rep1;
    assert(rep.getNoDulciuri() == 0);
    assert(rep.getListaDulciuri().size() == 0);

    rep1 = Repo(lista, 4);
    assert(rep1.getNoDulciuri() == 4);
    assert(rep1.getListaDulciuri().size() == 4);
    assert(rep1.getListaDulciuri()[0] == d1);
}

void testRepoSetteriSiGetteri(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    Repo rep, rep1;
    assert(rep.getNoDulciuri() == 0);
    assert(rep.getListaDulciuri().size() == 0);
    vector<Dulciuri> lista;
    lista.push_back(d1);
    lista.push_back(d2);
    lista.push_back(d3);
    lista.push_back(d4);

    rep.setListaDulciuri(lista);
    assert(rep.getNoDulciuri() == lista.size());
    assert(rep.getListaDulciuri() == lista);

}

void testRepoOperatori(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    vector<Dulciuri> lista;
    lista.push_back(d1);
    lista.push_back(d2);
    lista.push_back(d3);
    lista.push_back(d4);

    Repo rep, rep1;
    rep1 = Repo(lista, 4);
    assert(rep1!=rep);
    assert(rep==rep);
    assert(rep1==rep1);
    rep = rep1;
    assert(rep == rep1);
}

void testRepoAdd(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    vector<Dulciuri> lista;
    lista.push_back(d1);
    lista.push_back(d2);

    Repo rep;
    rep.addProduct(d1);
    rep.addProduct(d2);
    assert(rep.getNoDulciuri() == 2);
    assert(rep.getListaDulciuri() == lista);
}

void testRepoGetAll(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    Repo rep, rep1;
    rep.addProduct(d1);
    rep.addProduct(d2);
    rep.addProduct(d3);
    rep.addProduct(d4);

    rep1 = rep.getAll();
    assert(rep.getNoDulciuri() == rep1.getNoDulciuri());
    assert(rep.getListaDulciuri() == rep1.getListaDulciuri());
    assert(rep == rep1);
}

void testRepoRead(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    Repo rep;
    rep.addProduct(d1);
    rep.addProduct(d2);
    rep.addProduct(d3);
    assert(rep.getPozFromDulce(d1)==0);
    assert(rep.getPozFromDulce(d4)==-1);
    assert(rep.getDulceFromPos(1)==d2);
    assert(rep.getDulceFromPos(2)!=d2);
}

void testRepoUpdate(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    Repo rep, rep1;
    rep.addProduct(d1);
    rep.addProduct(d2);
    rep.addProduct(d3);
    rep.updateDulce(d1,d4);
    assert(rep.getDulceFromPos(0)==d4);
    rep.updateDulce(d1,d4);
    assert(rep.getDulceFromPos(0)==d4);
}

void testRepoDelete(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);

    Repo rep;
    rep.addProduct(d1);
    rep.addProduct(d2);
    rep.addProduct(d3);
    rep.addProduct(d4);
    assert(rep.getNoDulciuri() == 4);
    rep.deleteDulce(d3);
    assert(rep.getNoDulciuri() == 3);
    assert(rep.getDulceFromPos(2) == d4);
    assert(rep.getDulceFromPos(1) == d2);
}

void testRepo(){
    testRepoConstructor();
    testRepoSetteriSiGetteri();
    testRepoOperatori();
    testRepoAdd();
    testRepoGetAll();
    testRepoRead();
    testRepoUpdate();
    testRepoDelete();
}

void testServiceRead(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("21", "Lays", 10);
    assert(service.getDulceFromPoz(0)==d1);
    assert(service.getDulceFromPoz(1)==d2);
    assert(service.getPozFromDulce("21", "Lays", 10)==2);
    assert(service.getDulceFromPoz(3)==d3);
    assert(service.getPozFromDulce("98", "Cola", 5)==-1);
}

void testServiceAdd(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    assert(service.getSize()==0);
    service.addDulce("12", "Cappy", 4);
    service.addDulce("54", "Croissant", 6);
    assert(service.getSize()==2);
    assert(service.getDulceFromPoz(1)==d2);
    assert(service.getDulceFromPoz(0)==d1);
    assert(service.getAllDulce().size()==2);
}

void testServiceUpdateDulce(){
    Dulciuri d1("12", "Cappy", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.updateDulce("21", "Lays", 10, "98", "Cola", 5);
    assert(service.getDulceFromPoz(2)==d4);
    service.updateDulce("12", "Apa", 4, "54", "Croissant", 6);
    assert(service.getDulceFromPoz(0)==d2);
    assert(service.getDulceFromPoz(1)==d2);
    service.updateDulce("54", "Croissant", 6, "12", "Cappy", 4);
    assert(service.getDulceFromPoz(0)==d1);
    assert(service.getDulceFromPoz(1)==d2);
}

void testServiceRemove(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    assert(service.getSize()==3);
    service.remove("54", "Croissant", 6);
    assert(service.getSize()==2);
    assert(service.getDulceFromPoz(0)==d1);
    assert(service.getDulceFromPoz(1)==d3);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("54", "Croissant", 6);
    assert(service.getSize()==5);
    service.remove("54", "Croissant", 6);
    assert(service.getSize()==4);
    assert(service.getDulceFromPoz(2)==d3);
    assert(service.getDulceFromPoz(3)==d2);
}

void testServiceValidatori(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("21", "Lays", 10);
    assert(service.valideazaPozitie(1));
    assert(!service.valideazaPozitie(4));
    assert(!service.valideazaPozitie(-1));
    assert(service.valideazaElement("12", "Apa", 4));
    assert(service.valideazaElement("21", "Lays", 10));
    assert(!service.valideazaElement("98", "Cola", 5));
}

void testServiceCanIGetRest(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("21", "Lays", 10);
    assert(service.canIGetRest(10));
    assert(service.canIGetRest(200));
    assert(!service.canIGetRest(1000));

//    service.cumparare("21", 100);
}

void testServiceSumaSuficientaCumparareProdus(){
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("21", "Lays", 10);

    assert(service.sumaSuficientaCumparareProdus("12",5));
    assert(!service.sumaSuficientaCumparareProdus("12",3));
    assert(!service.sumaSuficientaCumparareProdus("21",5));
    assert(service.sumaSuficientaCumparareProdus("54",20));
}

void testServiceCodValid() {
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
    service.addDulce("21", "Lays", 10);

    assert(service.codValid("12"));
    assert(service.codValid("21"));
    assert(!service.codValid("122"));
}

void testServiceBancnotaAcceptata() {
    Dulciuri d1("12", "Apa", 4);
    Dulciuri d2("54", "Croissant", 6);
    Dulciuri d3("21", "Lays", 10);
    Dulciuri d4("98", "Cola", 5);
    Repo rep;
    Service service(rep);
    service.addDulce("12", "Apa", 4);
    service.addDulce("54", "Croissant", 6);
    service.addDulce("21", "Lays", 10);
//    service.addDulce("22", "Chio", 10);

    assert(service.bancnotaAcceptata(1));
    assert(service.bancnotaAcceptata(5));
    assert(service.bancnotaAcceptata(10));
    assert(service.bancnotaAcceptata(50));
    assert(!service.bancnotaAcceptata(-5));
    assert(!service.bancnotaAcceptata(0));
    assert(!service.bancnotaAcceptata(4));
}

void testService(){
    testServiceAdd();
    testServiceUpdateDulce();
    testServiceRemove();
    testServiceRead();
    testServiceValidatori();
    testServiceCanIGetRest();
    testServiceSumaSuficientaCumparareProdus();
    testServiceCodValid();
    testServiceBancnotaAcceptata();
}

void testValidatorConvertToIntEmpty(){
    Validator validator;
    string nr1="";
    try{
        validator.validatorConvertToInt(nr1);
        assert(false);
    }
    catch (CantConverToInt &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}
void testValidatorConvertToIntLetter(){
    Validator validator;
    string nr2="a";
    try{
        validator.validatorConvertToInt(nr2);
        assert(false);
    }
    catch (CantConverToInt &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}
void testValidatorConvertToIntSpace(){
    Validator validator;
    string nr3=" ";
    try{
        validator.validatorConvertToInt(nr3);
        assert(false);
    }
    catch (CantConverToInt &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}
void testValidatorConvertToIntWord(){
    Validator validator;
    string nr4="bia";
    try{
        validator.validatorConvertToInt(nr4);
        assert(false);
    }
    catch (CantConverToInt &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorDuplicateCode(){
    Validator validator;
    Repo rep;
    Service service(rep);
    service.addDulce("1", "Apa", 4);
    service.addDulce("2", "Croissant", 6);
    service.addDulce("3", "Lays", 10);
    string code="1";
    try{
        validator.validatorDuplicateCode(code,service.getAllDulce());
        assert(false);
    }
    catch (DuplicateCode &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorEmptyCode(){
    Validator validator;
    string code="";
    try{
        validator.validatorEmptyCode(code);
        assert(false);
    }
    catch (EmptyCode &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorEmptyName(){
    Validator validator;
    string name="";
    try{
        validator.validatorEmptyName(name);
        assert(false);
    }
    catch (EmptyName &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorIntroduceInsufficientMoney(){
    Validator validator;
    int sumItrod = 12, sumNecessary = 15;
    try{
        validator.validatorIntroduceInsufficientMoney(sumItrod,sumNecessary);
        assert(false);
    }
    catch (InsufficientMoney &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorProductNotExist(){
    Validator validator;
    Repo rep;
    Service service(rep);
    service.addDulce("1", "Apa", 4);
    service.addDulce("2", "Croissant", 6);
    service.addDulce("3", "Lays", 10);
    string code="4", name ="Apa";
    int price = 4;
    try{
        validator.validatorProductNotExist(code,name,price,service.getAllDulce());
        assert(false);
    }
    catch (ProductNotExist &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorNegativeprice(){
    Validator validator;
    string price = "-1";
    try{
        validator.validatorNegativePrice(price);
        assert(false);
    }
    catch (NegativePrice &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorInvalidCode(){
    Validator validator;
    Repo rep;
    Service service(rep);
    service.addDulce("1", "Apa", 4);
    service.addDulce("2", "Croissant", 6);
    service.addDulce("3", "Lays", 10);
    string code="4";
    try{
        validator.validatorInvalidCode(code,service.getAllDulce());
        assert(false);
    }
    catch (InvalidCode &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidatorIsNotNumber(){
    Validator validator;
    string nr2="a";
    try{
        validator.validatorIsNotNumber(nr2);
        assert(false);
    }
    catch (IsNotNumber &e){
        assert(true);
        return;
    }
    catch (...){
        assert(false);
    }
    assert(false);
}

void testValidators(){
    testValidatorConvertToIntEmpty();
    testValidatorConvertToIntLetter();
    testValidatorConvertToIntSpace();
    testValidatorConvertToIntWord();
    testValidatorDuplicateCode();
    testValidatorEmptyCode();
    testValidatorEmptyName();
    testValidatorIntroduceInsufficientMoney();
    testValidatorProductNotExist();
    testValidatorNegativeprice();
    testValidatorInvalidCode();
    testValidatorIsNotNumber();
}

void tests(){
    testDulciuri();
    testRepo();
    testService();
    testValidators();
    std::cout<<"Testele au rulat cu succes!";
}
