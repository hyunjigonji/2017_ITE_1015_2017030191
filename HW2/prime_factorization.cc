#include <iostream>
#include <stdio.h>

using namespace std;

string primeFactorization(unsigned int _number){
    bool isPrime[66000];
    for(int i=2;i<=66000;i++) isPrime[i] = true;
    for(int i=2;(i*i)<=66000;i++){
        if(isPrime[i]){
            for(int j=(i*i);j<=66000;j+=i){
                isPrime[j] = false;
            }
        }
    }
    string ans;
    int calcul=0;
    while(_number > 1){
        for(int i=2;i<=66000;i++){
            if(isPrime[i]==true){
                int cnt=0;
                while(_number % i==0){
                    _number /= i;
                    cnt++;
                    
                }
                if(cnt!=0)
                {
                    calcul++;
                    if(calcul!=1)
                        ans.append(" x ");
                    ans.append(to_string(i));
                    ans.append("^");
                    string str=to_string(cnt);
                    ans.append(str);
                }
            }
            else continue;
        }
    }
    return ans;
}

int main(int argc,char** argv){
    if(argc<1) return -1;
    
    unsigned int number;
    sscanf(argv[1],"%u",&number);
    
    cout << primeFactorization(number) << endl;
    
    return 0;
}
