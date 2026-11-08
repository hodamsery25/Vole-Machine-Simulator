#pragma once

#include <iostream>//at first header which will be included her

class Cpu{
private:
    Memory& memory;//
    Screen& screen;//
    Regesters& regesters;//
    Instruction& IR;//
    int pc;
    bool halted;
public:
    Cpu(Memory& m,Regesters& regs,Instruction& ir);
    void total_run();///Machine?
    void reset();
    void set_pc(int address);
    bool fetch_decode()
    void execute();

};




