//2.sorted_array_main.cc
#include "sorted_array.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    
    SortedArray *sortedarray = new SortedArray();
    
    string numbers;
    getline(cin,numbers);
    
    while(numbers.find(" ")!=string::npos){
        size_t index = numbers.find(" ");
        int number = stoi(numbers.substr(0,index));
        sortedarray->AddNumber(number);
        numbers.erase(0,index+1);
    }
    size_t index = numbers.find(" ");
    int number = stoi(numbers.substr(0,index));
    sortedarray->AddNumber(number);
    numbers.erase(0,index+1);
    
    while(true){
        string command;
        getline(cin,command);
    
        if(isdigit(command[0])){

            while(command.find(" ")!=string::npos){
                size_t index = command.find(" ");
                int number = stoi(command.substr(0,index));
                sortedarray->AddNumber(number);
                command.erase(0,index+1);
            }
            size_t index = command.find(" ");
            int number = stoi(command.substr(0,index));
            sortedarray->AddNumber(number);
            command.erase(0,index+1);
            
        }
        
        else{
            if(command == "ascend"){
                size_t SIZE = sortedarray->GetSize();
                for(int i = 0 ; i < SIZE ; i++){
                    sortedarray->GetSortedAscending();
                    cout << sortedarray->GetElement(i) << " ";
                }
                cout << endl;
            }
    
            else if(command == "descend"){
                size_t SIZE = sortedarray->GetSize();
                for(int i = 0 ; i < SIZE ; i++){
                    sortedarray->GetSortedDescending();
                    cout << sortedarray->GetElement(i) << " ";
                }
                cout << endl;
            }
    
            else if(command == "max"){
                cout << sortedarray->GetMax() << endl;
            }
    
            else if(command == "min"){
                cout << sortedarray->GetMin() << endl;
            }
    
            else if(command == "quit"){
                return 0;
            }
        }
    }
}

