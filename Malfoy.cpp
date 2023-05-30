#include "Malfoy.h"

// Malfoy::Malfoy(): Movement() {
// }
Malfoy::Malfoy(int x, int y, char letter): Movement(x, y, letter) {
}

// Malfoy::~Malfoy() {}

void Malfoy::move(int x, int y){
    keypad(stdscr, TRUE);
    
    int char_move = getch();

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
        this->x+2;
        refresh();
        break;
    
    case KEY_LEFT:
        this->x-2;
        refresh();
        break;

    case KEY_EXIT:
        // refresh();
        endwin(); 
        break;
    
    }

}