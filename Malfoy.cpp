#include "Malfoy.h"

// Malfoy::Malfoy(): Movement() {
// }
Malfoy::Malfoy(int x, int y, char letter): Movement(x, y, 'M') {
}

// Malfoy::~Malfoy() {}

int Malfoy::move(int x, int y){
    keypad(stdscr, TRUE);
    
    int char_move = getch();

    switch (char_move)
    {
    case KEY_UP:
        // if (check_collisions(this->x, this->y--) == true){
            this->y--;
            refresh();


        // }
        
        break;
    
    case KEY_DOWN:
        // check_collisions(this->x, this->y++);
            this->y++;
            refresh();
        break;
    
    case KEY_RIGHT:
        // check_collisions(this->x, this->y++);
            this->x+=1;
            refresh();
        break;
    
    case KEY_LEFT:
        // check_collisions(this->x, this->y++);
            this->x=x-1;
            refresh();
        break;

    case KEY_EXIT:
        // refresh();
        endwin(); 
        break;
    
    }
    return char_move;
}

