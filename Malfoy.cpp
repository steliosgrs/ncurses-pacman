#include "Malfoy.h"
// #include <stdlib.h>
// #include <string>

// Malfoy::Malfoy(): Movement() {
// }
Malfoy::Malfoy(int x, int y, char letter): Movement(x, y, 'M') {
}

// Malfoy::~Malfoy() {}

int Malfoy::move(int x, int y){
    // keypad(stdscr, TRUE);
    
    int char_move = getch();
    // std::string space = " ";
    // int s = atoi(space.c_str());
    // int s = std::stoi(space);

    // char space[1];
    // space = {' '}; 
    // const char *s = space;
    switch (char_move){
        case KEY_UP:
            this->y-=1;
            break;
        
        case KEY_DOWN:
            this->y+=1;
            break;
        
        case KEY_RIGHT:
            this->x+=1;
            break;
        
        case KEY_LEFT:
            this->x=x-1;
            break;

        case 32: // Space
            refresh();
            break;

        case 27: // Esc
            refresh();
            endwin(); 
            break;
    }
    // refresh();
    return char_move;
}

