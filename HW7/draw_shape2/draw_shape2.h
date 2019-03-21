
#ifndef draw_shape2_h
#define draw_shape2_h

#include <iostream>
#include <vector>

using namespace std;

class Canvas{
public:
    Canvas(size_t row, size_t col);
    ~Canvas();
    
    void Resize(size_t w, size_t h);
    
    bool Draw(int x, int y, char brush);
    
    void Clear();
    
    size_t row();
    size_t col();
    
    vector<vector<char> > canvas_;
private:
    friend ostream& operator<<(ostream& os, const Canvas& c);
    size_t row_, col_;
};

class Shape{
public:
    virtual ~Shape();
    virtual void Draw(Canvas* canvas) const = 0;
    
    string type();
    int x() const;
    int y() const;
    size_t w() const;
    size_t h() const;
    char brush() const;
    
    void gettype(string type);
    void getx(int x);
    void gety(int y);
    void getw(size_t w);
    void geth(size_t h);
    void getbrush(size_t brush);
    
protected:
    string type_;
    int x_, y_;
    size_t w_,h_;
    char brush_;
};

class Rectangle: public Shape{
public:
    Rectangle();
    ~Rectangle();
    void Draw(Canvas* canvas) const;
};

class UpTriangle: public Shape{
public:
    UpTriangle();
    ~UpTriangle();
    void Draw(Canvas* canvas) const;
};

class DownTriangle: public Shape{
public:
    DownTriangle();
    ~DownTriangle();
    void Draw(Canvas* canvas) const;
};

class Diamond: public Shape{
public:
    Diamond();
    ~Diamond();
    void Draw(Canvas* canvas) const;
};

istream& operator>>(istream& is, Rectangle& r);
istream& operator>>(istream& is, UpTriangle& t);
istream& operator>>(istream& is, DownTriangle& d);
istream& operator>>(istream& is, Diamond& dm);

#endif /* draw_shape2_h */

