#include <string>


class Item{
    public:
        std::string Name;
        float Price;

        Item();
        Item(std::string _name, float _price);

        std::string GetInfo();

        Item CopyItem();
};

class USDAmount{
    float dollars;
    float cents;
    //maybe handle nickel dime exchange shit in this class - should kinda mimic datetime structs in c#
    
};