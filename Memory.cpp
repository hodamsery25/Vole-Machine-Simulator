#include <iostream>
#include "Memory.h"

Memory::Memory()
{
    clear();
}
uint8_t Memory::read(int i)
{
    return cells[i];
}

void Memory::write(int i, uint8_t v)
{
    cells[i] = v;
}
void Memory::clear()
{
    for (int i = 0;i < 256;i++) cells[i] = 0;
}
