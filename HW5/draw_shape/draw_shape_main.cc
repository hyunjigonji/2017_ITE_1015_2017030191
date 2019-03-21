
#include "draw_shape.h"
#include <ctype.h>

int main(){

    size_t width, height;
    
    cin >> width >> height;
    
    Canvas canvas(height,width);
    
    while(true){
        
        string command;
        cin >> command;
        
        if(command == "add"){
            string shape;
            cin >> shape;
            if(shape == "rect"){
                int x,y;
                cin >> x >> y;
                int rwidth,rheight;
                cin >> rwidth >> rheight;
                char brush;
                cin >> brush;
                
                Shape RECT = {RECTANGLE,x,y,rwidth,rheight,brush};
                int result = canvas.AddShape(RECT);
                
                if(result == ERROR_INVALID_INPUT){
                    cout << "error invalid input" << endl;
                }
                if(result == ERROR_OUT_OF_CANVAS){
                    cout << "error out of canvas" << endl;
                }
            }
            else if(shape == "tri_up"){
                int x,y;
                cin >> x >> y;
                int uwidth;
                cin >> uwidth;
                char brush;
                cin >> brush;
                
                Shape TRI_UP = {TRIANGLE_UP,x,y,uwidth,uwidth,brush};
                int result = canvas.AddShape(TRI_UP);
                
                if(result == ERROR_INVALID_INPUT){
                    cout << "error invalid input" << endl;
                }
                if(result == ERROR_OUT_OF_CANVAS){
                    cout << "error out of canvas" << endl;
                }
            }
            else if(shape == "tri_down"){
                int x,y;
                cin >> x >> y;
                int dwidth;
                cin >> dwidth;
                char brush;
                cin >> brush;
                
                Shape TRI_DOWN = {TRIANGLE_DOWN,x,y,dwidth,dwidth,brush};
                int result = canvas.AddShape(TRI_DOWN);
                
                if(result == ERROR_INVALID_INPUT){
                    cout << "error invalid input" << endl;
                }
                if(result == ERROR_OUT_OF_CANVAS){
                    cout << "error out of canvas" << endl;
                }
            }
        }
        else if(command == "draw"){
            canvas.Draw(cout);
        }
        else if(command == "dump"){
            canvas.Dump(cout);
        }
        else if(command == "delete"){
            int index;
            cin >> index;
            canvas.DeleteShape(index);
        }
        else if(command == "quit") return 0;
    }
}

