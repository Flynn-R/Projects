#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <conio.h>

class Menu
{
protected:
    std::map<unsigned int, std::string> options;
    std::map<unsigned int, std::string>::iterator pointer;
public:
    Menu(std::vector<std::string>&);
    virtual int selection(const std::string&);
    virtual ~Menu();
};