#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include "loader.h"
using namespace std;

bool Loader::parseLine(string line, uint16_t& instruction) {

    size_t pos = line.find(';');
    if (pos != string::npos) {
        line = line.substr(0, pos);
    }

    while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
        line.erase(0, 1);
    }

    while (!line.empty() && (line[line.length() - 1] == ' ' ||
                             line[line.length() - 1] == '\t' ||
                             line[line.length() - 1] == '\r')) {
        line.erase(line.length() - 1, 1);
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

    instruction = stoul(line, nullptr, 16);
    return true;
}

bool Loader::loadFile(string filename, vector<uint16_t>& program) {

    ifstream file(filename);
    if (!file.is_open()) {
        lastError = "the file not found";
        return false;
    }

    string line;
    while (getline(file, line)) {

        while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
            line.erase(0, 1);
        }

        if (line.empty() || line[0] == ';' || line[0] == '\r') {
            continue;
        }

        uint16_t instruction;
        if (!parseLine(line, instruction)) {
            lastError = "the line is Error";
            return false;
        }

        program.push_back(instruction);
    }

    return true;
}

string Loader::getLastError() {
    return lastError;
}
