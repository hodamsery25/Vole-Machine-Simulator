#includ "cpu.h"
#include<iostream>

Cpu::Cpu(Memory& m,Regesters& regs,Instruction& ir){
    memory = m;
    regesters = regs;
    IR = ir;
    pc = 0;
    halted = 0;
    }
void Cpu::reset(){
    pc = 0;
    halted = 0;
    IR.setrow(0);///?
    regesters.clear();///?
}
void set_pc(int address){
    pc = address;
}
int get_pc(){
    return pc;
}
    
bool Cpu::fetch_decode(){
    if(pc>=255)return false;//
    uint8_t byte1 = memory.read(pc);
    uint8_t byte2 = memory.read(pc+1);
    uint16_t row = (byte1<<8) + byte2;
    IR.set_row(row);
    return true;// 
}
void execute(){
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


    
    
void total_run(){///Machine?
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

void steps_run()
