#pragma once
#include <iostream>
#include <random>
#include <vector>

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

class Card{
private:

    Rank m_rank;
    Suit m_suit;
    int m_value;
    
public:

    Rank getRank() const;
    void setRank(Rank);
    
    Suit getSuit() const;
    void setSuit(Suit);

    int getValue() const;
    void setValue(Rank, int value);
    

    void DisplayCard();
    void PrintRank();
    void PrintSuit();
    void printValue();
};


class Deck{
private:
    
    Card m_cards[52];
    std::vector<Card> mixedDeck [52];
    
public:
    
    Rank getRank(int index) const;
    void setRank(Rank, int index);
    
    Suit getSuit(int index) const;
    void setSuit(Suit, int index);

    int getValue(int index) const;
    void setValue(Rank, int value, int index);

    Deck();
    void createDeck();
    void DisplayDeck();
};

class Hand{
private:

    

public:

    std::vector<Card> cardsInHand;

};

class Player{
private:
    
    Hand playerHand;

public:

    void passTurn();
    void splitHand();
    void drawCard();
    void showHandValue();
    void displayHand();
};

class Dealer{
private:

    Hand dealerHand;
    
public:

    void showHandValue();
    void drawTill();
    void drawCard();

    void displayCard();
};

class Game{
private:

    std::vector<Deck> gamePile;
        
public:

    
    void createPile();
    void diplaypile();    
    void shufflePile();
    void pileCardNbr();
    void dealCard();
    void getHandValue();
    void setHandValue();
    void displayHandValue();  
};