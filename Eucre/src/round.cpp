#ifndef ROUND
#define ROUND

#include "round.h"


Round::Round(Deck& deck)
    :t1("TEAM 1"), t2("TEAM 2")
{
    d = deck;
    dealerIndex = 0;
    players[0] = &t1.p1;
    players[1] = &t1.p2;
    players[2] = &t2.p1;
    players[3] = &t2.p2;
    playGame();
};

void Round::PrintPlayerHands(){
    std::cout << "THE TRUMP CARD IS: " << Trump.PrintCard() << std::endl;
    t1.PrintHands();
    t2.PrintHands();
}


void Round::playGame(){
    while(!gameHasEnded()){
        playRound();
    }
}

bool Round::gameHasEnded(){
    if(t1.Tricks >= pointsToWin){
        return true;
    }
    if(t2.Tricks >= pointsToWin){
        return true;
    }
    return false;
}

void Round::playRound(){
    std::cout << "" << std::endl;
    std::cout << "ROUND BEGIN" << std::endl;
    std::cout << "The dealer this round is player " << players[dealerIndex]->PlayerNumber << " on team " << players[dealerIndex]->TeamName << std::endl;
    d.ResetDeck();
    d.ShuffleDeck();
    dealCards();
    Trump = GetTrumpCard();
    if(!keepTrumpCard(Trump)){
        std::cout << "ROUND ABORTED" << std::endl;
        return;
    }
    PrintPlayerHands();
    std::vector<Card> table = getTable();
    DetermineWinner(Trump, table);
    SetNewDealer(); 
    resetChoser();
    std::cout << "ROUND END" << std::endl;
}

void Round::resetChoser(){
    for(int i =0; i < 4; i++){
        players[i]->choseTrump = false;
    }
}

void Round::dealCards(){
    t1.DealCards(d);
    t2.DealCards(d);
}

Card Round::GetTrumpCard(){
    return d.DrawCard();
}

bool Round::keepTrumpCard(Card trump){
    int chooserIndex = dealerIndex;
    for(int i =0; i < 4; i++){
        chooserIndex++;
        if(chooserIndex > 3){
            chooserIndex = 0;
        }
        if(players[chooserIndex]->keepTrump(trump)){
            return true;
        }
    }
    return false;
}

void Round::DetermineWinner(Card trump, std::vector<Card> table){
    
    CardChecker c = CardChecker(trump, table);
    std::cout << c.PrintTable(table) << std::endl;
    Card winner = c.getWinningCard();
    std::cout << winner.PrintCard() <<" WINNING CARD" << std::endl;
    if(t1.teamHasCard(winner)){
        t1.Tricks++;
        t2.checkIfPointsLost();
    }
    else if(t2.teamHasCard(winner)){
        t2.Tricks++;
        t1.checkIfPointsLost();
    }
    std::cout << "TEAM 1 has taken: " << t1.Tricks << " tricks" << std::endl;
    std::cout << "TEAM 2 has taken: " << t2.Tricks << " tricks" << std::endl;
    
}

std::vector<Card> Round::getTable(){
    std::vector<Card> table;
    table.push_back(players[dealerIndex]->playCard());
    if(&t1.p1 != players[dealerIndex]){
        table.push_back(t1.p1.playCard());
    }
    if(&t1.p2 != players[dealerIndex]){
        table.push_back(t1.p2.playCard());
    }
    if(&t2.p1 != players[dealerIndex]){
        table.push_back(t2.p1.playCard());
    }
    if(&t2.p2 != players[dealerIndex]){
        table.push_back(t2.p2.playCard());       
    }
    return table;
}

void Round::SetNewDealer(){
    if(players[dealerIndex] == &t1.p1){
        dealerIndex = 1;
        return;
    }
    if(players[dealerIndex] == &t1.p2){
        dealerIndex = 2;
        return;
    }
    if(players[dealerIndex] == &t2.p1){
        dealerIndex = 3;
        return;
    }
    if(players[dealerIndex] == &t2.p2){
        dealerIndex = 0;
        return;
    }
}

#endif