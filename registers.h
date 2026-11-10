#pragma once
#include <cstdint>

class Registers {
private:
    int n;
    uint8_t cells[16];
    uint8_t value;
public:
    Registers();
    uint8_t read(int noc);
    void display();
    void write(int noc, uint8_t v);
    void clear();


};
