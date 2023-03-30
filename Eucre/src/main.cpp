#include "players.cpp"
#include "round.cpp"
#include "cardChecker.cpp"

#pragma region REQUIRMENTS
// DONE You must implement game setup of 4 players 

// DONE you must initialize a standard 28 card euchre deck

// DONE Your eucher deck cannot be passed by value

// DONE You must partition 4 players into 2 teams.

// Each players gets 2 cards in the first deal and 3 cards in the second.

// DONE During the bidding phase if no player calls trump then the round ends and redeal

// players cannot go all-in

// DONE each won hand is 1 point. play uniil a team has won 10 points

// DONE calling trump and losing the hand results in a lost point
#pragma endregion
#pragma region notes
// To set code runner execute command to not be active file, 
// go to vscode settings
// search code runner
// change custom command to be whatever you want it to be
// use ctrl+alt+k to run this command

//to toggle header / src files use f4

//need to create AI for players
//right now team one always wins because player one always wins, so need to rotate dealer
#pragma endregion
#pragma region CARDCHECKERTESTING
std::vector<Card> getTempTable(Deck& d){
    std::vector<Card> table;
    for(int i =0; i < 5; i++){
        table.push_back(d.DrawCard());
    }
    return table;
}

void printTestTable(std::vector<Card> t){
    std::cout << "TEST TABLE" << std::endl;
    for(int i =0; i < t.size(); i++){
        std::cout << t[i].PrintCard() << std::endl;
    }
}

void testCardChecker(){
    Deck d = Deck();
    d.ShuffleDeck();
    std::vector<Card> testTable = getTempTable(d);
    printTestTable(testTable);
    Card trump = d.DrawCard();
    std::cout << trump.PrintCard() << " TRUMP" << std::endl;
    CardChecker c = CardChecker(trump, testTable);
    Card winner = c.getWinningCard(); 
    std::cout<< winner.PrintCard() <<" WINNER"<<std::endl;
}
#pragma endregion

int main (){
    std::cout<<"start"<<std::endl;
    Deck d = Deck();
    Round r = Round(d);
    

}