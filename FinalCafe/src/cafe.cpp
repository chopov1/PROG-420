#ifndef CAFE
#define CAFE
#include "cafe.h"
#include <cmath>

void Menu::AddItem(Item i){
    menuList.push_back(i);
}

std::string Menu::PrintMenu(){
    std::string menu = "MENU - ORDER UP! \n";
    for(int i =0; i < menuList.size(); i++){
        menu += menuList[i].GetInfo() + "\n";
    }
    return menu;
}

Menu::Menu(){

}

Cafe::Cafe(){
    Menu.AddItem(Item("Biscuit", 1.23));
    Menu.AddItem(Item("Orange Juice", 2.11));
    Menu.AddItem(Item("Cheese Waffle", 5.99));
    Menu.AddItem(Item("Uglass Sandwich", 0.01));
    Menu.AddItem(Item("Cool Sandwich", 11.98));
    selectedItem = &Menu.menuList[0];
}

bool Cafe::hasItem(std::string itemname){
    for(int i =0; i < Menu.menuList.size(); i++){
        if(Menu.menuList[i].Name == itemname){
            return true;
        }
    }
    return false;
}

void Cafe::SelectItem(std::string itemname){
    if(hasItem(itemname)){
        for(int i =0; i < Menu.menuList.size(); i++){
            if(Menu.menuList[i].Name == itemname){
                selectedItem = &Menu.menuList[i];
                Dialouge = "";
            }
        }
    }
    else{
        Dialouge = "\nWe do not have the item " + itemname + ".\n\n";
    }
}

Item* Cafe::GetSelectedItem(){
    return selectedItem;
}

std::string Cafe::DrawCafe(){
    std::string info;
    info += "\nWelcome To The Cafe!\n";
    info += Menu.PrintMenu() + "\n";
    info += "Current Selection-> " + selectedItem->GetInfo() + "\n";
    return info;
}

#endif