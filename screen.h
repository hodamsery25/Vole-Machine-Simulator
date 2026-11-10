#pragma once
#include<string>
#include<cstdint>
#include"Memory.h"
#include "registers.h"
using namespace std;
class Screen
{
private:
    string output;
    Memory& memory;
    Registers& registers;


public:
    void write(uint8_t value);
    void display();
    void displayMenu();
    void displayStatus(Registers& r, Memory& m);
    void clear();
    Screen(Memory& m, Registers& r);
};
