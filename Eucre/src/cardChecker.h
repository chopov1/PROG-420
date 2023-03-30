#include "deck.cpp"
#include "players.cpp"



class CardChecker{
    
    private:
    Card trump;
    std::vector<Card> &table;

    public:

    CardChecker(Card trump, std::vector<Card> &table);

    void setVars(Card trump, std::vector<Card> &table);

    Card getWinningCard();

    bool tableHasTrump();

    std::string getBower();

    std::string PrintTable(std::vector<Card> t);
 

};