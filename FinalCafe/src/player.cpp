#ifndef PLAYER
#define PLAYER
#include "player.h"
#include <string>
#include <cmath>

bool Player::isDigit(std::string s){
    for(int i = 0; i < s.size(); i++){
        if(!std::isdigit(s[i])){
            return false;
        }
    }
    return true;
}

std::string Player::getInput(){
    std::string input;
    getline(std::cin, input);
    return input;
}

float Player::getNumInput(){
    std::string s = getInput();
    float f = 0;
    if(isDigit(s)){
        f = std::stof(s);
    }
    return f;
}

Player::Player(){

}

std::string Player::GetItem(){
    return getInput();
}

std::string Player::PrintInventory(){
    std::string info = "Your Items Are Listed Below:\n";
    for(int i =0; i < inventory.size(); i++){
        info += inventory[i].GetInfo() + "\n";
    }
    return info;
}

int Player::GetAmount(){
    return getNumInput();
}

void Player::BuyItem(Item* item, float amount){
    if(amount - item->Price >= 0){
        amount -= item->Price;
        wallet -= amount;
        inventory.push_back(item->CopyItem());
        Dialouge = "\nYou purchased " + item->Name + " for " + std::to_string(item->Price) + ". You now have " + std::to_string(wallet) + " dollars\n\n";
        Dialouge += determineChange(amount);
    }
    else{
        Dialouge = "You do not have the required funds to purchase " + item->Name +"\n";
    }
    
}

//chat gpt helped me with the math for this method
std::string Player::determineChange(float amount){
    int change = std::round(amount * 100);
    int Q = change / 25;
    change = change % 25;
    int D = change/10;
    change = change % 10;
    int N = change/5;
    change = change % 5;
    int P = change;
    return "\nYour change is " + std::to_string(Q) + " quarters, " + std::to_string(D) + " dimes, " + std::to_string(N) + " nickles, and " + std::to_string(P) + " pennies. Thank you for you're purchase\n";
}



#endif