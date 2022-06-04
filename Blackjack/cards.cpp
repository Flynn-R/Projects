#include "cards.h"

using namespace std;

// Class Card
Card::Card(Suit suit, Value value, bool position) :
    cardSuit(suit), cardValue(value), isFaceUp(position) {}

void Card::flip() { isFaceUp = !isFaceUp; }

Value Card::getValue()
{
    if (cardValue > Ten && cardValue <= King)
        return Ten;
    return cardValue;
}

// Class Hand
Hand::~Hand() { Clear(); }

void Hand::Add(Card* card) { cards.push_back(card); }

void Hand::Clear() { cards.clear(); }

int Hand::GetValue()
{
    int sum = 0;
    int aceCount = 0;
    for (auto& card : cards)
    {
        if (card->isFaceUp)
        {
            sum += card->getValue();
            if (card->getValue() == Ace)
                aceCount++;
        }
    }

    if (aceCount > 0)
    {
        while (aceCount != 0)
        {
            if (sum + 10 <= 21)
            {
                sum += 10;
                aceCount--;
            }
            else
                aceCount = 0;
        }
    }

    return sum;
}