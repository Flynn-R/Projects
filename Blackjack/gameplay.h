#pragma once
#include "cards.h"

class GenericPlayer : public Hand
{
protected:
    string name;
public:
    explicit GenericPlayer(string);
    virtual bool IsHitting() = 0;
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
};

class Player : public GenericPlayer
{
public:
    explicit Player(string);
    bool IsHitting() override;
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House : public GenericPlayer
{
public:
    House();
    bool IsHitting() override;
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