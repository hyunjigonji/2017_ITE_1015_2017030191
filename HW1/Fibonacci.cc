#include<iostream>

using namespace std;

int cnt = 1;

int Fibo(int n)
{
    int save;
    
    if(n<1) save=0;
    
    else if(n==1) save=1;
    
    else save=Fibo(n-1)+Fibo(n-2);
    
    if(n==cnt){
        cnt++;
        cout << save << ' ';
    }
    
    return save;
}

int main() {
    int N;
    
    cin >> N;
    
    if(N==0 || N<0) return 0;

    Fibo(N);
    
    cout << endl;

    return 0;
}
