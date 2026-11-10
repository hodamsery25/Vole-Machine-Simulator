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
    output.push_back(to_string(value));
}

void Screen::display() {
    int s=output.size();
    if(s != 0){
      cout<<"\n-------------------------------------\n";
      for(int i=0; i<s; i++){
         cout << "\n~~Program Output: "<<output[i];
      }
      cout<<"\n\n-------------------------------------\n";
         output.clear();
    }
}

void Screen::displayMenu() {
    cout << "1. Load Program\n";
    cout << "2. Edit Memory cell\n";
    cout << "3. Edit Register\n";
    cout << "4. Run program\n";
    cout << "5. Run Step by Step\n";
    cout << "6. Display Machine Status\n";
    cout << "7. Clear Screen\n";
    cout << "8. Exit\n";
}

void Screen::displayStatus() {
    cout << hex << uppercase << setfill('0');

    cout << "\n\t        == Registers ==\n";
    cout << "\t     ";
    for (int i = 0; i < 16; i++) {
        cout << "R-" << dec << setw(2) << i << " = " << hex << setw(2) << (int)registers.read(i) << "   ";
        if ((i + 1) % 2 == 0) {
            cout << "\n\t     ";
        }
    }

    cout << "\n             ======  Memory  ======\n";
    for (int i = 0; i < 256; i++) {
        cout << setw(2) << (int)memory.read(i) << " ";
        if ((i + 1) % 16 == 0) {
            cout << "\n";
        }
    }

    cout << dec << setfill(' ');
}
void Screen::clear() {
    output.clear();
}
