#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum Gender { Male, Female };

class Entity
{
protected:
    Gender gender;
    string name;
    unsigned short age;
public:
    Entity(Gender, string, unsigned short);
    unsigned short getAge();
    virtual Gender getGender() = 0;
    virtual ~Entity();

    friend bool operator==(Entity&, Entity&);
};

class Human : public Entity
{
public:
    Human(Gender, string, unsigned short);
    Gender getGender() override;
    ~Human() = default;
};

class Man : public Human
{
public:
    Man(Gender, string, unsigned short);
    ~Man();
};

class Woman : public Human
{
public:
    Woman(Gender, string, unsigned short);
    ~Woman();
};

class Cat : public Entity
{
public:
    Cat(Gender, string, unsigned short);
    Gender getGender() override;
    ~Cat() = default;
};

class Cat_Male : public Cat
{
public:
    Cat_Male(Gender, string, unsigned short);
    ~Cat_Male();
};

class Cat_Female : public Cat
{
public:
    Cat_Female(Gender, string, unsigned short);
    ~Cat_Female();
};

template<class A> class Population
{
private:
    vector<A> entities;
public:
    Population() = default;
    void addEntity(A entity) { entities.push_back(entity); }
    void removeEntity(A entity)
    {
        for (auto it = entities.begin(); it != entities.end(); ++it)
        {
            if (*it == entity)
            {
                entities.erase(it);
                return;
            }
        }

        cout << "The entity was not found!" << endl;
    }
    ~Population() { cout << "Apocalypse!" << endl; }
};