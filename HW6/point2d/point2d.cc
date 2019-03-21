
#include "point2d.h"

Point::Point(){
    x_ = 0;
    y_ = 0;
}

Point::Point(const Point& p){
    x_ = p.x_;
    y_ = p.y_;
}

Point::Point(int c){
    x_ = c;
    y_ = c;
}

Point::Point(int x, int y){
    x_ = x;
    y_ = y;
}

Point operator-(const Point& p){

    return Point(p.x_*(-1),p.y_*(-1));
}

Point operator+(const Point& lhs, const Point& rhs){
    
    return Point(lhs.x_+rhs.x_,lhs.y_+rhs.y_);
}

Point operator-(const Point& lhs, const Point& rhs){
    
    return Point(lhs.x_-rhs.x_,lhs.y_-rhs.y_);
}

Point operator*(const Point& lhs, const Point& rhs){
    
    return Point(lhs.x_*rhs.x_,lhs.y_*rhs.y_);
}
