#pragma once
#include<string>
#include<cstdint>
#include"Memory.h"
#include"register.h"
class Screen
{
private:
  std::string output;
  Memory& memory;
  registers&registers;
  
   
public:
    void write ( uint8_t value);
    void display();
    void displayMenu();
    void displayStatus();
    void clear();
    Screen(Memory&m,registers&r);
};
