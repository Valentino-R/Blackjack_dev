#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>




class Card{
    
public:

    enum Suit{
        clubs,
        diamonds,
        hearts,
        spades,
        SUIT,
    };

    enum Rank{
        two, 
        three, 
        four, 
        five, 
        six,
        seven,
        eight,
        nine, 
        ten,
        Jack,
        Queen,
        King, 
        Ace,
        RANK,
    };

    Card();
    Card(Suit suit, Rank rank);

    Rank rank;
    Rank getRank() const;
    void setRank(Rank);
    
    Suit suit;
    Suit getSuit() const;
    void setSuit(Suit);

    int getValue() const;
    void setValue(Rank, int value);
    
    void displayCard();
    void PrintRank();
    void PrintSuit();
    void printValue();

private:

    Rank m_rank;
    Suit m_suit;
    int m_value;
};


class Deck{
private:
    
public:

    std::vector<Card> m_deck;
    Deck();
    void pileOfDecks();
    void displayDeck();
    void shuffleDeck();
    bool moreCards() const;

    void getCard();

    Card drawedCard;
    Card dealCard();
    void printCardDelt();
};

class Hand{
private:
    
    int m_value {0};
    std::vector<Card> m_cardInHand;
    Card::Rank rank;
    bool m_isHandActive {false};
    int handID {0};
    
public:
    
    int calcHandValue();
    bool passTurn();
    void drawCard();
    void splitHand();
    void doubleDown();
    bool surrender();
};
    
class Player{
private:
    
    Hand m_firstHand;
    Hand m_secondHand;
    Hand m_thirdHand;
    Hand m_fourthHand;
    std::vector<Hand> m_playerHands;
    int m_reserv {100};
    int m_bet {10};

public:

    void displayHand();
    Hand chooseHand();    
    bool firstSplit {false};
    bool secondSplit {false};
    bool thirdSplit {false};
    bool activHand {false};
};

class Game{
private:

    Deck m_gamePile;
    Card::Rank rank;
        
public:

   
    
    void giveCardPlayer();
    int setPlayerHandValue();
    void printPlayerHand();
    void displayPlayerHand();
    bool playerStand();
    void playerSplit();
    void playerSurrender();
    void playerChoices(bool& playerchoice);
    bool playerLoose {false};

    std::vector<Card> dealerHand;
    void giveCardDealer();
    int setDealerHandValue();
    void printDealerHand();
    void displayDealerHand();
    void drawTill();
    bool dealerLoose {false};

    void createPile();
    void displayPile();   
    void shufflePile();
    void setHandValue();
    void displayHandValue();

    void setupGame();
    void comparePlayerAndDealerHandValue();
    void checkWinner();
    bool playerWin {false};
};