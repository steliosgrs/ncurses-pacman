#ifndef _GEM_H
#define _GEM_H_
#include <ncurses.h>
#include "Movement.h"

class Gem: public Movement{

private:
    int life_of_gem = 25;
public:

    // Constucturor
    Gem(int, int, char = 'G');
    ~Gem();

    int get_life_ofGEM() const;
    
    void spawn(int, int);

};

#endif