#include <iostream>

using namespace std;

void magic(int **square,int n){
    square[0][n/2]=1;
    int from_x=0;
    int from_y=n/2;

    for(int i=2;i<=n*n;i++){
        
        int to_x=from_x-1;
        int to_y=from_y+1;
        
        if(to_x==-1){
            to_x=n-1;
        }
        if(to_y==n){
            to_y=0;
        }
        if(square[to_x][to_y]){
            to_x=from_x+1;
            to_y=from_y;
        }
        
        square[to_x][to_y]=i;
        
        from_x=to_x;
        from_y=to_y;
    }
}

int main(){
    int N;
    
    cin >> N;
    
    int** square = new int*[N];
    
    for(int i=0;i<N;i++)
        square[i] = new int[N];
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            square[i][j]=0;
        }
    }
    
    magic(square,N);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << square[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0;i<N;i++) delete[] square[i];
    delete[] square;

    return 0;
}

