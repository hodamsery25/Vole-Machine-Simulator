#pragma once
#include <iostream>//at first header which will be included her

class Cpu{
private:
    Memory& memory;//
    Regesters& regesters;//
    Instruction& IR;//
    Screen& screen;
    int pc;
    bool halted;
public:
    Cpu(Memory& m,Regesters& regs,Instruction& ir,Screen& s);
    void reset();
    void set_pc(int address);
    int get_pc();
    bool fetch_decode();
    void execute();
    void total_run();
    void steps_run();
};




