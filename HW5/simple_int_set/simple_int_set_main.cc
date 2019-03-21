
//1.simple_int_set_main.cc
#include <iostream>
#include <stdlib.h>
#include <set>
#include "simple_int_set.h"

using namespace std;

enum EOperateType
{
    Invalid = -1,
    
    Add,
    Sub,
    Mul,
    Print,
};
typedef enum EOperateType OperateType;

int main(void)
{
    while(true)
    {
        SimpleIntSet simpleintset;
        
        string inputs;
        getline(cin, inputs);
        
        if(inputs == "0") break;
        
        string *argv = new string[inputs.length()]; // more than count
        string token;
        size_t pos;
        int argc = 0;
        
        while(true)
        {
            pos = inputs.find(' ');
            token = inputs.substr(0, pos);
            
            argv[argc++] = token;
            
            if(pos >= inputs.length()) break;
            else inputs.erase(0, pos + 1);
        }
        
        set<int> left;
        set<int> right;
        set<int> elements;
        
        int elementCount = 0;
        OperateType type = Invalid;
        
        for(int i=0; i<argc; ++i)
        {
            string arg = argv[i];
            if(arg == "{" && elements.empty()) continue;
            else if(isdigit(arg[arg.length() - 1])) elements.insert(atoi(arg.c_str()));
            
            
            else if(arg == "}")
            {
                if(left.empty()) left = elements;
                else if(right.empty()) right = elements;
                
                elements.clear();
                elementCount = 0;
                
                if(type == Invalid) type = Print;
            }
            else if(arg == "+") type = Add;
            else if(arg == "-") type = Sub;
            else if(arg == "*") type = Mul;
        }
        
        switch(type)
        {
            case Add:
                elements = simpleintset.SetUnion(left,right); break;
            case Sub:
                elements = simpleintset.SetDifference(left,right); break;
            case Mul:
                elements = simpleintset.SetIntersection(left,right); break;
            default: break;
        }
        if(type != Invalid) simpleintset.printSet(elements);
        
        delete[] argv;
        
        left.clear();
        right.clear();
    }
    return 0;
}

