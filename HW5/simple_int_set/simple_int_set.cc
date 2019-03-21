
#include "simple_int_set.h"
#include <algorithm>

SimpleIntSet::SimpleIntSet(){
    
}

SimpleIntSet::~SimpleIntSet(){
    
    set0.clear();
    set1.clear();
    result.clear();
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count){
    
    mElementCount = _count;
    
}

int* SimpleIntSet::elements() const{
    
    return mElements;
}

int SimpleIntSet::elementCount() const{
    
    return mElementCount;
}

void SimpleIntSet::printSet(set<int>& result){
    
    cout << "{ ";
    for(set<int>::iterator it = result.begin() ; it != result.end() ; it++){
        cout << *it << " ";
    }
    cout << "}" << endl;
}

set<int> SimpleIntSet::SetIntersection(set<int>& set0, set<int>& set1){

    set_intersection(set0.begin(),set0.end(),set1.begin(),set1.end(),inserter(result,result.begin()));
    
    return result;
}

set<int> SimpleIntSet::SetUnion(set<int>& set0, set<int>& set1){
    
    set_union(set0.begin(),set0.end(),set1.begin(),set1.end(),inserter(result,result.begin()));
    
    return result;
    
}
set<int> SimpleIntSet::SetDifference(set<int>& set0, set<int>& set1){
    
    set_difference(set0.begin(),set0.end(),set1.begin(),set1.end(),inserter(result,result.begin()));
    
    return result;
    
}

