#include "Potter.h"

Potter::Potter(int x, int y, char letter): Movement(x, y, 'M') {
}

Potter::~Potter() {}

int Potter::AImove(int move){
    switch (move){
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
    }
    refresh();
}

