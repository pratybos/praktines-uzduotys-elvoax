#include <iostream>
#include "item.h"
#include "Storage.h"
#include "Processors.h"
#include "Database.h"
#include "Order.h"
#include <vector>
#include<ctime>
Order * findOrder(vector<Order*> & orders, string& name){
    for(Order* p : orders) {
        if (p->getName()==name){
            return p;
        }
    }
    return nullptr;
}
int main() {
    std::srand(std::time(nullptr));
    Processors musuProc;
    int processors,storage,database;
    Database musuDb;
    Storage musuSt;
    bool newOrder=true;
    string name;
    vector<Order*> orders;
    while(newOrder){
        cout<<"Iveskite esamo arba naujo kliento varda:"<<endl;
        name.clear();
        getline (cin, name);
        if (!name.empty()) {

            Order* p= findOrder(orders,name);
            if(p== nullptr){
                cout<< "Naujas klientas:"<<name<<endl;
                p=new Order(name);
                orders.push_back(p);
            }
            else{
                cout<< "Esamo uzsakymo koregavimas. Klientas:"<<name<<endl;
                p->getData(processors, storage,database);
                musuProc.increaseCount(processors);
                musuSt.increaseCount(storage);
                musuDb.increaseCount(database);
            }
            p->process(musuProc.getCount(), musuSt.getCount(), musuDb.getCount());
            p->getData(processors, storage,database);
            musuProc.decreaseCount(processors);
            musuSt.decreaseCount(storage);
            musuDb.decreaseCount(database);
            p->showDetails();
        } else {
            newOrder = false;
        }

    }
    for(Order* p : orders) {
        delete p;
    }
    orders.clear();
    return 0;
}
