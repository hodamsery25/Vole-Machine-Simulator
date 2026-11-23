#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "registers.h"
#include "Memory.h"
#include "screen.h"
#include "loader.h"
#include "cpu.h"

using namespace std;
int main()
{
//cout << "Hello world!" << endl;
  int choice = 0;
  Memory memory;
  Registers registers;
  Screen screen(memory, registers);
  Loader loader(memory, registers);
  Instructions ir ;
  Cpu cpu(memory,registers,ir,screen);
  cpu.reset();

  cout << "\n\t  -< Vole Machine simulator >- \n";
  while(1 == 1){
    cout<< endl;
    screen.displayMenu();
    cout << "\n= Enter your choice : ";
    cin >> choice;
    switch (choice) {
      case 1:{
          cpu.reset();
          if(!loader.loadFile()) break;
          screen.displayStatus();
          cout <<"\n  < File Loaded Successfully! >";
          cout <<"\n  -----------------------------\n";
          break;}
      case 2:
          screen.displayStatus();
          cpu.displayStatus();
          break;
      case 3:{
          int index;
          uint8_t value2;
          string line;
          cout << "  Enter Register number [0~15] : ";
          cin >> index;
          cin.ignore();
          cout << "\n  Enter Value in Hex[0~FF] : ";
          getline(cin,line);
          value2 = static_cast<uint8_t> (stoul(line, nullptr, 16));///
          registers.write(index, value2&0xFF);
          cout <<"\n  < Register Updated Successfully! >";
          cout <<"\n  ----------------------------------\n";
          break;}
      case 4:{
          int address;
          uint8_t value1;
          string line;
          cout << "= Enter Memory cell number [0~255] : ";
          cin >> address;
          cin.ignore();
          cout << "= Enter Value in Hex[0~FF] : ";
          getline(cin,line);
          value1 = static_cast<uint8_t> (stoul(line, nullptr, 16));///
          memory.write(address, value1&0xFF);
          cout <<"\n  < Memory Updated Successfully! >";
          cout <<"\n  --------------------------------\n";
          break;}
      case 5:{
          int pmc = 0;
          cout<<"\n= Set program memory counter to start from: ";
          cin >> pmc;
          if((pmc>=254 || pmc<0)&& pmc%2 != 0) pmc=0;
          cpu.set_pc(pmc);
          cpu.total_run();
          screen.displayStatus();
          screen.display();
          cout << "\n << Program executed to the End >>";
          cout << "\n ---------------------------------\n\n";
          break;}
      case 6:{
          int pmc = 0;
          cout<<"\n= Set program memory counter to start from: ";
          cin >> pmc;
          if((pmc>=254 || pmc<0)&& pmc%2 != 0) pmc=0;
          cpu.set_pc(pmc);
          screen.clear();
          cpu.steps_run();
          cout << "\n << Program execution reached a halt sequence >>";
          cout << "\n -----------------------------------------------\n\n";
          break;}
      case 7:
           system("cls");
           cout << "\n\t  -< Vole Machine simulator >- \n";
           break;
      case 8:
           cout << "\n**Program is Done";
           cout << "\n------------------\n";
           return EXIT_SUCCESS;
           break;
      default:
          cout << "\n**Invalid choice selection";
          cout << "\n--------------------------\n";
          if(cin.fail()) {///##
            cin.clear();   ///##
            cin.ignore(10000, '\n');///##
          }
    }
  }
  return 0;
}

