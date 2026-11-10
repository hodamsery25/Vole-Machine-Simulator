#include<string>
#include<cstdint>
#include<vector>
#include<iomanip>
#include<iostream>
#include"screen.h"
using namespace std;

Screen::Screen(Memory& m, Registers& r) : memory(m), registers(r) {
}

void Screen::write(uint8_t value)
{
    output = to_string(value);
}

void Screen::display() {
    cout << output;
}

void Screen::displayMenu() {
    cout << "1. Load Program\n";
    cout << "2. Edit Memory\n";
    cout << "3. Edit Register\n";
    cout << "4. Run prgram\n";
    cout << "5. Run Step by Step\n";
    cout << "6. Display Machine Status\n";
    cout << "7. Clear Screen\n";
    cout << "8. Exit\n";
}

void Screen::displayStatus(Registers& r, Memory& m) {
    cout << hex << uppercase << setfill('0');

    cout << "\n===== Registers =====\n";
    for (int i = 0; i < 16; i++) {
        cout << "R" << dec << i << " = " << hex << setw(2) << (int)r.read(i) << "   ";
        if ((i + 1) % 4 == 0) {
            cout << "\n";
        }
    }

    cout << "\n===== Memory =====\n";
    for (int i = 0; i < 256; i++) {
        cout << setw(2) << (int)m.read(i) << " ";
        if ((i + 1) % 16 == 0) {
            cout << "\n";
        }
    }

    cout << dec << setfill(' ');
}
void Screen::clear() {
    output.clear();
}
