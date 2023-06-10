#include "Movement.h"

Movement::Movement(int x, int y, char letter){
    this->x = x;
    this->y = y;
    this->letter = letter;
}

Movement::~Movement(){
}

int Movement::move(int x, int y){
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

// char Movement::get_direction() const{
//     return direction;
// }

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
// void Movement::set_direction(char direction){
//     this->direction = direction;
// }