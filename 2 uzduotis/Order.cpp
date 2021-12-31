//
// Created by 37067 on 12/18/2021.
//

#include "Order.h"
#include<iostream>
using namespace std;
Order::Order(string cname){
    this->cname=cname;
    this->proc= nullptr;
    this->data= nullptr;
    this->stor= nullptr;
}
Order::~Order() {
    if(proc!= nullptr){
        delete proc;
    }
    if(stor!= nullptr){
        delete stor;
    }
    if(data!= nullptr){
        delete data;
    }
}
string Order::getName() {
    return cname;
}
void Order::process(int maxProc, int maxSt, int maxDt) {
    processors(maxProc);
    storage(maxSt);
    database(maxDt);
}
void Order::reset(){
    if(proc!= nullptr){
        delete proc;
        proc= nullptr;
    }
    if(stor!= nullptr){
        delete stor;
        stor=nullptr;
    }
    if(data!= nullptr){
        delete data;
        data= nullptr;
    }
}
int Order::inputCount(string msg, int max){
    int n;
    bool valid=false;
    while (!valid) {
        cout<< msg<<"[0..."<<max<<"]:";
        cin >> n;
        std::cin.ignore(1,'\n');
        if (n>=0 && n<=max){
            valid=true;
        } else {
            cout<<"Klaida, skaicius turi buti nuo 0 iki "<<max<<endl;
        }
    }
    return n;
}
void Order::processors(int max){
    int n= inputCount("Iveskite reikalinga procesoriu skaiciu:",max);
    if(n>0){
        proc= new Processors(n);
    }
}
void Order::storage(int max) {
    int n= inputCount("Iveskite reikalinga saugyklos dydi:",max);
    if (n > 0) {
        stor = new Storage(n);
    }
}
void Order::database(int max) {
    int n= inputCount("Iveskite reikalinga duomenu bazes dydi:",max);
    if (n > 0) {
        data = new Database(n);
        }
}
void Order::showDetails(){
    cout<<endl<<" Kliento "<<cname<<" uzsakymas: "<<endl;
    if (proc!=nullptr){
        proc->showDetails();
    }
    if (stor!=nullptr){
        stor->showDetails();
    }
    if (data!=nullptr){
        data->showDetails();
    }

}
void Order::getData(int& processors, int& storage,  int& database){
    processors=0;
    storage=0;
    database=0;
    if(proc!= nullptr){
        processors=proc->getCount();
    }
    if(stor!= nullptr){
        storage=stor->getCount();
    }
    if(data!= nullptr){
        database=data->getCount();
    }
}