#include <vector>
#include "items.cpp"

class Menu{
    public:
        std::vector<Item> menuList;

        Menu();

        void AddItem(Item i);

        std::string PrintMenu();

};

class Cafe{

    bool hasItem(std::string itemname);
    Item* selectedItem;

    public:
    Menu Menu;
    std::string Dialouge;

    Cafe();

    Item* GetSelectedItem();

    void SelectItem(std::string itemname);
    
    std::string DrawCafe();
};

