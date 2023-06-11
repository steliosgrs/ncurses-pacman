#include "Movement.h"

Movement::Movement(int x, int y, char letter){
    this->x = x;
    this->y = y;
    this->letter = letter;
}

Movement::~Movement(){
}

int Movement::move(int x, int y){
    int char_move = getch();

    switch (char_move){
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

        case 32: // Space
            refresh();
            break;
    }
    refresh();
            
    return char_move;
}

// Getters
int Movement::get_x() const{
    return x;
}

int Movement::get_y() const{
    return y;
}

char Movement::get_letter() const{
    return letter;
}

int Movement::get_yMax() const{
    return yMax;
}

int Movement::get_xMax() const{
    return xMax;
}

// Setters
void Movement::set_x(int x){
    this->x = x;
}

void Movement::set_y(int y){
    this->y = y;
}

void Movement::set_letter(char letter ){
    this->letter = letter;
}

void Movement::set_yMax(int yMax){
    this->yMax = yMax;
}

void Movement::set_xMax(int xMax){
    this->xMax = xMax;
}
