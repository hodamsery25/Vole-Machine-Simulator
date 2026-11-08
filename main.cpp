#include "screen.h"
#include "loader.h"
#include "cpu.h"
#include "Memory.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
cout << "Hello world!" << endl;
  int choice = 0;
  Memory memory;
  Screen screen;
  Cpu cpu;
  cout << "  \t\t-< Vole Machine simulator >- \n\n";
  While(){
    screen.displayMenu();
    cout << "\n  Enter your choice : ";
    cin >> choice;
    switch (choice) {
      case 1:
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
          total_run(/*under constructio*/);
          break;
      case 5: 
          steps_run(/*under constructio*/);
          break;
      case 6: 
          screen.displayStatus(); 
          break;
      case 7:
           cout << "\n**Program is Done\n";
           return EXIT_SUCCESS;
           break;
      default: 
          cout << "Invalid choice selection.\n";
    }
  }

    //cin>> q;
    /*if (q=='q') system("cls"); *////#####
  return 0;
}
