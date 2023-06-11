#include "Gem.h"

Gem::Gem(int x, int y, char letter): Movement(x, y, 'G') {
}

Gem::~Gem(){
}

int Gem::get_life_ofGEM() const{
    return this->life_of_gem;
}

void Gem::spawn(int x, int y){
    // Remove Previous
    mvaddch(this->y, this->x, '.');

    // Create new Gem
    this->x = x;
    this->y = y;
    mvaddch(this->y, this->x, this->get_letter());
}