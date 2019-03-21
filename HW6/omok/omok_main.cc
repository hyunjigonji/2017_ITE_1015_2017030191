
#include "omok.h"

using namespace std;

int main(){
    Omok* omok = new Omok();
    int winner = NOBODY;
    while(true){
        int x,y;
        cin >> x >> y;
        
        int result = omok->Put(y,x);
        
        if(result==NOBODY){
            cout << "Can not be placed there" << endl;
        }
        else{
            omok->isOmok(&winner);
            if(winner == BLACK){
                operator<<(cout,*omok);
                cout << "Winner: Black player" << endl;
                break;
            }
            else if(winner == WHITE){
                operator<<(cout,*omok);
                cout << "Winner: White player" << endl;
                break;
            }
        }
    }
    
    return 0;
}

/*
//2.point2d_main.cc
#include "point2d.h"
#include <iostream>
#include <ctype.h>

using namespace std;

int main(){
    vector<pair<string,Point> > points;
    
    while(true){
        string command;
        getline(cin,command);
    
        if(command.find("set") != string::npos){
            size_t firstInd = command.find(" ");
            command.erase(0,firstInd+1);
            
            size_t secondInd = command.find(" ");
            string name = command.substr(0,secondInd);
            command.erase(0,secondInd+1);
            
            size_t thirdInd = command.find(" ");
            int lval = stoi(command.substr(0,thirdInd));
            command.erase(0,thirdInd+1);
            
            int rval = stoi(command);
            
            Point VAR;
            VAR.x_ = lval;
            VAR.y_ = rval;
            points.push_back(make_pair(name,VAR));
        }
        else if(command.find("eval") != string::npos){
            size_t firstInd = command.find(" ");
            command.erase(0,firstInd+1);
            
            size_t secondInd = command.find(" ");
            string LVAR = command.substr(0,secondInd);
            command.erase(0,secondInd+1);
            Point lhs;
            
            bool LFIND = false;
            if(isdigit(LVAR[0])||isdigit(LVAR[1])){
                lhs = Point(stoi(LVAR));
                LFIND = true;
            }
            bool isLNeg = false;
            if(LVAR[0] == '-'){
                LVAR.erase(0,1);
                isLNeg = true;
            }
            for(size_t i = 0 ; i < points.size() ; i++){
                if(LVAR == points[i].first){
                    lhs = points[i].second;
                    LFIND = true;
                    if(isLNeg == true) lhs = operator-(lhs);
                }
            }
            if(LFIND == false){
                cout << "input error" << endl;
            }
            
            size_t thirdInd = command.find(" ");
            string oper = command.substr(0,thirdInd);
            command.erase(0,thirdInd+1);
            
            string RVAR = command;
            Point rhs;
            
            bool RFIND = false;
            if(isdigit(RVAR[0])||isdigit(RVAR[1])){
                rhs = Point(stoi(RVAR));
                RFIND = true;
            }
            bool isRNeg = false;
            if(RVAR[0] == '-'){
                isRNeg = true;
                RVAR.erase(0,1);
            }
            
            for(size_t i = 0 ; i < points.size() ; i++){
                if(RVAR == points[i].first){
                    rhs = points[i].second;
                    RFIND = true;
                    if(isRNeg == true) rhs = operator-(rhs);
                }
            }
            
            if(RFIND == false && LFIND == true) cout << "input error" << endl;
            
            if(LFIND == true && RFIND == true){
                if(oper == "+"){
                    Point ANS = operator+(lhs,rhs);
                    cout << "(" << ANS.x_ << ", " << ANS.y_ << ")" <<endl;
                }
                else if(oper == "-"){
                    Point ANS = operator-(lhs,rhs);
                    cout << "(" << ANS.x_ << ", " << ANS.y_ << ")" <<endl;
                }
                else if(oper == "*"){
                    Point ANS = operator*(lhs,rhs);
                    cout << "(" << ANS.x_ << ", " << ANS.y_ << ")" <<endl;
                }
            }
        }
        else if(command == "quit") return 0;
    }
}*/
