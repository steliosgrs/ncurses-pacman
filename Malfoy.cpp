#include "Malfoy.h"

Malfoy::Malfoy(int x, int y, char letter): Movement(x, y, letter) {
}

// Malfoy::~Malfoy() {}

void Malfoy::move(int x, int y){
    mvaddch(y, x, '.');
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
    // mvaddch(y, x, letter);
    }
}