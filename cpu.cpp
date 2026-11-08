#includ "cpu.h"
#include "cpu.h"

#include<iostream>
#include <iomanip>
#include "registers.h"
#include "memory.h"

cpu::cpu(Memory& m, Screen& s){
    memory = m;
    screen = s;
    pc = 0;
    halted = 0;
    }
bool cpu::fetch_decode(){
    if(pc>=255)return false;
    uint8_t byte1 = memory.read(pc);
    uint8_t byte2 = memory.read(pc+1);
    uint16_t row = (byte1<<8) + byte2;
    ir.set_row(row);
    return true; 
}
void cpu::execute(){
  int op = ir.getOp();
  int R = ir.getR();
  int xy = ir.getXY();
  switch(op){
    case 1: 
        registers.write(r, memory.read(xy));
        break;
    case 2: 
        registers.write(r, xy);
        break;
    case 3:
        memory.write(xy, registers.read(r));
        if(xy == 0x00) { 
          screen.write(registers.read(r));
        }
        break;
    case 4: 
        registers.write(ir.getY(), registers.read(ir.getX()));///????
        break;
    case 5: 
        registers.write(r, ALU::add(registers.read(ir.getX()), registers.read(ir.getY())));
        break;
    case 0xB: // Jump to XY if R == R0
        if(registers.read(r) == registers.read(0)) {
          pc = xy;
        }
        break;
    case 0xC: // Halt execution loop
        halted = 1;
        break;
  }
}
void cpu::reset(){
    pc = 0;
    halted = 0;
    ir.setrow(0);///?
    regesters.clear();///?
}
    
    
void cpu::total_run(){///Machine?
  bool error = 0;
  while(!halted && ir.isvalid){
    if(!fetch()){
      error = 1;
      cout << "**Erorr: Memory index out of range >> File Rejected\n "; 
      break; 
    }
    if(!ir.isvalid()){
      error = 1;
      cout << "**Erorr: Invalid instruction >> File Rejected\n ";
      break;
    } 
    pc+=2;
    excute();
  }
  if(error) //menue
}
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
memory::memory()
{
    index=0;
    value=0;
    clear();
}
uint8_t memory::read (int i)
{
    if (index<0||index>255)return 0;
    index=i;
    return cells[index];
    //cout<<(int)obj1.read(index) for printing;
}
void memory:: write(int i,uint8_t v)
{
    if (index<0||index>255) return 0;
    index=i;
    value=v;
    cells[index]=value;
}
void memory::clear()
{
    for (int i=0;i<255;i++)
    {
        cells[i]=0;
    }
}