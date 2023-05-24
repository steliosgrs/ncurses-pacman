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
    // char direction;

    // XY coordinates;


public:
    explicit Movement(int x, int y, char letter);//, char direction);
    // MOVEMENT(const std::string &);
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
    // char set_direction(char);

    // Methods
    void move(int x, int y);


};


#endif