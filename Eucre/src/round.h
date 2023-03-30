#include "players.cpp"
#include "cardChecker.cpp"

class Round{

    private:
    Deck d;
    int pointsToWin = 10;
    Player* players[4];
    public:
    
    Team t1;
    Team t2;

    Card Trump;

    int dealerIndex;

    Round(Deck& deck);

    void PrintPlayerHands();
    
    void playRound();

    void playGame();

    void dealCards();

    bool gameHasEnded();

    Card GetTrumpCard();

    bool keepTrumpCard(Card trump);

    void DetermineWinner(Card trump, std::vector<Card> table);

    std::vector<Card> getTable();

    void SetNewDealer();

    void resetChoser();
};