#include "item.h"
#include<iostream>
using namespace std;

Item::Item() {
    count = 0;
    mat = "vnt";
    this->priceUnits = 1;
    this->price = 0;
    this->name = "unknown";
}
Item::Item(int cnt, string m, string name) {
    count=cnt;
    mat=m;
    this->priceUnits=priceUnits;
    this->price=price;
    this->name=name;
}
void Item::showDetails() {
    cout<<name<<" "<<count<<" "<<mat<<" "<<getPrice()<<" eur"<<endl;
}
void Item::setPrice(double priceUnits, double price){
    this->priceUnits=priceUnits;
    this->price=price;
};
double Item::getPrice()const{
    return (count/priceUnits)*price;
}
int Item::getCount(){
    return count;
}
void Item::increaseCount(int n){
    count+=n;
}
void Item::decreaseCount(int n){
    count-=n;
}