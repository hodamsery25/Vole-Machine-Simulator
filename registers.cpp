#include <iostream>
#include <iomanip>
#include "registers.h"

using namespace std;
Registers::Registers()
{
    value = 0;
    clear();
}
uint8_t Registers::read(int noc)
{
    return cells[noc];
}
void Registers::write(int noc, uint8_t v)
{
    cells[noc] = v;
}
void Registers::clear()
{
    for (int i = 0;i < 16;i++)  cells[i] = 0;
}
