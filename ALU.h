#pragma once
#include <cstdint>
using namespace std;
class ALU {
public:
	uint8_t add(uint8_t a, uint8_t b);
	uint8_t addfloat(uint8_t a, uint8_t b);
	uint8_t bitOr(uint8_t a, uint8_t b);
	uint8_t bitAnd(uint8_t a, uint8_t b);
	uint8_t bitXor(uint8_t a, uint8_t b);
};
