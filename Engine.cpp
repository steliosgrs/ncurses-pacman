#include <iostream>
#include "Engine.h"
// #include "Malfoy.h"
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
    entitiesPositions.push_back(std::make_pair(-1,-1));

    CreateEntities();

    // Check Move
    int move = 32;
    // int prev_y =  prev_x = 0; 
    int x, y;
    bool not_valid = true;
    int counter_gem = 0;


    while ( move != 27){
        
        x = player->get_x();
        y = player->get_y();
        
        make_move(move, y, x);
        move = player->move(x, y);
        while (mapHandler[player->get_y()][player->get_x()] == '*'){
            make_move(move, y, x);
            move = player->move(x, y);

        }

        if (move == 27){
            break;
        }
        if (counter_gem == 15){
            rand_pos();
            gem->spawn(rand_X, rand_Y);
            counter_gem = 0;
        }
        if (move != 32){
            counter_gem+=1;
        }

        wrefresh(window);
    } 
    // Refresh the window
    // wrefresh(window);
    delete player;
    delete bot_potter;
    delete gem;
}

// Destructor
Engine::~Engine(){
    delwin(window);
    clear();
    // werase(window);
    // endwin(); 
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
                notAvailablePositions.push_back(std::make_pair(row,col));
            } else
                mvwaddch(window,row, col,'.');
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

void Engine::rand_pos(){
    do{
        // Create a random X,Y
        this->rand_X = rand_int(this->xMax);
        this->rand_Y = rand_int(this->yMax);
        
        for (int i = 0; i < entitiesPositions.size(); i++){
            if ((entitiesPositions[i].first == rand_Y) and (entitiesPositions[i].second == rand_X) ){
                this->rand_X = rand_int(this->xMax);
                this->rand_Y = rand_int(this->yMax);
            }else{
                entitiesPositions.push_back(std::make_pair(rand_Y,rand_X));
                break;
            }
        }
        // Check if it is wall
        }while (mapHandler[rand_Y][rand_X] == '*');
}

void Engine::GenerateMalfoy(){
    rand_pos();
    player = new Malfoy(rand_X, rand_Y);
    player->set_xMax(xMax);
    player->set_yMax(yMax);
    // mvaddch(player->get_y(), player->get_x(), this->player->get_letter());
}

void Engine::GeneratePotter(){
    rand_pos();
    bot_potter = new Potter(rand_X, rand_Y);
    bot_potter->set_xMax(xMax);
    bot_potter->set_yMax(yMax);
    mvaddch(bot_potter->get_y(), bot_potter->get_x(), this->bot_potter->get_letter());
}

void Engine::GenerateGem(){
    rand_pos();
    gem = new Gem(rand_X, rand_Y);
    gem->set_xMax(xMax);
    gem->set_yMax(yMax);
    mvaddch(gem->get_y(), gem->get_x(), this->gem->get_letter());
}

void Engine::CreateEntities(){
    GenerateMalfoy();
    GeneratePotter();
    GenerateGem();
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


// Rerender the map with .
void Engine::renderPath(int move, int y, int x){
    switch (move){
        case KEY_UP:
            mvaddch(y+1,x, '.');
            break;
        case KEY_DOWN:
            mvaddch(y-1,x, '.');
            break;
        
        case KEY_RIGHT:
            mvaddch(y,x-1, '.');
            break;
        
        case KEY_LEFT:
            mvaddch(y,x+1, '.');
            break;
        }
}

void Engine::make_move(int move, int y, int x){
    bool valid_move;
    renderPath(move, y, x);

    // Move Player
    mvaddch(y, x, this->player->get_letter());
    // Move AI Bot
    // move_AI(move, y+1, x+1);
}

void Engine::move_AI(int move, int y, int x){
    bool valid_move;
    renderPath(move, y, x);
    mvaddch(y, x, this->bot_potter->get_letter());
    // mvaddch(this->bot_potter->get_y(), this->bot_potter->get_x(), this->bot_potter->get_letter());
}

