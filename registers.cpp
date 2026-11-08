
#include <iomanip>
#include "registers.h"

registers::registers()
{
    n=0;
    value=0;
    clear();
}
uint8_t registers::read (int noc )
{
    if (noc<1||noc>16)return 0;
    n=noc;
    return cells[noc-1];
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
    if (noc<1) noc=1;
    if (noc>16) return;
    cells[noc-1] =v;
    n=noc;
}
void registers::clear()
{
    for (int i=0;i<16;i++)
    {
        cells[i]=0;
    }
}
