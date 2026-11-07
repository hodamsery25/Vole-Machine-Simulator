#ifndef _CPU_H
#define _CPU_H
#include <iostream>

class cpu{
private:
    Memory& memory;//
    Screen& screen;//
    Regesters regesters;//
    Instruction ir;//
    int pc;
    bool halted;
public:
    cpu(Memory& m, Screen& s);
    void total_run();///Machine?
    void reset();
    bool fetch_decode()
    void execute();
};
#endif
