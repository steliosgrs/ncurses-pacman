#include "Potter.h"
#include <iostream>
// #include <stdlib.h>
// #include <string>

// Potter::Potter(): Movement() {
// }
Potter::Potter(int x, int y, char letter): Movement(x, y, 'M') {
}

// Potter::~Potter() {}

int Potter::move(int x, int y){
    int ai_move = 2;
    switch (ai_move){
        case KEY_UP:
            if (--y <= 0){
                this->y = 1;
            }else{
            this->y-=1;
            }
            break;
        
        case KEY_DOWN:
            if (++y >= yMax-1){
                this->y = yMax -2;
            }else{

            this->y+=1;
            }
            break;
        
        case KEY_RIGHT:
            if (++x >= xMax - 1){
                // std::cout << xMax<<" " <<yMax<<std::endl;
                this->x = xMax -2;
            }else{
                this->x+=1;

            }
            break;
        
        case KEY_LEFT:
            if (--x <= 1){
                this->x = 1;

            }else{
            this->x-=1;
            }
            break;

        case 32: // Space
            refresh();
            break;

        // case 27: // Esc
        //     refresh();
        //     endwin(); 
        //     break;
    }
    // refresh();
            
    return ai_move;
}

