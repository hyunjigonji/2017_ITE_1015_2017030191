
#ifndef sorted_array_h
#define sorted_array_h

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SortedArray{

public:
    SortedArray();
    ~SortedArray();
    
    void AddNumber(int num);
    
    vector<int> GetSortedAscending();
    vector<int> GetSortedDescending();
    
    int GetElement(int index);
    size_t GetSize();
    
    int GetMax();
    int GetMin();
    
private:
    
    vector<int> numbers_;
    
};


#endif /* sorted_array_h */

