//
// Created by 37067 on 12/11/2021.
//

#ifndef UNTITLED9_ITEM_H
#define UNTITLED9_ITEM_H
#include <string>

using namespace std;

class Item{
public:
    Item();
    Item(int cnt, string m, string name);
    void showDetails();
    void setPrice(double priceUnits, double price);
    double getPrice()const;
    int getCount();
    void increaseCount(int n);
    void decreaseCount(int n);
protected:

private:

    int count;
    double price,priceUnits;
    string mat, name;
};
#endif //UNTITLED9_ITEM_H
