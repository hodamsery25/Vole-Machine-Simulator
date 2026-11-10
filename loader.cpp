#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <iostream>
#include "loader.h"
using namespace std;
Loader::Loader(Memory& m, Registers& r):memory(m),registers(r){filename = "";}

bool Loader::parseLine(string line, uint16_t& instruction) {

    size_t pos = line.find(';');
    if (pos != string::npos) {
        line = line.substr(0, pos);
    }
    while (!line.empty() && (line.back() == '\r' || line.back() == ' ' || line.back() == '\t')) {
        line.pop_back();
    }
    while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
        line.erase(0, 1);
    }
    if (line.empty()) {
        instruction = 0xFFFF;
        return true;
    }

    if (line.length() != 4) {
        return false;
    }

    int i = 0;
    while (i < 4) {
        char c = line[i];
        bool digit = (c >= '0' && c <= '9');
        bool upper = (c >= 'A' && c <= 'F');
        bool lower = (c >= 'a' && c <= 'f');

        if (!digit && !upper && !lower) {
            return false;
        }
        i++;
    }

    instruction = static_cast<uint16_t>(stoul(line, nullptr, 16));
    return true;
}

bool Loader::loadFile() {

    cout<<"= Enter File Name : ";
    cin.ignore(10000, '\n');///
    getline(cin,filename);///
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "\n**Error: File not found >> File Rejected\n\n";
        memory.clear();
        registers.clear();
        return false;
    }
    int address=0;

    string line;
    while (getline(file, line)) {

        while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
            line.erase(0, 1);
        }
        while (!line.empty() && (line.back() == '\r' || line.back() == ' ' || line.back() == '\t')) {
            line.pop_back();
        }

        if (line.empty() || line[0] == ';' || line[0] == '\r') {
            continue;
        }

        uint16_t instruction;
        if (!parseLine(line, instruction)) {
            cout << "\n**Error: Line invalid >> File Rejected\n\n";
            memory.clear();
            registers.clear();
            file.close();
            return false;
        }
         if (instruction == 0xFFFF) {
            continue;
        }
        if (address+1>255) {
            cout<<"\n**Error: program is too large >> File Rejected\n\n";
            memory.clear();
            registers.clear();
            file.close();
            return false;
        }

        memory.write(address, (instruction >> 8) & 0xFF);
        memory.write(address + 1, instruction & 0xFF);
        address+=2;
    }
    file.close();
    return true;
}

