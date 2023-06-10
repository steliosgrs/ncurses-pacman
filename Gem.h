#ifndef _GEM_H
#define _GEM_H_
#include <ncurses.h>
#include "Movement.h"

class Gem: public Movement{

public:

    // Constucturor
    Gem(int, int, char = 'G');
    ~Gem();
    
    void spawn(int, int);

};

#endif