#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "RepoFile.h"
using namespace std;
#include <fstream>

int main() {

    tests();
    cout<<endl;
    Repo* repo = new RepoFile("produse.txt");
//    Service* s = new Service(r);
//    RepoFile repo("produse.txt");
//    Repo repo;
    Service* srv = new Service(*repo);

    UI UserInterface(*srv);
    UserInterface.runMenu();


    return 0;
}

//    srv.addDulce("12", "Apa", 4);
//    srv.addDulce("54", "Croissant", 6);
//    srv.addDulce("21", "Lays", 10);
//    srv.addDulce("21", "Lays", 10);