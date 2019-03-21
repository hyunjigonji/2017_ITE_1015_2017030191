#include <iostream>

using namespace std;

int n;

void Sort(int *arr){

    int save;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>=arr[j+1]){
                save = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = save;
            }
        }
    }

}

int main(){
    cin >> n;

    if(n<=0) return 0;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    Sort(arr);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
