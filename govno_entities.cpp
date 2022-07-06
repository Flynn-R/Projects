#include "govno_entities.h"

// class Entity
Entity::Entity(Gender _gender, string _name, unsigned short _age) :
gender(_gender), name(_name), age(_age) {}
unsigned short Entity::getAge() { return age; }
Entity::~Entity() { cout << " has diead!" << endl; }

// class Human
Human::Human(Gender _gender, string _name, unsigned short _age) :
Entity(_gender, _name, _age) {}
Gender Human::getGender()
{
    cout << (gender == Male ? "Man" : "Woman") << endl;
    return gender;
}

// class Man
Man::Man(Gender _gender, string _name, unsigned short _age) : Human(_gender, _name, _age) {}
Man::~Man() { cout << "Man, named " << name; }

// class Woman
Woman::Woman(Gender _gender, string _name, unsigned short _age) : Human(_gender, _name, _age) {}
Woman::~Woman() { cout << "Woman, named " << name; }

// class Cat
Cat::Cat(Gender _gender, string _name, unsigned short _age) :
Entity(_gender, _name, _age) {}
Gender Cat::getGender()
{
    cout << (gender == Male ? "Male" : "Female") << endl;
    return gender;
}

// class Cat_Male
Cat_Male::Cat_Male(Gender _gender, string _name, unsigned short _age) : Cat(_gender, _name, _age) {}
Cat_Male::~Cat_Male() { cout << "Male cat, named" << name; }

// class Cat_Female
Cat_Female::Cat_Female(Gender _gender, string _name, unsigned short _age) : Cat(_gender, _name, _age) {}
Cat_Female::~Cat_Female() { cout << "Female cat, named" << name; }

// operator '==' overload
bool operator==(Entity& entity1, Entity& entity2)
{
    if (entity1.name == entity2.name)
    {
        if (entity1.age == entity2.age)
        {
            if (entity1.gender == entity2.gender)
                return true;
        }
    }

    return false;
}