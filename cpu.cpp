#include <iostream>
#include "cpu.h"

Cpu::Cpu(Memory& m,Regesters& regs,Instruction& ir,Screen& s){
    memory = m;
    regesters = regs;
    IR = ir;
    screen = s;
    pc = 0;
    halted = 0;
    }
void Cpu::reset(){
    pc = 0;
    halted = 0;
    IR.setrow(0);///?
    regesters.clear();///?
}
void Cpu::set_pc(int address){
    pc = address;
}
int Cpu::get_pc(){
    return pc;
}

void Cpu::fetch_decode(){
    uint8_t byte1 = memory.read(pc);
    uint8_t byte2 = memory.read(pc+1);
    uint16_t row = (byte1<<8) + byte2;
    IR.set_row(row);
}
void Cpu::execute(){
  int op = IR.getOp();
  int R = IR.getR();
  int xy = IR.getXY();
  switch(op){
    case 1:
        registers.write(R, memory.read(xy));
        break;
    case 2:
        registers.write(R, xy);
        break;
    case 3:
        memory.write(xy, registers.read(r));
        if(xy == 0x00) {
          screen.write(registers.read(r));
        }
        break;
    case 4:
        registers.write(IR.getY(), registers.read(IR.getX()));///????
        break;
    case 5:
        registers.write(R, ALU::add(registers.read(IR.getX()), registers.read(IR.getY())));///need fix
        break;
    case 0xB:
        if(registers.read(R) == registers.read(0)) {
          pc = xy;
        }
        break;
    case 0xC:
        halted = 1;
        break;
  }
}

void Cpu::total_run(){
  while(!halted ){
    fetch_decode()
    pc+=2;
    excute();
  }
}

void Cpu::steps_run(){
  string o;
  while(!halted){
      fetch_decode()
      pc+=2;
      excute();
      screen.displayStatus();
      cin.ignore();
      cout << "\n > Press Enter to continue > ";
      getline(cin,o);
  }
}
