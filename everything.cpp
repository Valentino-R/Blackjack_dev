#include "everything.h"

//Card constructor link m_suit and m_rank to suit and rank enums
Card::Card()
{
    m_suit = SUIT;
    m_rank = RANK;
}

Card::Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank) {}

//display the card in terminal by calling the printrank and printsuit function
void Card::displayCard()
{
    PrintRank();
    PrintSuit();
    std::cout << '\n';
}

//sent to the terminal a text equivalent to the rank of the card
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

//sent to the terminal a text equivalent to the suit of the card
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

//m_rank getter 
Card::Rank Card::getRank() const
{ return m_rank; }

//m_rank setter
void Card::setRank(Rank rank)
{ m_rank = rank; }

//m_suit getter 
Card::Suit Card::getSuit() const
{ return m_suit; }

//m_rank setter
void Card::setSuit(Suit suit)
{ m_suit = suit; }

//m_value getter
int Card::getValue() const
{ return m_value; }

//set the value of a card in fonction of his rank 
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

//deck constructor that loop through both suit and rank enum and pushback the created card in a vector
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

//display the deck by looping throught it and calling the displaycard function
void Deck::displayDeck()
{
    for (Card cards : m_deck) 
    {
        cards.displayCard();
    }   
}

//shuffel the deck whith the shuffle function, random_device and default_random_engine. 
//random_device is seeded in default_random_engine to ensure a differant shuffle each time the function is called.
//default_random_engine them serv as the unit of the shuffle. 
void Deck::shuffleDeck()
{   
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(m_deck.begin(), m_deck.end(), rng);
}

//return a copy of the last card of the deck then suppress hit from the deck whith the pushback function.
Card Deck::dealCard()
{
    drawedCard = m_deck[m_deck.size()-1];
    m_deck.pop_back();

    return drawedCard;
}

//display the card drawed in the terminal by calling the displaycard function.
void Deck::printCardDelt()
{
    drawedCard.displayCard();
}

//create a pile by instantiating a deck object, shuffeling it and assigning it to m_gamepile.
void Game::createPile()
{
        Deck deck;
        deck.shuffleDeck();
        m_gamePile = deck;  
}

// display all the card in m_gamepile by calling the displaydeck function.
void Game::displayPile()
{
   m_gamePile.displayDeck(); 
}

//give a card to the player whith the push_back function to the playerHand vector by calling the dealcard function to m_gamePile. 
void Game::giveCardPlayer()
{
    playerHand.push_back(m_gamePile.dealCard());
}

//set the value of player hand by adding the value of each card in the player hand.
int Game::setPlayerHandValue()
{
    int value;
    m_playerHandValue = 0;
    for (Card cards : playerHand) 
    {
        cards.setValue(rank, value);
        m_playerHandValue += cards.getValue();
    }
    return m_playerHandValue;
}

//print the cards in the player hand in the terminal by looping throught the playerHand vector and calling the displayCard function.
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

//display all the cards in the hand of the player and their combined value in the terminal.
void Game::displayPlayerHand()
{
    std::cout << "Player Hand :\n";
    printPlayerHand();
    setPlayerHandValue(); 
    std::cout << "Value : " << m_playerHandValue << " points\n";
}

//give a card to the dealer whith the push_back function to the dealerHand vector by calling the dealcard function to m_gamePile.
void Game::giveCardDealer()
{
    dealerHand.push_back(m_gamePile.dealCard());
}

//print the cards in the dealer hand in the terminal by looping throught the dealerHand vector and calling the displayCard function.
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

//set the value of player hand by adding the value of each card in the player hand.
void Game::setDealerHandValue()
{
    int value;
    for (Card cards : dealerHand) 
    {
        cards.setValue(rank, value);
        m_dealerHandValue += cards.getValue();
    }
    std::cout << m_dealerHandValue << '\n';
}

//setup a game by creating a pile and then giving 2 cards to the player and 1 to the dealer.
void Game::setupGame()
{
    createPile();
    giveCardPlayer();
    giveCardDealer();
}

int main()
{
    Game game;
    game.createPile();
    game.giveCardPlayer();
    game.displayPlayerHand();
    std::cout << " " << '\n';
    game.giveCardPlayer();
    game.displayPlayerHand();
    game.displayPlayerHand();

    return 0;
}

    /*Deck deck;
    deck.shuffleDeck();
    deck.DisplayDeck();
    std::cout << " " << '\n';
    deck.dealCard();
    deck.printCardDelt();*/