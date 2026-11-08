#pragma once

#include <iostream>//at first header which will be included her

class Cpu{
private:
    Memory& memory;//
    Screen& screen;//
    Regesters regesters;//
    Instruction ir;//
    int pc;
    bool halted;
public:
    Cpu(Memory& m, Screen& s);
    void total_run();///Machine?
    void reset();
    void set_pc(int address);
    bool fetch_decode()
    void execute();

};




