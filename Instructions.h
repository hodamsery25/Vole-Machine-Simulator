#pragma once
#include <cstdint>
using namespace std;
class Instructions {
private:
	uint16_t raw;
public:
	void setRaw(uint16_t value);
	bool isValid();
	int getOpcode();
	int getR();
	int getX();
	int getY();
	int getXY();
	uint16_t getRaw();
};
