#ifndef _POTTER_H_
#define _POTTER_H_

#include <ncurses.h>
#include "Movement.h"

class Potter: public Movement{

public:
    using Movement::Movement;
    Potter(int x, int y, char letter);
    // ~Malfoy();

    // // Getters
    // // Setters
    // // Methods
    // void move(int x, int y);
    
};


#endif