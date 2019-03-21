
//simple_int_set.h
#ifndef __hw03__simple_int_set__
#define __hw03__simple_int_set__

#define MAX_SIZE 1024
#include <set>
#include <iostream>

using namespace std;

class SimpleIntSet
{
private:
    int *mElements;
    int mElementCount;

    set<int> set0;
    set<int> set1;
    set<int> result;
    
public:
    SimpleIntSet(int *_elements, int _count);
    ~SimpleIntSet();
    
    SimpleIntSet();
    
    int *elements() const; // return sorted array
    int elementCount() const;
    
    set<int> SetIntersection(set<int>& set0, set<int>& set1);
    set<int> SetUnion(set<int>& set0, set<int>& set1);
    set<int> SetDifference(set<int>& set0, set<int>& set1);
    
    void printSet(set<int>& result);
};

#endif

