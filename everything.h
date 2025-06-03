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

class Player{
private:
    
std::vector<Card> m_playerHand;

public:

    void passTurn();
    void splitHand();
    Deck drawCard();
    void showHandValue();
    void displayHand();
};

class Game{
private:

    Deck m_gamePile;
    int m_playerHandValue {0};
    int m_dealerHandValue {0};

    Card::Rank rank;
        
public:

    std::vector<Card> playerHand;
    std::vector<Card> splitedHand;
    void giveCardPlayer();
    int setPlayerHandValue();
    void printPlayerHand();
    void displayPlayerHand();
    bool playerStand();
    void playerSplit();
    void playerSurrender();
    void playerChoices(bool& playerchoice);
    bool playerLoose {false};
    bool playerEndTurn {false};

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