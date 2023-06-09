#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include <ncurses.h>
#include <string>

class Movement{

protected:
    int x;
    int y;
    char letter;
    int xMax;
    int yMax;

public:
    Movement(int x, int y, char letter);
    virtual ~Movement();

    // Getters
    int get_x() const;
    int get_y() const;
    char get_letter() const;
    int get_xMax() const;
    int get_yMax() const;

    // Setters
    void set_x(int);
    void set_y(int);
    void set_letter(char);
    void set_direction(char);
    void set_xMax(int);
    void set_yMax(int);
    // Methods
    int move(int x, int y);
    
};


#endif