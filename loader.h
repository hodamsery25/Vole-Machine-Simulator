#pragma once
#include<string>
#include<cstdint>
#include<vector>
#include "Memory.h"
#include "registers.h"
using namespace std;

class Loader
{
private:
    Registers& registers;
    Memory& memory;
	string filename;
	bool parseLine(string line, uint16_t& instruction);
public:
    Loader(Memory& m, Registers& r);
	bool loadFile();


};
