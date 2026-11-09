//
// Created by iprahim on 09/11/2026.
//

#include "Memory.h"
#include <iostream>
Memory::Memory()
{
    index=0;
    value=0;
    clear();
}
uint8_t Memory::read (int i)
{
    index=i;
    return cells[index];
    //cout<<(int)obj1.read(index) for printing;
}
void Memory:: write(int i,uint8_t v)
{
    index=i;
    value=v;
    cells[index]=value;
}
void Memory::clear()
{
    for (int i=0;i<256;i++)
    {
        cells[i]=0;
    }
}
