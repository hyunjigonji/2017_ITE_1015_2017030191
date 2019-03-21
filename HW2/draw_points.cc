#include <iostream>

using namespace std;

char arr[51][101];
int x,y;

int main(){
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            arr[i][j]='.';
        }
    }
    int maxx=0,maxy=0;
    while(1){
        cin >> x >> y;
        if(x<0 || y<0) return 0;
        arr[y][x]='*';
        if(x>maxx) maxx=x;
        if(y>maxy) maxy=y;
        for(int i=0;i<=maxy;i++){
            for(int j=0;j<=maxx;j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}
