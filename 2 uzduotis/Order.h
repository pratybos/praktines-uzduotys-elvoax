//
// Created by 37067 on 12/18/2021.
//

#ifndef UNTITLED9_ORDER_H
#define UNTITLED9_ORDER_H
#include"Processors.h"
#include "Storage.h"
#include "Database.h"

class Order {
public:
    Order(string cname);
    ~Order();
    void process(int maxProc, int maxSt, int maxDt);
    void getData(int& processors, int& storage,  int& database);
    void showDetails();
    string getName();
    void reset();
protected:
    void processors(int max);
    void database(int max);
    void storage(int max);
    int inputCount(string msg, int max);
private:
    Processors *proc;
    Storage *stor;
    Database *data;
    string cname;
};


#endif //UNTITLED9_ORDER_H
