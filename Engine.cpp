#include <iostream>
#include "Engine.h"
#include "Malfoy.h"
#include <time.h>
#include <new>
#include <random>
#include <time.h>

Engine::Engine(const std::string map_filename){

    StartCurses();
    ReadMapFile(map_filename);
    window = newwin(height_map,width_map,0,0);
    GenerateMap();

    srand(time(0));
    int rand_X; 
    int rand_Y; 

    do{
        rand_X = rand_int(xMax);
        rand_Y = rand_int(yMax);

    }while (mapHandler[rand_Y][rand_X] == '*' or  mapHandler[rand_Y][rand_X] == ' ');
    player = new Malfoy(rand_X, rand_Y);

    // Check Move
    int move;
    do {
        int x = player->get_x();
        int y = player->get_y();
        display_Malfoy(move, y, x);
        move = player->move(x, y);
        // do {

        // } while ();
        wrefresh(window);
    } while ( move != 27);
    // Refresh the window
    wrefresh(window);
    delete player;
}

// Destructor
Engine::~Engine(){
    clear();
    werase(window);
    // endwin(); 
    delwin(window);
    endwin(); 
}

void Engine::StartCurses(){
    // Initialize the screen, setup memory
    initscr(); 
    // 
    noecho();
    cbreak();
    intrflush(stdscr, FALSE);

    set_escdelay(0);

    // Arrows
    keypad(stdscr, TRUE);
    // Memory refresh
    refresh(); 
}

void Engine::ReadMapFile(const std::string &file_name){
    
    std::ifstream mapfile;
    mapfile.open(file_name);
    if (mapfile.is_open()){

        std::string line;
        std::getline(mapfile,line);
        mapHandler.push_back(line);
        width_map = line.length()-1;
        for(line;std::getline(mapfile,line); ){
            mapHandler.push_back(line);
        }
        height_map = mapHandler.size();
        mapfile.close();
    }
    
}

void Engine::GenerateMap(){
    yMax = xMax = 0 ;
    for(int row = 0; row < mapHandler.size(); row++){
        for(int col = 0; col < mapHandler[row].size()+1; col++){
            if (mapHandler[row][col] == '*' ){
                mvwaddch(window,row, col, '*');
            }else if (mapHandler[row][col] == ','){
                // mvwaddch(window,row, col,' ');
                continue;
            } else
                mvwaddch(window,row, col,' ');
                availablePositions.push_back(std::make_pair(row,col));
        }
        yMax++;

    }

    xMax = mapHandler[0].size()-1;
    wrefresh(window);

}
int Engine::rand_int(int max) {
    return ((int)rand() / ((int)RAND_MAX + 1.0)) * (max - 1);
}

bool Engine::check_collisions(int move, int x, int y){
    bool valid_move = false;
    if (mapHandler[y][x] == '*' ){
        valid_move = true;
        return valid_move;
    }else {
        return valid_move;
    }

}

void Engine::display_Malfoy(int move, int y, int x){
    bool valid_move;
    switch (move){
        case KEY_UP:
            // valid_move = check_collisions(move, x, y);
            if (check_collisions(move, x, y-1)){
                mvaddch(y+1,x, ' ');
                mvaddch(y, x, this->player->get_letter());
            }
                break;
        case KEY_DOWN:
            // valid_move = check_collisions(move, x, y);
            if (check_collisions(move, x, y+1)){
                mvaddch(y-1,x, ' ');
                mvaddch(y, x, this->player->get_letter());
            }
            break;
        
        case KEY_RIGHT:
            // valid_move = check_collisions(move, x, y);
            if (check_collisions(move, x+1, y)){
                mvaddch(y,x-1, ' ');
                mvaddch(y, x, this->player->get_letter());
            }
            break;
        
        case KEY_LEFT:
            // valid_move = check_collisions(move, x, y);
            if (check_collisions(move, x-1, y)){
                mvaddch(y,x+1, ' ');
                mvaddch(y, x, this->player->get_letter());
            }
            break;
        }
    
    // mvaddch(y, x, this->player->get_letter());
    // }
    // wrefresh(window);
}

