
#include "draw_shape2.h"

Canvas::Canvas(size_t row, size_t col){
    row_ = row;
    col_ = col;
    
    canvas_.assign(row_,vector<char>(col_,'.'));
}

Canvas::~Canvas(){
}

void Canvas::Resize(size_t w, size_t h){
    row_ = w;
    col_ = h;
    
    canvas_.assign(row_,vector<char>(col_,'.'));
}

bool Canvas::Draw(int x, int y, char brush){
    
    if(x < col() && x >= 0 && y < row() && y >= 0){
        canvas_[y][x] = brush;
    }
    
    return true;
}
 
void Canvas::Clear(){
    
    canvas_.assign(row_,vector<char>(col_,'.'));
}

size_t Canvas::row(){
    return row_;
}
size_t Canvas::col(){
    return col_;
}

ostream& operator<<(ostream& os, const Canvas& c){
    
    os << " ";
    for(int i = 0 ; i < c.row_ ; i++) os << i%10;
    os << endl;
    for(int i = 0 ; i < c.col_ ; i++){
        os << i%10;
        for(int j = 0 ; j < c.row_ ; j++){
            os << c.canvas_[j][i];
        }
        os << endl;
    }
    
    return os;
}

Shape::~Shape(){
    
}

string Shape::type(){
    return type_;
}

int Shape::x() const{
    return x_;
}

int Shape::y() const{
    return y_;
}

size_t Shape::w() const{
    return w_;
}

size_t Shape::h() const{
    return h_;
}

char Shape::brush() const{
    return brush_;
}

void Shape::gettype(string type){
    type_ = type;
}

void Shape::getx(int x){
    x_ = x;
}
void Shape::gety(int y){
    y_ = y;
}
void Shape::getw(size_t w){
    w_ = w;
}
void Shape::geth(size_t h){
    h_ = h;
}
void Shape::getbrush(size_t brush){
    brush_ = brush;
}

Rectangle::Rectangle(){
}

UpTriangle::UpTriangle(){
}

DownTriangle::DownTriangle(){
}

Diamond::Diamond(){
}

Rectangle::~Rectangle(){
}

UpTriangle::~UpTriangle(){
}

DownTriangle::~DownTriangle(){
}

Diamond::~Diamond(){
}

void Rectangle::Draw(Canvas* canvas) const{
    
    for(int i = y() ; i < y() + h() ; i++){
        for(int j = x() ; j < x() + w() ; j++){
            canvas->Draw(i,j,brush());
        }
    }
}

void UpTriangle::Draw(Canvas* canvas) const{
    
    for(int i = y() ; i <= y() + w() - 1 ; i++){
        for(int j = x() - (int)(i - y()) ; j <= x() + (i - y()) ; j++){
            canvas->Draw(i,j,brush());
        }
    }
}

void DownTriangle::Draw(Canvas* canvas) const{

    for(int i = (int)(y() - w() + 1) ; i <= y() ; i++){
        for(int j = x() + (y() - i) ; j >= x() - (y() - i) ; j--){
            canvas->Draw(i,j,brush());
        }
    }
}

void Diamond::Draw(Canvas* canvas) const{
    
    for(int i = y() ; i <= y() + w() ; i++){
        for(int j = x() - (i - y()) ; j <= x() + (i - y()) ; j++){
            canvas->Draw(i,j,brush());
        }
    }
    int y_temp = y()+ (int)h()*2;
    for(int i = (int)(y_temp - w() + 1) ; i <= y_temp ; i++){
      for(int j = x() + (y_temp - i) ; j >= x() - (y_temp - i) ; j--){
      canvas->Draw(i,j,brush());
      }
    }
}

istream& operator>>(istream& is, Rectangle& r){
    
    int x,y,w,h;
    char brush;
    
    is >> x >> y >> w >> h >> brush;
    
    r.gettype("rect");
    r.getx(x);
    r.gety(y);
    r.getw(w);
    r.geth(h);
    r.getbrush(brush);
    
    return is;
}

istream& operator>>(istream& is, UpTriangle& t){
    
    int x,y,w;
    char brush;
    
    is >> x >> y >> w >> brush;
    
    t.gettype("tri_up");
    t.getx(x);
    t.gety(y);
    t.getw(w);
    t.geth(w);
    t.getbrush(brush);
    
    return is;
}

istream& operator>>(istream& is, DownTriangle& d){
    
    int x,y,w;
    char brush;
    
    is >> x >> y >> w >> brush;
    
    d.gettype("tri_down");
    d.getx(x);
    d.gety(y);
    d.getw(w);
    d.geth(w);
    d.getbrush(brush);
    
    return is;
}

istream& operator>>(istream& is, Diamond& dm){
    
    int x,y,w;
    char brush;
    
    is >> x >> y >> w >> brush;
    
    dm.gettype("diamond");
    dm.getx(x);
    dm.gety(y);
    dm.getw(w);
    dm.geth(w);
    dm.getbrush(brush);
    
    return is;
}
