//  simple_int_set.cpp

#include "simple_int_set.h"
#include <algorithm>
#include <iostream>

using namespace std;

SimpleIntSet::SimpleIntSet(){
    
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count){
    
    mElementCount = _count;
    
    mElements = new int[mElementCount];
    
    for(int i=0;i<_count;i++){
        mElements[i] = _elements[i];
    }
    
    sortElements();
}

SimpleIntSet::~SimpleIntSet(){
}

void SimpleIntSet::sortElements(){
    
    sort(mElements,mElements+mElementCount);
    
    for(int i=mElementCount-1;i>0;i--){
        if(mElements[i]==mElements[i-1]){
            for(int j=i;j<mElementCount-1;j++){
                mElements[j]=mElements[j+1];
            }
            mElementCount--;
        }
    }
}

int* SimpleIntSet::elements() const{
    return mElements;
}

int SimpleIntSet::elementCount() const{
    return mElementCount;
}

SimpleIntSet *SimpleIntSet::unionSet(SimpleIntSet& _operand){
    
    int cnt1 = _operand.mElementCount;
    int cnt2 = mElementCount;
    
    sortElements();
    
    for(int i=0;i<cnt1;i++){
        int dec = 0;
        int save = 0;
        for(int j=0;j<cnt2;j++){
            if(_operand.mElements[i] == mElements[j]){
                dec = 1;
                break;
            }
            else save = _operand.mElements[i];
        }
        if(dec==0) {
            mElements[mElementCount++] = save;
        }
    }
    
    sortElements();
    
    return this;
}


SimpleIntSet *SimpleIntSet::differenceSet(SimpleIntSet& _operand){
    
    int cnt1 = _operand.mElementCount;
    int cnt2 = mElementCount;
    
    sortElements();
    
    for(int i=0;i<cnt1;i++){
        int dec = 0;
        int save = 0;
        for(int j=0;j<cnt2;j++){
            if(_operand.mElements[i] == mElements[j]){
                dec = 1;
                save = mElements[j];
                mElementCount--;
                break;
            }
        }
        if(dec == 1){
            for(int k=0;k<cnt2;k++){
                if(mElements[k]==save){
                    for(int l=k;l<mElementCount;l++){
                        mElements[l]=mElements[l+1];
                    }
                }
            }
        }
    }
    
    sortElements();
    
    return this;
}

SimpleIntSet *SimpleIntSet::intersectSet(SimpleIntSet& _operand){
    
    int cnt1 = _operand.mElementCount;
    int cnt2 = mElementCount;
    
    sortElements();
    
    for(int i=0;i<cnt2;i++){
        int dec = 0;
        int save = 0;
        for(int j=0;j<cnt1;j++){
            if(_operand.mElements[j]==mElements[i]){
                dec = 1;
                break;
            }
            else{
                save = i;
            }
        }
        if(dec == 0){
            for(int k=i;k<cnt2-1;k++){
                mElements[k]=mElements[k+1];
            }
            i--;
            cnt2--;
            mElementCount--;
        }
    }
    
    return this;
}

void SimpleIntSet::printSet(){
    
    cout << "{ ";
    for(int i=0;i<mElementCount;i++){
        cout << mElements[i] << " ";
    }
    cout << "}" << endl;
    
}
