
#include <iomanip>
#include "registers.h"
#include <iostream>

registers::registers()
{
    n=0;
    value=0;
    clear();
}
uint8_t registers::read (int noc )
{
    n=noc;
    return cells[noc];
}
void registers::display()
{
    cout<<hex<<uppercase<<setfill('0');
    for (int i=0;i<16;i++)
    {
        cout<<setw(2)<<static_cast<int>(cells[i])<<" ";
    }
}
void registers::write(int noc,uint8_t v)
{
    cells[noc] =v;
    n=noc;
}
void registers::clear()
{
    for (int i=0;i<16;i++)
    {
        cells[i]=0;
    }
}
