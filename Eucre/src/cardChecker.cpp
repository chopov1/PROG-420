#ifndef CHECKER
#define CHECKER
#include "cardChecker.h"

//steps to check winner
//check if any card is the jack of trump
//check if any card is the bower
//get all cards that share a suit with the trump
//get the highest value of the cards
//if no cards match trump, get the highest value among all cards

CardChecker::CardChecker(Card trump, std::vector<Card> &table) : trump(trump), table(table){

}

void CardChecker::setVars(Card trump, std::vector<Card> &table){
    this->trump = trump;
    this->table = table;
};

Card CardChecker::getWinningCard(){

    Card winner = table[0];
    std::string leadingSuit = table[0].Suit;

    //check for jack of trump
    for(int i =0; i < table.size(); i++){
        if(table[i].Suit == trump.Suit && table[i].Name == "jack"){
            return table[i];
        }
    }
    //check for bower
    std::string bower = getBower();
    for(int i =0; i < table.size(); i++){
        if(table[i].Suit == bower && table[i].Name == "jack"){
            return table[i];
        }
    }

    //check if there are any trump suits
    if(tableHasTrump()){
        //check highest card of trump suits
        for(int i=0; i < table.size(); i++){
            if(table[i].Suit == trump.Suit){
                if(winner.Suit == trump.Suit){
                    if(table[i].Value < winner.Value){
                        winner = table[i];
                    }
                }
                else{
                    winner = table[i];
                }
            }
        }
    }
    else{
        //check highest of leading suit
        for(int i =0; i < table.size(); i++){
            if(table[i].Suit == leadingSuit && table[i].Value < winner.Value){
                winner = table[i];
            }
        }
    }
    return winner;
};

bool CardChecker::tableHasTrump(){

    for(int i =0; i < table.size(); i++){
        if(table[i].Suit == trump.Suit){
            return true;
        }
    }
    return false;
}

std::string CardChecker::getBower(){
    if(trump.Suit == "hearts"){
        return "diamonds";
    }
    if(trump.Suit == "diamonds"){
        return "hearts";
    }
    if(trump.Suit == "spades"){
        return "clubs";
    }
    if(trump.Suit == "clubs"){
        return "spades";
    }
    return "none";
}

std::string CardChecker::PrintTable(std::vector<Card> t){
    
    std::string Table = "\n";
    Table += "TABLE\n";
    for(int i =0; i < t.size(); i++){
        Table+= t[i].PrintCard();
        Table+= "\n";
    }
    return Table;
}


#endif