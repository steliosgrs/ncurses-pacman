#ifndef _MALFOY_H_
#define _MALFOY_H_

#include <ncurses.h>
#include "Movement.h"

class Malfoy: public Movement{

public:
    using Movement::Movement;
    Malfoy(int x, int y, char letter = 'M');
    // ~Malfoy();

    // // Getters
    // // Setters
    // // Methods
    int move(int x, int y);
    

};


#endif