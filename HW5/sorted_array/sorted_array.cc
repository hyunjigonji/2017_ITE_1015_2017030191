
#include "sorted_array.h"

SortedArray::SortedArray(){
    
}

SortedArray::~SortedArray(){
    
}

void SortedArray::AddNumber(int num){
    
    numbers_.push_back(num);
}

int SortedArray::GetElement(int index) {
    return numbers_[index];
}

size_t SortedArray::GetSize(){
    return numbers_.size();
}

vector<int> SortedArray::GetSortedAscending(){
    
    sort(numbers_.begin(),numbers_.end());
    
    return numbers_;
}

vector<int> SortedArray::GetSortedDescending(){
    
    sort(numbers_.begin(),numbers_.end());
    reverse(numbers_.begin(),numbers_.end());
    
    return numbers_;
}

int SortedArray::GetMax(){
    
    sort(numbers_.begin(),numbers_.end());
    
    return numbers_.back();
}

int SortedArray::GetMin(){
    
    sort(numbers_.begin(),numbers_.end());
    
    return numbers_.front();
}

