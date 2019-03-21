#include "binary_search.h"
#include <algorithm>

using namespace std;

BinarySearch::BinarySearch(){
    
}

BinarySearch::BinarySearch(int *_array,int _arrayCount){
    
    mArrayCount = _arrayCount;
    mArray = new int[mArrayCount];

    for(int i=0;i<mArrayCount;i++){
	mArray[i] = _array[i];
    }    

    sortArray();
}

BinarySearch::~BinarySearch(){

}

void BinarySearch::sortArray(){
    sort(mArray, mArray+mArrayCount);
}

int BinarySearch::getIndex(int _element){
    int i=0,j=mArrayCount;
    int m=0;
    int location = 0;
    
    while(i<j){
        m = (i+j)/2;
        if(_element > mArray[m]) i = m+1;
        else j = m;
    }
    if(_element == mArray[i]) location = i;
    else location = -1 ;
    
    return location;
}

