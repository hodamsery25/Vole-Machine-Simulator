#include <iostream>
#include "cpu.h"

Cpu::Cpu(Memory& m, Registers& regs, Instructions& ir, Screen& s) : memory(m), registers(regs), IR(ir), screen(s) {
    pc = 0;
    halted = false;
}
void Cpu::reset() {
    pc = 0;
    halted = 0;
    IR.setRaw(0);
    registers.clear();
}
void Cpu::set_pc(int address) {
    pc = address;
}

void Cpu::fetch_decode() {
    uint8_t byte1 = memory.read(pc);
    uint8_t byte2 = memory.read(pc + 1);
    uint16_t raw = (byte1 << 8) + byte2;
    IR.setRaw(raw);
}
void Cpu::execute() {
    int op = IR.getOpcode();
    int R = IR.getR();
    int xy = IR.getXY();
    int X = IR.getX();
    int Y = IR.getY();
    switch (op) {
    case 0x1:
        registers.write(R, memory.read(xy));
        break;
    case 0x2:
        registers.write(R, xy);
        break;
    case 0x3:
        memory.write(xy, registers.read(R));
        if (xy == 0x00) {
            screen.write(registers.read(R));
        }
        break;
    case 0x4:
        registers.write(IR.getY(), registers.read(IR.getX()));
        break;
    case 0x5:
        registers.write(R, alu.add(registers.read(IR.getX()), registers.read(IR.getY())));
        break;
    case 0x6:
        registers.write(R, alu.addfloat(registers.read(X), registers.read(Y)));
        break;

    case 0x7:
        registers.write(R, alu.bitOr(registers.read(X), registers.read(Y)));
        break;

    case 0x8:
        registers.write(R, alu.bitAnd(registers.read(X), registers.read(Y)));
        break;
    case 0x9:
        registers.write(R, alu.bitXor(registers.read(X), registers.read(Y)));
        break;

    /*case 0xA:
        registers.write(R, alu.rotateRight(registers.read(R), X));
        break;*/
    case 0xB:
        if (registers.read(R) == registers.read(0)) {
            pc = xy;
        }
        break;
    case 0xC:
        halted = 1;
        break;
    }
}

void Cpu::total_run() {
    while (!halted) {
        fetch_decode();
        pc += 2;
        execute();
    }
}

void Cpu::steps_run() {
    string o;
    while (!halted) {
        fetch_decode();
        pc += 2;
        execute();
        screen.displayStatus();
        cin.ignore();
        cout << "\n > Press Enter to continue > ";
        getline(cin, o);
    }
}
void Cpu::displayStatus(){
    cout <<"\n Current Program counter: "<< pc;
}