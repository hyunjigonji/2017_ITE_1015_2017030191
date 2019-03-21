
#ifndef point2d_h
#define point2d_h

#include <vector>

using namespace std;

struct Point{
    int x_,y_;
    
    Point();
    Point(const Point& p);
    explicit Point(int c);
    Point(int x, int y);
};

Point operator-(const Point& p);
Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);

#endif /* point2d_h */

