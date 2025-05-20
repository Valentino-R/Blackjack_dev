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
    void shuffleDeck();
};

class Player{
private:
    
    std::vector<Card> playerHand;

public:

    void passTurn();
    void splitHand();
    void drawCard();
    void displayHand();
};

class Dealer{
private:

    std::vector<Card> dealerHand;
    
public:
    Deck getDeck() const;
    void drawTill();
    void drawCard();
    void displayCard();
};

class Game{
private:

    
        
public:

    std::vector<Deck> gamePile;
    void createPile();
    void diplaypile();    
    void shufflePile();
    void dealCard();
    void getHandValue();
    void setHandValue();
    void displayHandValue();  
};