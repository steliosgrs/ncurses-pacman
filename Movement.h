#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include <ncurses.h>
#include <string>

class Movement{

protected:
    int x;
    int y;
    char letter;
    // char direction;

    // XY coordinates;


public:
    Movement(int x, int y, char letter);//, char direction);
    virtual ~Movement();

    // Getters
    int get_x() const;
    int get_y() const;
    char get_letter() const;
    // char get_direction() const;

    // Setters
    void set_x(int);
    void set_y(int);
    void set_letter(char);
    void set_direction(char);

    // Methods
    virtual void move(int x, int y);
    


};


#endif