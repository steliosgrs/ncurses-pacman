#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include <ncurses.h>
// #include <vector>
#include <string>
// #include <fstream>

class Movement{

protected:
    int x;
    int y;
    char letter;
    char direction;


public:
    Movement(int x, int y, char letter, char direction);
    // MOVEMENT(const std::string &);
    ~Movement();

    // Getters
    int get_x() const;
    int get_y() const;
    char get_letter() const;
    char get_direction() const;

    // Setters
    int set_x(int);
    int set_y(int);
    char set_letter(char);
    char set_direction(char);

    // Methods
    void move(int x, int y);

};


#endif