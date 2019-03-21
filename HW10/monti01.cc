#include <stdio.h>
#include <iostream>
#include <random>

using namespace std;

int main(){
    
    int strategy = 0;
    int number = 0;
    double sum = 0;
    size_t gift = 0;
    size_t choice = 0;
    size_t change = 0;
    
    cin >> strategy >> number;
    
    if(strategy == 1){
        for(int i = 0 ; i < number ; i++){
        
            random_device rand;
            mt19937_64 rng(rand());
        
            uniform_int_distribution<__int64_t> num(0,2);

            gift = num(rng);
            choice = num(rng);
            
            if(gift == choice) sum++;
        }
    }
    
    if(strategy == 2){
        for(int i = 0 ; i < number ; i++){
            
            random_device rand;
            mt19937_64 rng(rand());
            
            uniform_int_distribution<__int64_t> num(0,2);
            
            gift = num(rng);
            choice = num(rng);
            
            for(int i = 0 ; i < 3 ; i++){
                if(choice != gift){
                    change = gift;
                }
                else if(choice == gift && choice != i){
                    change = i;
                }
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
                
                uniform_int_distribution<__int64_t> num(0,2);
                
                gift = num(rng);
                choice = num(rng);
                
                if(gift == choice) sum++;
            }
            else if(random_strategy == 1){
                
                random_device rand;
                mt19937_64 rng(rand());
                
                uniform_int_distribution<__int64_t> num(0,2);
                
                gift = num(rng);
                choice = num(rng);
                
                for(int i = 0 ; i < 3 ; i++){
                    if(choice != gift){
                        change = gift;
                    }
                    else if(choice == gift && choice != i){
                        change = i;
                    }
                }
                
                if(change == gift) sum++;
            }
        }
    }
    
    printf("%.1f", (sum/number)*100);
    cout << "% (" << sum << "/" << number << ")" << endl;
    
    return 0;
}

