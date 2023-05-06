#include "players.cpp"
#include "round.cpp"
#include "cardChecker.cpp"

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