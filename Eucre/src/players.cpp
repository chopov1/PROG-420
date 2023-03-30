#ifndef PLAYER
#define PLAYER
#include "players.h"

    Player::Player(int pn, std::string teamname){
        PlayerNumber = pn;
        TeamName = teamname;
        //DrawHand(deck);
    };

    void Player::DrawHand(Deck& deck){
        for(int i =0; i < handSize; i++){
            Hand[i] = deck.DrawCard();
            //std::cout << Hand[i].PrintCard() << " hand" << std::endl;
        }
    };

    void Player::ShowHand(){
        std::cout << "PLAYER " << PlayerNumber << "'s HAND ON TEAM " << TeamName << std::endl;
        for(int c =0; c < handSize; c++){
            std::cout << Hand[c].PrintCard() << std::endl;
        }
    }

    Card Player::playCard(){
        //returning this by value so that the card stays in the players hand. this way I can check which player has the winning card to determine the winner after I run the table through the cardchecker
        return Hand[0];
    }

    bool Player::keepTrump(Card trump){
        for(int c =0; c < handSize; c++){
            if(Hand[c].Suit == trump.Suit){
                choseTrump = true;
                return true;
            }
        }
        return false;
    }


    Team::Team(std::string name)
        :p1(1,name), p2(2,name)
    {
        Tricks =0;
    };

    void Team::DealCards(Deck& deck){
        p1.DrawHand(deck);
        p2.DrawHand(deck);
    }

    void Team::PrintHands(){
        p1.ShowHand();
        p2.ShowHand();
    }

    void Team::checkIfPointsLost(){
        if(p1.choseTrump || p2.choseTrump){
            if(Tricks - 1 >= 0){
                Tricks--;
                std::cout << "The Team" << p1.TeamName << " LOST A POINT" << std::endl;
            }
        }
    }

    bool Team::teamHasCard(Card card){
        for(int i =0; i < p1.handSize; i++){
            if(p1.Hand[i].PrintCard() == card.PrintCard()){
                return true;
            }
        }

        for(int i =0; i < p1.handSize; i++){
            if(p2.Hand[i].PrintCard() == card.PrintCard()){
                return true;
            }
        }

        return false;
    }

#endif