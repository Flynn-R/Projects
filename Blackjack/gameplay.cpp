#include "gameplay.h"

// Operators
ostream& operator<<(ostream& out, Card& card)
{
    if (card.isFaceUp)
    {
        switch(card.cardSuit)
        {
            case Heart:
                out << "Heart ";
                break;
            case Spade:
                out << "Spade ";
                break;
            case Diamond:
                out << "Diamond ";
                break;
            case Club:
                out << "Club ";
                break;
            default:;
        }

        switch(card.cardValue)
        {
            case Ace:
                out << "Ace";
                break;
            case Two:
                out << '2';
                break;
            case Three:
                out << '3';
                break;
            case Four:
                out << '4';
                break;
            case Five:
                out << '5';
                break;
            case Six:
                out << '6';
                break;
            case Seven:
                out << '7';
                break;
            case Eight:
                out << '8';
                break;
            case Nine:
                out << '9';
                break;
            case Ten:
                out << "10";
                break;
            case Jack:
                out << "Jack";
                break;
            case Queen:
                out << "Queen";
                break;
            case King:
                out << "King";
                break;
            default:;
        }
    }
    else
        out << "XX";

    return out;
}

ostream& operator<<(ostream& out, GenericPlayer& player)
{
    out << player.name << endl;
    for (auto it = player.cards.begin(); it != player.cards.end(); ++it)
    {
        out << *(*it);
        out << (it + 1 == player.cards.end() ? "\n" : ", ");
    }
    out << player.GetValue() << endl;

    return out;
}

// Class GenericPlayer
GenericPlayer::GenericPlayer(string _name) : name(_name) {}

bool GenericPlayer::IsBoosted() { return (GetValue() > 21); }

void GenericPlayer::Bust() { if (IsBoosted()) cout << name << " is busted!" << endl; }

// Class Deck
Value& operator++(Value& rank)
{
    rank = static_cast<Value>(rank + 1);
    return rank;
}

Suit& operator++(Suit& suit)
{
    suit = static_cast<Suit>(suit + 1);
    return suit;
}

void Deck::Populate()
{
    for (auto i = Ace; i <= King; ++i)
    {
        for (auto j = Heart; j <= Club; ++j)
            Add(new Card(j, i));
    }
}

Deck::Deck() { Populate(); }

void Deck::Shuffle() { random_shuffle(cards.begin(), cards.end()); }

void Deck::Deal(Hand& hand)
{
    if (!cards.empty())
    {
        Card* card = cards.back();
        card->flip();
        hand.Add(card);
        cards.pop_back();
    }
    else
        cout << "Out of cards!" << endl;
}

void Deck::AdditionalCards(GenericPlayer& player)
{
    while(!player.IsBoosted() && player.IsHitting())
    {
        Deal(player);
        cout << player << endl;

        if (player.GetValue() == 21)
            break;

        if (player.IsBoosted())
            player.Bust();
    }
}

// Class Player
Player::Player(string _name) : GenericPlayer(_name) {}

bool Player::IsHitting()
{
    string response;

    do
    {
        cout << "Do you want a hit? (Y/N): ";
        getline(cin, response);

        if (response.length() > 1)
            cout << "Incorrect input." << endl << endl;
        else
        {
            if (response[0] == 'y' || response[0] == 'Y')
                return true;
        }

    } while (response[0] != 'N' && response[0] != 'n');

    return false;
}

void Player::Win() const { cout << name << " wins!" << endl; }

void Player::Lose() const { cout << name << " loses!" << endl; }

void Player::Push() const { cout << name << " pushed!" << endl; }

// Class House
House::House() : GenericPlayer("House") {}

bool House::IsHitting() { return GetValue() <= 16; }

void House::FlipFirstCard() { cards[0]->flip(); }

// Class Game
Game::Game(const vector<string>& player_names)
{
    srand(static_cast<unsigned int>(time(0)));
    for (const auto& it : player_names)
        players.push_back(Player(it));

    deck.Shuffle();
}

void Game::Play()
{
    for (auto& it : players)
    {
        deck.Deal(it);
        deck.Deal(it);
    }

    deck.Deal(house);
    deck.Deal(house);
    house.FlipFirstCard();

    for (auto& it : players)
        cout << it << endl << endl;
    cout << house << endl << endl;

    for (auto& it : players)
        deck.AdditionalCards(it);
    house.FlipFirstCard();
    deck.AdditionalCards(house);

    for (auto& it : players)
    {
        if (!it.IsBoosted())
        {
            if (it.GetValue() > house.GetValue())
                it.Win();
            else if (house.GetValue() == it.GetValue())
                it.Push();
            else
                it.Lose();
        }
        else if (house.IsBoosted())
            it.Push();
        else
            it.Lose();

        it.Clear();
    }
    house.Clear();

    system("pause");
}