#ifndef ITEMS
#define ITEMS

#include "items.h"

Item::Item(std::string _name, float _price){
    Name = _name;
    Price = _price;
};

std::string Item::GetInfo(){
    return Name + ": " + std::to_string(Price); 
}

Item::Item(){
    Name = "none";
    Price = 0;
}

Item Item::CopyItem(){
    return Item(Name, Price);
}

#endif

