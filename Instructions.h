#pragma once
#include <cstdint>
using namespace std;
class Instructions{
private:
	uint16_t raw;
public:
	void setRaw(uint16_t value);
	bool isValid();
	int getOpcode();
	int getR();
	int getS();
	int getT();
	int getXY();	
	uint16_t getRaw();
};
