
#ifndef omok_h
#define omok_h

#include <iostream>
#include <vector>

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19

using namespace std;

class Omok{
public:
    Omok(): width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(BLACK) {
        map.assign(width_,vector<char>(height_,'.'));
    }
    
    int Put(int x, int y);
    
    void isOmok(int* winner);
    int Turn() const {return turn_;}
    
    vector<vector<char> > map;
    
private:
    int width_, height_;
    int turn_;
  
};

std::ostream& operator<<(std::ostream& os, const Omok& omok);

#endif /* omok_h */

