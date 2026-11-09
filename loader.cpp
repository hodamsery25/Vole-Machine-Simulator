#include<string>
#include<cstdint>
#include<vector>
#include<iostream>
#include<fstream>
#include"loader.h"
using namespace std;
 bool Loader::loadFile(string filename ,vector<uint16_t>&program){
    ifstream file;
    file.open(filename);
        if(file.is_open()==false){
            lastError="the file not found";
            return false;
        }

    
        string storage;


        while(getline(file,storage)){
            
            uint16_t instruction  ;

            if(parseLine( storage,instruction)==false){

                lastError="the line is Error";
                return false;
            }
            program.push_back(instruction);


        }
            return true;


        
    }
    
 


string Loader::getLastError(){
    return lastError;
}
 bool Loader::parseLine(string line , uint16_t& instruction){
    string Line=line;
        
        size_t position=Line. find(';');

        if(position!=string::npos){
            
            Line=Line.substr(0,position);

        }
        
        while(!line.empty()&&Line[0]==' ')
        {
            Line.erase(0,1);

        }
        
        while (!Line.empty() && Line[Line.length() - 1] == ' ')
        Line.erase(Line.length() - 1, 1);
        

        
        if(Line.length()!=4){
            return false;

        }
        

        for(int i =0;i<4;i++){
            if((Line[i]<'0'||Line[i]>'9')&&(Line[i]<'A'||Line[i]>'F')&&(Line[i]<'a'||Line[i]>'f')){
                return false;


        }
            
        
        instruction=stoul(Line,nullptr,16);
        return true;

        


    }


