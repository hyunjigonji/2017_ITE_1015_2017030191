
#include "omok.h"

int Omok::Put(int x, int y){
    if(x < 0 || x > width_ || y < 0 || y > height_) return NOBODY;
    
    if(map[x][y] == '.' && Turn() == BLACK){
        map[x][y] = 'o';
        return BLACK;
    }
    else if(map[x][y] == '.' && Turn() == WHITE){
        map[x][y] = 'x';
        return WHITE;
    }
    else return NOBODY;
}

void Omok::isOmok(int* winner){
    if(Turn() == BLACK){
        for(int j = 0 ; j < GROUND_SIZE ; j++){
            for(int i = 0 ; i < GROUND_SIZE ; i++){
                if(map[i][j] == 'o'){
                    if(map[i][j+1] == 'o' && map[i][j+2] == 'o' && map[i][j+3] == 'o' && map[i][j+4] == 'o' && map[i][j-1] != 'o' && map[i][j+5] != 'o'){
                        *winner = BLACK;
                        break;
                    }
                    if(map[i+1][j+1] == 'o' && map[i+2][j+2] == 'o' && map[i+3][j+3] == 'o' && map[i+4][j+4] == 'o' && map[i-1][j-1] != 'o' && map[i+5][j+5] != 'o'){
                        *winner = BLACK;
                        break;
                    }
                    if(map[i+1][j] == 'o' && map[i+2][j] == 'o' && map[i+3][j] == 'o' && map[i+4][j] == 'o' && map[i-1][j] != 'o' && map[i+5][j] != 'o'){
                        *winner = BLACK;
                        break;
                    }
                    if(map[i+1][j-1] == 'o' && map[i+2][j-2] == 'o' && map[i+3][j-3] == 'o' && map[i+4][j-4] == 'o' && map[i-1][j+1] != 'o' && map[i+5][j-5] != 'o'){
                        *winner = BLACK;
                        break;
                    }
                }
            }
        }
        turn_ = WHITE;
    }
    else if(Turn() == WHITE){
        for(int j = 0 ; j < GROUND_SIZE ; j++){
            for(int i = 0 ; i < GROUND_SIZE ; i++){
                if(map[i][j] == 'x'){
                    if(map[i][j+1] == 'x' && map[i][j+2] == 'x' && map[i][j+3] == 'x' && map[i][j+4] == 'x' && map[i][j-1] != 'x' && map[i][j+5] != 'x'){
                        *winner = WHITE;
                        break;
                    }
                    if(map[i+1][j+1] == 'x' && map[i+2][j+2] == 'x' && map[i+3][j+3] == 'x' && map[i+4][j+4] == 'x' && map[i-1][j-1] != 'x' && map[i+5][j+5] != 'x'){
                        *winner = WHITE;
                        break;
                    }
                    if(map[i+1][j] == 'x' && map[i+2][j] == 'x' && map[i+3][j] == 'x' && map[i+4][j] == 'x' && map[i-1][j] != 'x' && map[i+5][j] != 'x'){
                        *winner = WHITE;
                        break;
                    }
                    if(map[i+1][j-1] == 'x' && map[i+2][j-2] == 'x' && map[i+3][j-3] == 'x' && map[i+4][j-4] == 'x' && map[i-1][j+1] != 'x' && map[i+5][j-5] != 'x'){
                        *winner = WHITE;
                        break;
                    }
                }
            }
        }
        turn_ = BLACK;
    }
}

std::ostream& operator<<(std::ostream& os, const Omok& omok){
    for(int i = 0 ; i < GROUND_SIZE ; i++){
        for(int j = 0 ; j < GROUND_SIZE ; j++){
            os << omok.map[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
