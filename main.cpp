#include "screen.h"
#include "loader.h"
#include "cpu.h"
#include "Memory.h"
#include "registers.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
cout << "Hello world!" << endl;
  int choice = 0;
  Memory memory;
  Registers registers;
  Instructions ir;
  Screen screen(memory, registers);
  Cpu cpu(memory,registers,ir,screen);

  cpu.reset();
  memory.clear();

  cout << "  \t\t-< Vole Machine simulator >- \n\n";
  while(1 == 1){
    screen.displayMenu();
    cout << "\n= Enter your choice : ";
    cin >> choice;
    switch (choice) {
      case 1:
          cpu.reset();
          //loadFile(/*under constructio*/); break;
      case 2:
          int address;
          uint8_t value1;
          cout << "= Enter Memory cell number in Hex[0~FF] : ";
          cin >> hex >> address;
          cout << "= Enter Value in Hex[0~FF] : ";
          cin >> hex >> value1;
          memory.write( address, value1);
          break;
      case 3:
          int index;
          uint8_t value2;
          cout << "  Enter Register number in Hex[0~F] : ";
          cin >> hex >> index;
          cout << "\n  Enter Value in Hex[0~‣FF] : ";
          cin >> hex >> value2;
          registers.write(index, value2);
      case 4:
          cpu.total_run(/*under constructio*/);
          cout << "\n  << Program executed to the End >>\n\n";
          break;
      case 5:
          cpu.steps_run(/*under constructio*/);
          cout << "\n  << Program execution reached a halt sequence >>\n\n";
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

