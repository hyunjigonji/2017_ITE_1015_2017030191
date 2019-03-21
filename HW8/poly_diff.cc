
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> vec;

string fx;
int c;

int main(){
    while(true){
        vec.clear();
        cin >> fx;
        if(fx == "quit") return 0;
        
        cin >> c;
        
        while(fx.find("+") != string::npos){
            size_t ind = fx.find("+");
            string subfx = fx.substr(0,ind+1);
            vec.push_back(subfx);
            fx.erase(0,ind+1);
        }
        if(fx.find("x") != string::npos) vec.push_back(fx);
        
        size_t SIZE = vec.size();
        int sum = 0;
        
        for(int i = 0 ; i < SIZE ; i++){
            bool minus = false;
            bool power = false;
            int co = 0;
            int pows = 0;
            
            string subfx = vec[i];
            if(subfx[0]=='-'){
                minus = true;
                subfx.erase(0,1);
            }
            size_t xind = subfx.find("x");
            if(xind == 0){
                co = 1;
                subfx.erase(0,1);
            }
            else if(xind != 0){
                co = stoi(subfx.substr(0,xind));
                subfx.erase(0,xind+1);
            }
            
            if(subfx.find("^") != string::npos){
                power = true;
                subfx.erase(0,1);
                size_t len = subfx.length();
                if(subfx[len-1] == '+'){
                    pows = stoi(subfx.substr(0,len-1));
                }
                else{
                    pows = stoi(subfx);
                }
                
            }
            
            if(minus == true){
                if(power == true) sum -= co * pows * pow(c,pows-1);
                else sum -= co;
            }
            else{
                if(power == true) sum += co * pows * pow(c,pows-1);
                else sum += co;
            }
        }
        cout << sum << endl;
    }
}
