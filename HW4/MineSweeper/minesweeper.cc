

#include "minesweeper.h"

Minesweeper::Minesweeper(){

}

Minesweeper::~Minesweeper(){
    
}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string> &_map){
    
    width_ = _width;
    height_ = _height;
    
    if(_map.size() != height_) return false;
    map_.resize(_height);
    
    for(size_t i = 0 ; i < height_ ; i++){
        
        if(_map[i].length() != width_) return false;
        map_[i] = vector<int> (width_,0);
        
        for(size_t j = 0 ; j < width_ ; j++){
            
            if(_map[i][j] == '*') map_[i][j] = -1;
            if(_map[i][j] != '*' && _map[i][j] != '.') return false;
        }
    }
    
    this -> setMap();
    
    return true;
}

bool Minesweeper::toggleMine(size_t _x, size_t _y){
    
    if(get(_x,_y) == ' ') return false;
    else if(get(_x,_y) == '*') map_[_y][_x] = 0;
    else map_[_y][_x] = -1;
    
    this -> setMap();
    
    return true;
}

size_t Minesweeper::width() const{
    return width_;
}

size_t Minesweeper::height() const{
    return height_;
}

char Minesweeper::get(size_t _x, size_t _y) const{
    
    if(_x >= width_ || _y >= height_){
        return ' ';
    }
    return (map_[_y][_x]==-1)? '*':'.';
}

bool Minesweeper::setPlay(){
    
    if(!map_.size()) return false;
    
    checkMap.resize(height_);
    
    for(int i = 0 ; i < height_ ; i++){
        
        checkMap[i] = vector<int> (width_,0);

    }
    
    printPlayMap();
    
    return true;
}

bool Minesweeper::touchMap(int _x, int _y){
    
    if(_x < 0 || _x >= width_ || _y < 0 || _y >= height_) return false;
    
    if(get(_x,_y) == '*') return true;
    
    checkMap[_y][_x] = 1;
    
    this -> printPlayMap();
    
    return false;
}

int Minesweeper::touchCount() const{
    
    int count = 0;
    
    for(int i = 0 ; i < height_ ; i++){
        for(int j = 0 ; j < width_ ; j++){
            count += checkMap[i][j];
        }
    }
    
    return count;
}

void Minesweeper::setMap(){
    
    int dx[8] = {-1,-1,-1,0,+1,+1,+1,0};
    int dy[8] = {-1,0,+1,+1,+1,0,-1,-1};
    
    for(size_t i = 0 ; i < height_ ; i++){
        for(size_t j = 0 ; j < width_ ; j++){
            
            if(map_[i][j] == -1) continue;
            map_[i][j] = 0;
            
            for (int k = 0; k < 8; k++) {
                if (i + dx[k] < height_ && j + dy[k] < width_ && map_[i+dx[k]][j+dy[k]] == -1)
                    map_[i][j]++;
            }
        }
    }
    
    this -> printMap();
    
}

void Minesweeper::printMap(){
    
    for(size_t i = 0 ; i < height_ ; i++){
        for(size_t j = 0 ; j < width_ ; j++){
            if(map_[i][j] == -1) cout << "*";
            else cout << map_[i][j];
        }
        cout << endl;
    }
}

void Minesweeper::printPlayMap(){
    
    for(size_t i = 0 ; i < height_ ; i++){
        for(size_t j = 0 ; j < width_ ; j++){
            if(checkMap[i][j]) cout << map_[i][j];
            else cout << "_";
        }
        cout << endl;
    }
}

