#pragma once
#include "cards.h"
#include <algorithm>

class GenericPlayer : public Hand
{
public:
    string name;
public:
    explicit GenericPlayer(string);
    virtual bool IsHitting(const string&) = 0;
    bool IsBoosted();
    void Bust();
    friend ostream& operator<<(ostream&, GenericPlayer&);
};

class Deck : public Hand
{
private:
    void Populate();
public:
    Deck();
    void Shuffle();
    void Deal(Hand&);
    void AdditionalCards(GenericPlayer&);
    friend void printPlayers();
};

class Player : public GenericPlayer
{
public:
    explicit Player(string);
    bool IsHitting(const string&) override;
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House : public GenericPlayer
{
public:
    House();
    bool IsHitting(const string&) override;
    void FlipFirstCard();
};

class Game
{
private:
    Deck deck;
    House house;
    vector<Player> players;
public:
    explicit Game(const vector<string>&);
    void Play();
};

void printPlayers(vector<Player>&);