
#include "minesweeper.h"

using namespace std;

int main(){
    
    Minesweeper *minesweeper = new Minesweeper();
    
    while(true){
        
        vector<string> MAP;
        string command;
        
        getline(cin,command);
        
        if(command.find(":set")!=string::npos){
            
            MAP.clear();
            
            size_t x,y;
            
            command.erase(0,5);
            size_t ind = command.find(" ");
            
            x = stoi(command.substr(0,ind));
            command.erase(0,ind+1);
            y = stoi(command);
            
            for(size_t i = 0 ; i < y ; i++){
                string row;
                getline(cin,row);
                MAP.push_back(row);
            }
            
            minesweeper->setMap(x,y,MAP);
        }
        
        else if(command==":play"){
            
            minesweeper->setPlay();
        }
        
        else if(command.find(":touch")!=string::npos){
            
            int x,y;
            
            command.erase(0,7);
            size_t ind = command.find(" ");
            
            x = stoi(command.substr(0,ind));
            command.erase(0,ind+1);
            y = stoi(command);
            
            if(minesweeper->touchMap(x,y)){
                cout << "DEAD(" << minesweeper->touchCount() + 1 << ")" << endl;
            }
            
        }
        
        else if(command.find(":toggle")!=string::npos){
            
            size_t x,y;
            
            command.erase(0,8);
            size_t ind = command.find(" ");
            
            x = stoi(command.substr(0,ind));
            command.erase(0,ind+1);
            y = stoi(command);
            
            minesweeper->toggleMine(x,y);
    
        }
        
        else if(command == ":quit"){
            
            return 0;
            
        }
        
    }
}

