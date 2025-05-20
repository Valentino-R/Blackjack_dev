#include "everything.h"


void Card::DisplayCard()
{
    PrintRank();
    PrintSuit();
    printValue();
    std::cout << '\n';
}


void Card::PrintRank()
{
    if (m_rank == two)
    {
        std::cout << "2 of ";
    }
    else if (m_rank == three)
    {
        std::cout << "3 of ";
    }
    else if (m_rank == four)
    {
        std::cout << "4 of ";
    }
    else if (m_rank == five)
    {
        std::cout << "5 of ";
    }
    else if (m_rank == six)
    {
        std::cout << "6 of ";
    }
    else if (m_rank == seven)
    {
        std::cout << "7 of ";
    }
    else if (m_rank == eight)
    {
        std::cout << "8 of ";
    }
    else if (m_rank == nine)
    {
        std::cout << "9 of ";
    }
    else if (m_rank == ten)
    {
        std::cout << "10 of ";
    }
    else if (m_rank == Jack)
    {
        std::cout << "Jack of ";
    }
    else if (m_rank == Queen)
    {
        std::cout << "Queen of ";
    }
    else if (m_rank == King)
    {
        std::cout << "King of ";
    }
    else if (m_rank == Ace)
    {
        std::cout << "Ace of ";
    }
    else
    {
        std::cout << "OwO";
    }    
}

void Card::PrintSuit()
{
    if (m_suit == clubs)
    {
        std::cout << "Clubs";
    }
    else if (m_suit == diamonds)
    {
        std::cout << "Diamonds";
    }
    else if (m_suit == hearts)
    {
        std::cout << "Hearts";
    }
    else if (m_suit == spades)
    {
        std::cout << "Spades";
    }
    else
    {
        std::cout << "UwU";
    } 
}

void Card::printValue()
{
    if (m_value == 2)
    {
        std::cout << " Value : 2 ";
    }
    else if (m_value == 3)
    {
        std::cout << " Value : 3 ";
    }
    else if (m_value == 4)
    {
        std::cout << " Value : 4 ";
    }
    else if (m_value == 5)
    {
        std::cout << " Value : 5 ";
    }
    else if (m_value == 6)
    {
        std::cout << " Value : 6 ";
    }
    else if (m_value == 7)
    {
        std::cout << " Value : 7 ";
    }
    else if (m_value == 8)
    {
        std::cout << " Value : 8 ";
    }
    else if (m_value == 9)
    {
        std::cout << " Value : 9 ";
    }
    else if (m_value == 10)
    {
        std::cout << " Value : 10 ";
    }
    else if (m_value == 11)
    {
        std::cout << " Value : 11 ";
    }
    else
    {
        std::cout << "NANY???";
    }
    
}

Rank Card::getRank() const
{ return m_rank; }

void Card::setRank(Rank rank)
{ m_rank = rank; }

Suit Card::getSuit() const
{ return m_suit; }

void Card::setSuit(Suit suit)
{ m_suit = suit; }

int Card::getValue() const
{ return m_value; }

void Card::setValue(Rank, int value)
{
    getRank();
    if (m_rank == two)
    {
        value = 2;
    }
    else if (m_rank == three)
    {
        value = 3;
    }
    else if (m_rank == four)
    {
        value = 4;
    }
    else if (m_rank == five)
    {
        value = 5;
    }
    else if (m_rank == six)
    {
        value = 6;
    }
    else if (m_rank == seven)
    {
        value = 7;
    }
    else if (m_rank == eight)
    {
        value = 8;
    }
    else if (m_rank == nine)
    {
        value = 9;
    }
    else if (m_rank == ten)
    {
        value = 10;
    }
    else if (m_rank == Jack)
    {
        value = 10;
    }
    else if (m_rank == Queen)
    {
        value = 10;
    }
    else if (m_rank == King)
    {
        value = 10;
    }
    else if (m_rank == Ace)
    {
        value = 11; 
    }
    else
    {
        std::cout << "OwO";
    }
    m_value = value;    
}

Deck::Deck()
{
    for (int col = (int)clubs; col <= (int)spades; col++)
    {
        for (int row = (int)two; row <= (int)Ace; row++)
        {
            Card card;
            card.setRank((Rank)row);
            card.setSuit((Suit)col);
            card.setValue((Rank)row, row);
            
            int index = (13 * col) + row;
            m_cards[index] = card;
        } 
    }
}

Rank Deck::getRank(int index) const
{ return m_cards[index].getRank(); }

void Deck::setRank(Rank rank, int index)
{ m_cards[index].setRank(rank); }

Suit Deck::getSuit(int index) const
{ return m_cards[index].getSuit(); }

void Deck::setSuit(Suit suit , int index)
{ m_cards[index].setSuit(suit); }

int Deck::getValue(int index) const
{ return m_cards[index].getValue(); }

void Deck::setValue(Rank rank, int value, int index)
{ m_cards[index].setValue(rank, value); }

void Deck::DisplayDeck()
{
    for (int col = (int)clubs; col <= (int)spades; col++)
    {
        for (int row = (int)two; row <= (int)Ace; row++)
        {
            int index = (13 * col) + row;
            m_cards[index].DisplayCard();
        }
    }
}

int main()
{
    Deck deck1;
    deck1.DisplayDeck();

    return 0;
}