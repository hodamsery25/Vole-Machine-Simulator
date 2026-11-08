#pragma once
#include<string>
#include<cstdint>
class Screen
{
private:
  std::string output;
  Memory& memory;
  Registers&registers;
  Cpu&cpu;
   
public:
    void write ( uint8_t value);
    void display();
    void displayMenu();
    void displayStatus();
    void clear();
    Screen(Memory&m,Registers&r);
};