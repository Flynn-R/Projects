#pragma once
#include <vector>
#include <map>
#include <iostream>

#define ADD_HUMAN_OR_MALE 1
#define ADD_CAT_OR_FEMALE 2
#define RM_HUMAN_OR_BACK 3
#define RM_CAT 4
#define EXIT 5

#define MALE 

using namespace std;

class MainMenu
{
private:
    const vector<string> mainMenuList
    {
        "Hello!", "Add a human", "Add a cat",
        "Remove a human", "Remove a cat",
        "Exit"
    };
protected:
    map<unsigned short, string> options;
public:
    MainMenu();
    unsigned short selection();
    virtual ~MainMenu();
};

class GenderMenu : public MainMenu
{
private:
    const vector<string> genderList
    {
        "Select gender:", "Male", "Female", "Back"
    };
public:
    GenderMenu();
    ~GenderMenu() = default;
};