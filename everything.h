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
    };

    Card(Suit suit, Rank rank);

    Rank rank;
    Rank getRank() const;
    void setRank(Rank);
    
    Suit suit;
    Suit getSuit() const;
    void setSuit(Suit);

    int getValue() const;
    void setValue(Rank, int value);
    

    void DisplayCard();
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
    
    std::vector<Card> m_deck;
    int m_drawedCard;
    
public:

    Deck();
    void DisplayDeck();
    void shuffleDeck();
    bool moreCards() const;

    Card dealCard();
};

class Player{
private:
    
    

public:

    void passTurn();
    void splitHand();
    void drawCard();
    void showHandValue();
    void displayHand();
};

class Dealer{
private:

   
    
public:

    void showHandValue();
    void drawTill();
    void drawCard();

    void displayCard();
};

class Game{
private:

    Deck gamePile;
        
public:

    
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;
    void createPile();
    void diplaypile();    
    void shufflePile();
    void dealCard();
    void getHandValue();
    void setHandValue();
    void displayHandValue();
    void getTopCard();  
};