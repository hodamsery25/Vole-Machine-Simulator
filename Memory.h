//
// Created by iprahim on 09/11/2026.
//

#ifndef VOLE_MACHINE_SIMULATOR_MEMORY_H
#define VOLE_MACHINE_SIMULATOR_MEMORY_H
#include <cstdint>

class Memory
{
private:
    uint8_t cells[256];
    int index;
    uint8_t value;
public:
    uint8_t read (int i);
    void write(int i,uint8_t v);
    void clear();
};
#endif //VOLE_MACHINE_SIMULATOR_MEMORY_H
