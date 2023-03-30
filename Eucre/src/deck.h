
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

Card(std::string n = "none", std::string s = "none", int v = 0);

std::string PrintCard();

};

class Deck{

private:
std::string names[7] = {"jack", "ace", "king", "queen", "ten", "nine", "eight"}; 
std::string suits[4] = {"diamonds", "hearts", "spades", "clubs"};
std::vector<Card> Cards;

std::vector<Card> CreateDeck();

public:     

Deck();

void PrintDeck();

void ShuffleDeck();

Card DrawCard();

void ResetDeck();

};
