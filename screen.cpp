#include<iostream>
#include<iomanip>
#include<cstdint>
#include<vector>
#include<string>
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
    cout << "1. Load New Program    2. Display Machine Status\n";
    cout << "3. Edit Register       4. Edit Memory cell\n";
    cout << "5. Run program         6. Run Step by Step\n";
    cout << "7. Clear Screen        8. Exit\n";

}

void Screen::displayStatus() {
    cout << hex << uppercase << setfill('0');

    cout << "\n\t        == Registers ==\n";
    cout << "\t     ";
    for (int i = 0; i < 16; i++) {
        cout << "R-"  << setw(2) << i << " = "<< setw(2) << (int)registers.read(i) << "   ";
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
