#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<string> vec;

int BlackJack(vector<string> &vec){
    
    size_t number = vec.size();
    int anum = 0;
    int sum = 0;
    
    while(number--){
        
        if(vec.back() == "A"){
            anum++;
            vec.pop_back();
        }
        else if(vec.back() == "J" || vec.back() == "Q" || vec.back() == "K"){
            sum += 10;
            vec.pop_back();
        }
        else{
            if(!isdigit(vec.back()[0])){
                return -1;
            }
            sum += atoi(vec.back().c_str());
            vec.pop_back();
        }
        
    }
    
    int Anum = anum;
    
    while(Anum--){
        
        if(sum + 11 > 21) sum += 1;
        else sum += 11;
    }
    
    if(sum < 21) return sum;
    else if(sum > 21) return 0;
    else return 21;
    
}

int main(){
    
    while(true){
        string card;
        getline(cin,card);
        
        if(!isdigit(card[0])) return 0;
        size_t ind = card.find(" ");
        int num = stoi(card.substr(0,ind));
        
        if(num<=1) return 0;
    
        card.erase(0,ind+1);
        
        int cnt=0;
    
        while(card.find(" ")!=string::npos){
    
            size_t index = card.find(" ");
            string word = card.substr(0,index);
            
            vec.push_back(word);
        
            card.erase(0,index+1);
            
            cnt++;
        
        }
        
        size_t index = card.find(" ");
        string word = card.substr(0,index);
        
        vec.push_back(word);
        
        card.erase(0,index+1);
        
        cnt++;
        
        if(cnt != num) return 0;
    
        if(vec.size() != num) return 0;
    
        int result = BlackJack(vec);
        
        if(result == 21) cout << "BlackJack" << endl;
        else if(result == 0) cout << "Exceed" << endl;
        else if(result == -1) return 0;
        else cout << result << endl;
    }
    
}
