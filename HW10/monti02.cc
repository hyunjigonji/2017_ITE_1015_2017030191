//monti02.cc
#include <stdio.h>
#include <iostream>
#include <random>

using namespace std;

int main(){
    
    int strategy = 0;
    int number = 0;
    int doornum = 0;
    double sum = 0;
    size_t gift = 0;
    size_t choice = 0;
    size_t exception = 0;
    size_t change = 0;
    
    cin >> strategy >> number >> doornum;
    
    if(strategy == 1){
        for(int i = 0 ; i < number ; i++){
            
            random_device rand;
            mt19937_64 rng(rand());
            
            uniform_int_distribution<__int64_t> num(0,doornum-1);
            
            gift = num(rng);
            choice = num(rng);
            
            if(gift == choice) sum++;
        }
    }
    
    if(strategy == 2){
        for(int i = 0 ; i < number ; i++){
            
            random_device rand;
            mt19937_64 rng(rand());
            
            uniform_int_distribution<__int64_t> num(0,doornum-1);
            
            gift = num(rng);
            choice = num(rng);
            
            exception = choice;
            change = choice;
            
            while(exception == choice || exception == gift){
                exception = num(rng);
            }
            
            while(change == choice || change == exception){
                change = num(rng);
            }
        
            if(change == gift) sum++;
        }
    }
    
    if(strategy == 3){
        for(int i = 0 ; i < number ; i++){
            
            random_device rand;
            mt19937_64 rng(rand());
            
            uniform_int_distribution<__int64_t> num(0,1);
            
            size_t random_strategy = num(rng);
            
            if(random_strategy == 0){
                random_device rand;
                mt19937_64 rng(rand());
                
                uniform_int_distribution<__int64_t> num(0,doornum-1);
                
                gift = num(rng);
                choice = num(rng);
                
                if(gift == choice) sum++;
            }
            else if(random_strategy == 1){
                random_device rand;
                mt19937_64 rng(rand());
                
                uniform_int_distribution<__int64_t> num(0,doornum-1);
                
                gift = num(rng);
                choice = num(rng);
                
                while(exception == choice || exception == gift){
                    exception = num(rng);
                }
                
                while(change == choice || change == exception){
                    change = num(rng);
                }
                
                if(change == gift) sum++;
            }
        }
    }
    
    printf("%.1f", (sum/number)*100);
    cout << "% (" << sum << "/" << number << ")" << endl;
    
    return 0;
}

