#include "Movement.h"

Movement::Movement(int x, int y, char letter, char direction){
    this->x = x;
    this->y = y;
    this->letter = letter;
    this->direction = direction;

}

Movement::~Movement(){

}

void Movement::move(int x, int y){
    keypad(stdscr, TRUE);
    
    char char_move = getch();

    switch (char_move)
    {
    case KEY_UP:
        this->y--;
        refresh();
        break;
    
    case KEY_DOWN:
        this->y++;
        refresh();
        break;
    
    case KEY_RIGHT:
        this->x++;
        refresh();
        break;
    
    case KEY_LEFT:
        this->x--;
        refresh();
        break;

    case KEY_EXIT:
        // refresh();
        endwin(); 
        break;
    
    }
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

char Movement::get_direction() const{
    return direction;
}

// Setters
int Movement::set_x(int x){
    this->x = x;
}

int Movement::set_y(int y){
    this->y = y;
}

char Movement::set_letter(char letter ){
    this->letter = letter;
}

char Movement::set_direction(char direction){
    this->direction = direction;
}