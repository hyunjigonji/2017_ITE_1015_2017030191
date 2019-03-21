
#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col){
    row_ = row;
    col_ = col;

    canvas_.assign(row_,vector<char>(col_,'.'));
    
    Draw(cout);
}

Canvas::~Canvas(){

}

int Canvas::AddShape(const Shape &s){
    
    if(s.type == RECTANGLE){
        if(s.height % 2 == 0 || s.width % 2 == 0) return ERROR_INVALID_INPUT;
        if(s.y - s.height/2 < 0 || s.y + s.height/2 >= row_) return ERROR_OUT_OF_CANVAS;
        if(s.x - s.width/2 < 0 || s.x + s.width/2 >= col_) return ERROR_OUT_OF_CANVAS;
    }
    if(s.type == TRIANGLE_UP){
        if(s.y + s.height -1 >= col_) return ERROR_OUT_OF_CANVAS;
        if(s.x - s.width + 1 < 0 || s.x + s.width -1 >= row_) return ERROR_INVALID_INPUT;
    }
    if(s.type == TRIANGLE_DOWN){
        if(s.y - s.height +1 < 0) return ERROR_OUT_OF_CANVAS;
        if(s.x - s.width +1 < 0 || s.x + s.width - 1 >= row_) return ERROR_OUT_OF_CANVAS;
    }
    
    shapes_.push_back(s);

    return int(shapes_.size());
}

void Canvas::DeleteShape(int index){
    
    size_t SIZE = shapes_.size();
    
    if(index >= SIZE) return;
    
    for(size_t i = index ; i < SIZE ; i++){
        shapes_[i] = shapes_[i+1];
    }
    
    shapes_.resize(SIZE - 1);
}

void Canvas::Draw(ostream& os){
    
    canvas_.assign(row_,vector<char>(col_,'.'));
    
    size_t SIZE = shapes_.size();
    
    for(size_t i = 0 ; i < SIZE ; i++){
        if(shapes_[i].type == RECTANGLE){
            int dx = shapes_[i].x;
            int dy = shapes_[i].y;
            int dwidth = shapes_[i].width;
            int dheight = shapes_[i].height;
            char dbrush = shapes_[i].brush;
            
            for(int i = dy - dheight/2 ; i <= dy + dheight/2 ; i++){
                for(int j = dx - dwidth/2 ; j <= dx + dwidth/2 ; j++){
                    canvas_[i][j] = dbrush;
                }
            }
        }
        else if(shapes_[i].type == TRIANGLE_UP){
            int dx = shapes_[i].x;
            int dy = shapes_[i].y;
            int dwidth = shapes_[i].width;
            char dbrush = shapes_[i].brush;
            
            for(int i = dy ; i <= dy + dwidth - 1 ; i++){
                for(int j = dx - (i - dy) ; j <= dx + (i - dy) ; j++){
                    canvas_[i][j] = dbrush;
                }
            }
        }
        else if(shapes_[i].type == TRIANGLE_DOWN){
            int dx = shapes_[i].x;
            int dy = shapes_[i].y;
            int dwidth = shapes_[i].width;
            char dbrush = shapes_[i].brush;
            
            for(int i = dy - dwidth + 1 ; i <= dy ; i++){
                for(int j = dx + (dy - i); j >= dx - (dy - i) ; j--){
                    canvas_[i][j] = dbrush;
                }
            }
        }
    }
    
    os << " ";
    
    deque<int> number;
    
    for(int i = 0 ; i < 10 ; i++) number.push_back(i);

    for(int i = 0 ; i < col_ ; i++){
        os << number.front();
        number.push_back(number.front());
        number.pop_front();
    }

    number.clear();
    for(int i = 0 ; i < 10 ; i++) number.push_back(i);
    
    os << endl;
    for(int i = 0 ; i < row_ ; i++){
        os << number.front();
        for(int j = 0 ; j < col_ ; j++){
            os << canvas_[i][j];
        }
        os << endl;
        number.push_back(number.front());
        number.pop_front();
    }
}

void Canvas::Dump(ostream& os){
    
    for(int i = 0 ; i < shapes_.size() ; i++){
        if(shapes_[i].type == RECTANGLE){
            os << i << " rect " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        }
        else if(shapes_[i].type == TRIANGLE_UP){
            os << i << " tri_up " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].brush << endl;
        }
        else if(shapes_[i].type == TRIANGLE_DOWN){
            os << i << " tri_down " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].brush << endl;
        }
    }
}

