
#include <iostream>
#include <vector>
#include "items.cpp"

class Player{
    private:
        bool isDigit(std::string s);
        std::string getInput();
        float getNumInput();
        std::string determineChange(float change);

    public:
        
        std::string Dialouge;
        float wallet = 100;
        std::vector<Item> inventory;

        Player();

        std::string GetItem();

        int GetAmount();

        std::string PrintInventory();

        void BuyItem(Item* item, float amount);

};