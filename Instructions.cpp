#include "Instructions.h"
#include <iostream>
void Instructions :: setRaw(uint16_t value) {
	raw = value;
}

bool Instructions :: isValid() {
	int digit_1 = raw / 4096;
	//recheck wich instructions do we offer in this system and which do we not (important)
	if ((digit_1 >= 1 && digit_1 <= 8) || digit_1 == 11 || digit_1 == 12)
		return true;
	else
		return false;
}

int Instructions :: getOpcode() {
	return raw / 4096;
}

int Instructions::getR() {
	return (raw / 256) % 16;
}

int Instructions::getX() {	
	return (raw / 16) % 16;
}

int Instructions::getY() {
	return raw % 16;
}

int Instructions::getXY() {
	return raw % 256;
}

uint16_t Instructions::getRaw() {
	return raw;
}
