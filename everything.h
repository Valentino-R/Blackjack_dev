#pragma once
#include <iostream>
#include <random>
#include <vector>



class Card{
    
public:

    enum Suit{
        clubs,
        diamonds,
        hearts,
        spades,
        SUIT
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
        RANK
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
    
    Card m_cards[52];
    std::vector<Card> m_deck;
    int m_drawedCard;
    
public:

    Deck();
    
    Rank getRank(int index) const;
    void setRank(Rank, int index);
    
    Suit getSuit(int index) const;
    void setSuit(Suit, int index);

    int getValue(int index) const;
    void setValue(Rank, int value, int index);

    Deck();
    void createDeck();
    void DisplayDeck();

    void drawCard(Card);
    void showDrawedCard();
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