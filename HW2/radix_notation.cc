#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

string RadixNotation(unsigned int number,unsigned int radix){
    string str = "0123456789abcdefghijklmnopqrstuvwxyz";
    while(number > 0){
        st.push(str[number%radix]);
        number /= radix;
    }
    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(int argc, char** argv){

    if(argc<2) return -1;
    
    unsigned int radix;
    
    sscanf(argv[1],"%u",&radix);
    if(radix<2 || radix > 36) return -1;
    for(int i=2;i<argc;++i){
        unsigned int number;
        sscanf(argv[i],"%u",&number);
        cout << RadixNotation(number,radix) << endl;
    }
    
    return 0;
}
