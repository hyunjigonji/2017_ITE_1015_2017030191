
#ifndef minesweeper_h
#define minesweeper_h

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

class Minesweeper
{
public:
    ////////// 4-3-1 (7 score) //////////
    Minesweeper();
    ~Minesweeper();
    
    // return false when input is incorrect
    bool setMap(size_t _width, size_t _height, vector<string>& _map);
    bool toggleMine(size_t _x, size_t _y);
    
    // return map width, height, and char
    size_t width() const;
    size_t height() const;
    char get(size_t _x, size_t _y) const; // return ' ' if input is illegal
    
    ////////// 4-3-2 (3 score) //////////
    bool setPlay(); // return false when map is not set
    bool touchMap(int _x, int _y); // return true when dead
    
    int touchCount() const;
    
private:
    size_t width_,height_;

    vector<vector<int> > map_;
    vector<vector<int> > checkMap;
    
    void setMap();
    void printMap();
    void printPlayMap();

    // add private member variables and functions if it is needed.
};

#endif /* minesweeper_h */

