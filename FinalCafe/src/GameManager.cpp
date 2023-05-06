#ifndef GAMEMANAGER
#define GAMEMANAGER
#include "cafe.cpp"
#include "player.cpp"
#include <iostream>

class GameManager{
    public:
    bool isRunning;
    Cafe c;
    Player p;

    GameManager(){
        c = Cafe();
        p = Player();
        mainFunc();
    }

    void mainFunc(){
        isRunning = true;
        while(isRunning){
            std::cout << c.DrawCafe() << std::endl;
            std::cout << "Enter an Item's Name To Select It. \nEnter \"BUY\" to buy selected item. \nEnter \"VIEW\" to view the items you have " << std::endl;
            std::string input = p.GetItem();
            if(input == "BUY"){
                std::cout << "Enter a dollar amount to pay with:" << std::endl;
                int amount = p.GetAmount();
                p.BuyItem(c.GetSelectedItem(), amount);
            }
            else if(input == "VIEW"){
                std::cout << p.PrintInventory() << std::endl;
                c.Dialouge = "";
                p.Dialouge = "";
            }
            else{
                c.SelectItem(input);
            }
            std::cout << c.Dialouge;
            std::cout << p.Dialouge;
        }
    }

};

#endif