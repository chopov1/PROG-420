
#include "players.h"



int main (){
    std::cout<<"start"<<std::endl;
    Deck d = Deck();
    d.ShuffleDeck();
    d.PrintDeck();
    
    Player p1 = Player(1, d);
    p1.ShowHand();

    d.PrintDeck();

}