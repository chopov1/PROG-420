#ifndef DECK
#define DECK
#include "deck.h"

Card::Card(std::string n, std::string s, int v){
    Suit = s;
    Name = n;
    Value = v;
};

std::string Card::PrintCard(){
    return Name + " of " + Suit;
};

std::vector<Card> Deck::CreateDeck(){
    std::vector<Card> deck;
    deck.clear();
    for(int n = 0; n < 7; n++){
        for(int s = 0; s < 4; s++){
            Card c = Card(names[n], suits[s], n);
            deck.push_back(c);
        }
    }
    return deck;
};

Deck::Deck(){
    srand(time(0));
    ResetDeck();
};

void Deck::PrintDeck(){
    std::cout << "" << std::endl;
    std::cout << "PRINTING DECK" << std::endl;
    //hohoho c++
    for(int c =0; c < Cards.size(); c++){
        std::cout << Cards[c].PrintCard() << std::endl;
    }
};

void Deck::ShuffleDeck(){
    for(int i = Cards.size() -1; i > 0; i--){
        int index = (rand() % i);
        Card temp = Cards[i];
        Cards[i] = Cards[index];
        Cards[index] = temp;
    }
};

Card Deck::DrawCard(){
    Card c = Cards[Cards.size()-1];
    Cards.pop_back();
    return c;
};

void Deck::ResetDeck(){
    Cards = CreateDeck();
}

#endif
