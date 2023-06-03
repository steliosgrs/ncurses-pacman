#include "Malfoy.h"
#include <iostream>
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
            
    return char_move;
}

