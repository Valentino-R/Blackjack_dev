#include "everything.h"

Card::Card()
{
    m_suit = SUIT;
    m_rank = RANK;
}

Card::Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank) {}

void Card::displayCard()
{
    PrintRank();
    PrintSuit();
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
        std::cout << "OwO ";
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

Card::Rank Card::getRank() const
{ return m_rank; }

void Card::setRank(Rank rank)
{ m_rank = rank; }

Card::Suit Card::getSuit() const
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
    for (int suit = Card::clubs; suit <= Card::spades; suit++)
    {
        for (int rank = Card::two; rank <= Card::Ace; rank++)
        {
            m_deck.push_back(Card(static_cast<Card::Suit>(suit),
            static_cast<Card::Rank>(rank)));
        } 
    }
}

void Deck::displayDeck()
{
    for (Card cards : m_deck) 
    {
        cards.displayCard();
    }   
}

void Deck::shuffleDeck()
{   
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(m_deck.begin(), m_deck.end(), rng);
}

Card Deck::dealCard()
{
    drawedCard = m_deck[m_deck.size()-1];
    m_deck.pop_back();

    return drawedCard;
}

void Deck::printCardDelt()
{
    drawedCard.displayCard();
}

void Game::createPile()
{
        Deck deck;
        deck.shuffleDeck();
        m_gamePile = deck;  
}

void Game::displayPile()
{
   m_gamePile.displayDeck(); 
}

void Game::giveCardPlayer()
{
    playerHand.push_back(m_gamePile.dealCard());
}

int Game::calcPlayerHandValue()
{
    int value;
    for (Card cards : playerHand) 
    {
        cards.setValue(rank, value);
        m_playerHandValue += cards.getValue();
    }
    return m_playerHandValue;
}

void Game::printPlayerHandValue()
{
    calcPlayerHandValue();
    
}

void Game::printPlayerHand()
{   
    if (playerHand.empty())
    {
        std::cout << "Hand empty\n";
        return;
    }
    for (Card cards : playerHand) 
    {
        cards.displayCard();
    }   
}

void Game::displayPlayerHand()
{

}

void Game::giveCardDealer()
{
    dealerHand.push_back(m_gamePile.dealCard());
}

void Game::printDealerHand()
{
    std::cout << "Dealer Hand :\n";
    if (dealerHand.empty())
    {
        std::cout << "Hand empty\n";
        return;
    }
    for (Card cards : dealerHand) 
    {
        cards.displayCard();
    }   
}

void Game::calcDealerHandValue()
{
    int value;
    for (Card cards : dealerHand) 
    {
        cards.setValue(rank, value);
        m_dealerHandValue += cards.getValue();
    }
    std::cout << m_dealerHandValue << '\n';
}

int main()
{
    Game game;
    game.createPile();
    game.giveCardPlayer();
    std::cout << " " << '\n';
    game.giveCardPlayer();
    game.printPlayerHand();
    game.printPlayerHand();

    return 0;
}

    /*Deck deck;
    deck.shuffleDeck();
    deck.DisplayDeck();
    std::cout << " " << '\n';
    deck.dealCard();
    deck.printCardDelt();*/