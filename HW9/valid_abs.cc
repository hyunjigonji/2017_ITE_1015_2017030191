#include <stack>
#include <iostream>

using namespace std;

stack<char> st;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        string input;
        cin >> input;
        
        bool no = false;
        size_t len = input.length();
        
        for(int i = 0 ; i < len ; i++){
            if(input[i] == '<'){
                st.push('<');
            }
            else if(input[i] == '>'){
                if(st.empty()){
                    no = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        
        if(no == true || !st.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
        
        while(!st.empty()){
            st.pop();
        }
    }
}
