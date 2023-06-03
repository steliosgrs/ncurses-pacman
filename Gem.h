#ifndef _GEM_H
#define _GEM_H_
#include <ncurses.h>
class Gem{

private:
    int x;
    int y;
    char letter;
public:

    // Constucturor
    Gem(int, int, char = 'G');
    ~Gem();
    void spawn();

};

#endif