#include "Instructions.h"
#include "ALU.h"
#include "screen.h"
class Cpu {
private:
    Memory& memory;//
    Registers& registers;//
    Instructions& IR;//
    Screen& screen;
    ALU alu;
    int pc;
    bool halted;
public:
    Cpu(Memory& m, Registers& regs, Instructions& ir, Screen& s);
    void reset();
    void set_pc(int address);
    int get_pc();
    void fetch_decode();
    void execute();
    void total_run();
    void steps_run();

};
