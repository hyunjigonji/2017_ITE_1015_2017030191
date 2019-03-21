
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int arr[1001];
    int T;
    int k;
    
    for(int i = 1 ; i <= 1000 ; i++){
        arr[i] = (i*(i+1))/2;
    }
    
    cin >> T;
    while(T--){
        cin >> k;
        
        bool dec = false;
        for(int i = 1 ; i <= sqrt(2*k) ; i++){
            for(int j = 1 ; j <= sqrt(2*k) ; j++){
                for(int l = 1 ; l <= sqrt(2*k) ; l++){
                    if(arr[i]+arr[j]+arr[l]==k){
                        dec = true;
                        break;
                    }
                }
            }
        }
        
        if(dec == true) cout << "1" << endl;
        else cout << "0" << endl;
    }
}
