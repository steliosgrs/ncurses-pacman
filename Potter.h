#ifndef _POTTER_H_
#define _POTTER_H_

#include <ncurses.h>
#include "Movement.h"

class Potter: public Movement{

public:
    Potter(int x, int y, char letter = 'M');
    // ~Malfoy();

    int move(int, int);
    
};


#endif