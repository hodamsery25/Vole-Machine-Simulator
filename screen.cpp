#pragma once
#include<string>
#include<cstdint>
#include<vector>
#include<iostream>
#include"screen.h"
using namespace std;

    void Screen::write(uint8_t value)
    {
        string output="value";

    }

    void Screen::display(){
        cout<<output;

    }

    void Screen::displayMenu(){
       cout<<"1. Load Program\n";
       cout<<"2. Edit Memory\n";
       cout<<"3. Edit Register\n";
       cout<<"4. Run prgram\n";
       cout<<"5. Run Step by Step\n";
       cout<<"6. Display Machine Status\n";
        cout<<"7. Clear Screen\n";
       cout<<"8. Exit\n";


    }

    void Screen::displayStatus(){


    }

    void Screen::clear(){
        output.clear();

    }
