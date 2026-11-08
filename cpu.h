#ifndef _CPU_H
#define _CPU_H
#ifndef _REGISTER_H
#define _REGISTER_H
#include <cstdint>

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
    bool fetch_decode();
    void execute();
};
#endif
class registers{
private:
    int n;
    uint8_t cells [16];
    uint8_t value;
public:

    uint8_t read (int noc );
    void display();
    void write(int noc,uint8_t v);
    void clear ();


};
#endif




