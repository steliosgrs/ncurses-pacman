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
    // std::pair<int, int> random_point = PickRandomPosition();

    // Malfoy* player = new Malfoy(random_point.second, random_point.first, 'M');
    // std::pair<int, int>  start_Malfoy = availablePositions.front();
    // std::pair<int, int>  start_Potter = availablePositions.back();

    // mvwaddch(window,  player->get_y(), player->get_x()/2, player->get_letter());
    // std::cout << player->get_x()/2 << " " << player->get_y() << std::endl;
    // diplay_Malfoy(this->window,  player->get_y(), player->get_x()/2, player->get_letter());

    srand(time(0));
    int rand_X = rand_int(xMax);
    int rand_Y = rand_int(yMax);

    while (mapHandler[rand_Y][rand_X] == '*' or  mapHandler[rand_Y][rand_X] == '.'){
    // while (mapHandler[rand_Y][rand_X] != ' '){
        rand_X = rand_int(xMax);
        rand_Y = rand_int(yMax);
        // std::cout << rand_Y << " " << rand_X << std::endl;

    }
    // std::cout << "X" << rand_X << " Y" << rand_Y << std::endl;
    //                              Y               ,       X
    player = new Malfoy(rand_X, rand_Y);
    // mvwaddch(window,player->get_y(),player->get_x(), player->get_letter());
    mvaddch(player->get_y(),player->get_x(), player->get_letter());
    // display_Malfoy(player);

    // Check Move
    // while (player->move(player->get_x(), player->get_y()) != KEY_EXIT){
    //     // player->get_y() = rand_Y;
    //     // player->get_x() = rand_X;
    //     // mvwaddch(window,player->get_y(),player->get_x(), player->get_letter());
    //     int move = player->move(player->get_x(), player->get_y());

    //     // erase_

    //     display_Malfoy(move);
        
    //     wrefresh(window);
    // }
    int move;
    do {
        int x = player->get_x();
        int y = player->get_y();
        move = player->move(x, y);
        display_Malfoy(move, y, x);
        wrefresh(window);
    } while ( move != KEY_EXIT);
    // Refresh the window
    wrefresh(window);
    delete player;
}

// Destructor
Engine::~Engine(){
    clear();
    werase(window);
    endwin(); 
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
                mvwaddch(window,row, col,'.');
                availablePositions.push_back(std::make_pair(row,col));
            // if (col == 0){
            //     xMax++;
            // }
        }
        // std::cout << xMax << std::endl;
        // std::cout << row << std::endl;
        yMax++;

    }

    xMax = mapHandler[0].size()-1;
    // std::cout << xMax << std::endl;
    refresh();

}
int Engine::rand_int(int max) {
    return ((int)rand() / ((int)RAND_MAX + 1.0)) * (max - 1);
}

bool Engine::check_collisions(int x, int y){
    bool valid_move = false;
    if (mapHandler[y][x] == '*' ){
        valid_move = true;
        return valid_move;
    }else {
        return valid_move;
    }

}

std::pair<int, int> Engine::PickRandomPosition(){

    int index;
    // std::cout << rand() << std::endl;
    int rand_num = rand() % availablePositions.size();
    // std::cout << "Rand "<<rand_num << std::endl;
    for (int i = 0; i < availablePositions.size(); i++){
        if (i == rand_num){
            return availablePositions[i];
        }
    }
}

void Engine::display_Malfoy(int move, int y, int x){
    keypad(stdscr, TRUE);
    mvwaddch(this->window,this->player->get_y(),this->player->get_x(), this->player->get_letter());
    // std::cout << this->player->get_y() <<y << y+1<< std::endl;
    switch (move){
    case KEY_UP:
        mvaddch(y-1,x, '.');
    std::cout << this->player->get_y() <<y << y+1<< std::endl;
        refresh();
        break;
    case KEY_DOWN:
        mvaddch(y-1,x, '.');
        refresh();
        break;
    
    case KEY_RIGHT:
        mvaddch(y,x-1, '.');
        wrefresh(window);
        break;
    
    case KEY_LEFT:
        mvaddch(y,x+1, '.');
        refresh();
        break;
    }
}


// void CreateMalfoy(){

// }