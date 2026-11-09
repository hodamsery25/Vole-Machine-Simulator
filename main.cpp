#include "screen.h"
#include "loader.h"
#include "cpu.h"
#include "Memory.h"
#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
  int choice = 0;
  Memory memory;
  Screen screen;
  Cpu cpu;
  cout << "  \t\t-< Vole Machine simulator >- \n\n";
  While(/*under constructio*/){
    screen.displayMenu();
    cout << "\n>>Enter your choice : ";
    cin >> choice;
    switch (choice) {
      case 1:
          cpu.reset();
          loadFile(/*under constructio*/); break;
      case 2:
          int address;
          uint8_t value;
          cout << "  Enter Memory cell number in Hex[0~‣FF] : ";
          cin >> hex >> address;
          cout << "\n  Enter Value in Hex[0~‣FF] : ";
          cin >> hex >> value;
          memory.write( address, value);
          break;
      case 3:
          int index;
          uint8_t value;
          cout << "  Enter Register number in Hex[0~‣F] : ";
          cin >> hex >> index;
          cout << "\n  Enter Value in Hex[0~‣FF] : ";
          cin >> hex >> value;
          registers.write(index, value);
      case 4:
          cpu.total_run(/*under constructio*/);
          cout << "\n<< Program executed to the End >>\n";
          break;
      case 5:
          cpu.steps_run(/*under constructio*/);
          cout << "\n<< Program execution reached a halt sequence >>\n";
          break;
      case 6:
          screen.displayStatus();
          break;
      case 7:
           system("cls"); 
           cout << "  \t\t-< Vole Machine simulator >- \n\n";
           break;
      case 8:
           cout << "\n**Program is Done\n";
           return EXIT_SUCCESS;
           break;
      default:
          cout << "**Invalid choice selection\n";
    }
  }
  return 0;
}
