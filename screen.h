#pragma once
#include<string>
#include<cstdint>
class Screen
{
private:
  std::string output;
   
public:
    void write ( uint8_t value);
    void display();
    void displayMenu();
    void clear();
};
