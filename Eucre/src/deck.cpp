#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

class Card{

public:
std::string Suit;
std::string Name;
int Value;
Card(std::string n = "none", std::string s = "none", int v = 0){
    Suit = s;
    Name = n;
    Value = v;
}

std::string PrintCard(){
    return Name + " of " + Suit;
}

};

class Deck{

private:
std::string names[7] = {"jack", "ace", "king", "queen", "ten", "nine", "eight"}; 
std::string suits[4] = {"diamonds", "hearts", "spades", "clubs"};
std::vector<Card> Cards;

std::vector<Card> CreateDeck(){
    std::vector<Card> deck;
    for(int n = 0; n < 7; n++){
        for(int s = 0; s < 4; s++){
            Card c = Card(names[n], suits[s], n);
            deck.push_back(c);
        }
    }
    return deck;
}

public:

Deck(){
    Cards = CreateDeck();
}

void PrintDeck(){
    //hohoho c++
    std::cout << "PRINTING DECK" << std::endl;
    for(int c =0; c < Cards.size(); c++){
        std::cout << Cards[c].PrintCard() << std::endl;
    }
}

void ShuffleDeck(){
    for(int i = Cards.size() -1; i > 0; i--){
        srand(time(0));
        int index = (rand() % i);
        Card temp = Cards[i];
        Cards[i] = Cards[index];
        Cards[index] = temp;
    }
}

Card DrawCard(){
    Card c = Cards[Cards.size()-1];
    Cards.pop_back();
    return c;
}

};

