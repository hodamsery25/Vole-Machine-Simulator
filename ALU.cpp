#include "ALU.h"
#include <iostream>
uint8_t ALU::add(uint8_t a, uint8_t b) {
	return a + b;
}

uint8_t ALU::addfloat(uint8_t a, uint8_t b) {
	return  (uint8_t)((float)a + (float )b);
}

uint8_t ALU::bitOr(uint8_t a, uint8_t b) {
	return a | b;
}

uint8_t ALU::bitAnd(uint8_t a, uint8_t b) {
	return a & b;
}

uint8_t ALU::bitXor(uint8_t a, uint8_t b) {
	return a ^ b;
}
