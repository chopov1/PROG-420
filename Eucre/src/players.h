
#include "deck.cpp"

class Player{   
    public:
    int handSize = 3;
    std::string TeamName;
    int PlayerNumber;
    Card Hand[5];
    Card played;
    bool choseTrump;

    Player(int pn, std::string teamname);

    void DrawHand(Deck& deck);

    void ShowHand();

    Card playCard();

    bool keepTrump(Card trump);

};

class Team{
    public:
    Player p1;
    Player p2;
    std::string TeamName;
    int Points;
    

    Team(std::string name);

    void DealCards(Deck& deck);

    void PrintHands();

    bool teamHasCard(Card card);

    void checkIfPointsLost();
};
