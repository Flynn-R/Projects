#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum Suit
{
    Heart, Spade, Diamond, Club
};
enum Value
{
    Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7,
    Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13
};

class Card
{
public:
    Card(Suit, Value, bool = false);
    void flip();
    Value getValue();
    bool isFaceUp;
private:
    Suit cardSuit;
    Value cardValue;
    friend ostream& operator<<(ostream&, Card&);
};

class Hand
{
protected:
    vector<Card*> cards;
public:
    virtual ~Hand();
    void Add(Card*);
    void Clear();
    int GetValue();
};