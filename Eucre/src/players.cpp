#include "deck.h"

class Player{
    private:
    int handSize = 5;
    public:
    int PlayerNumber;
    Card Hand[5];

    Player(int pn, Deck& deck){
        PlayerNumber = pn;
        DrawHand(deck);
    };

    void DrawHand(Deck& deck){
        for(int i =0; i < handSize; i++){
            Hand[i] = deck.DrawCard();
            //std::cout << Hand[i].PrintCard() << " hand" << std::endl;
        }
    };

    void ShowHand(){
        std::cout << "PLAYER " << PlayerNumber << "'s HAND" << std::endl;
        for(int c =0; c < handSize; c++){
            std::cout << Hand[c].PrintCard() << std::endl;
        }
    }

};

class Team{
    public:
    Player* p1;
    Player* p2;
    int Points;
    std::string TeamName;

    Team(Deck& deck, Player* one, Player * two){
        Points =0;
        p1 = one;
        p2 = two;
    };

};