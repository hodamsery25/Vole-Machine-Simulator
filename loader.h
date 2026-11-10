#pragma once
#include<string>
#include<cstdint>
#include<vector>
using namespace std;

class Loader
{
private:
	string lastError;
	bool parseLine(string line, uint16_t& instruction);
public:
	bool loadFile(string filename, vector<uint16_t>& program);
	string getLastError();

};
