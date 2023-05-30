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
    std::pair<int, int> random_point = PickRandomPosition();
    Malfoy* player = new Malfoy(random_point.second, random_point.first, 'M');
    std::pair<int, int>  start_Malfoy = availablePositions.front();
    std::pair<int, int>  start_Potter = availablePositions.back();

    mvwaddch(window,  player->get_y(), player->get_x()/2, player->get_letter());
    // std::cout << player->get_x()/2 << " " << player->get_y() << std::endl;
    // diplay_Malfoy(this->window,  player->get_y(), player->get_x()/2, player->get_letter());
    // mvwaddch(window, 19, 78, 'M');
    // CreateMalfoy();
    // CreatePotter();
    srand(time(0));
    int rand_X = rand_int(xMax);
    int rand_Y = rand_int(yMax);
    std::cout << "X" << rand_X << " Y" << rand_Y << std::endl;
    // while (player->)
    // {
    //     /* code */
    // }
    
    
    // Refresh the window
    wrefresh(window);
    // getch();

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
                // mvwaddstr(window,row, col, "*");
                mvwaddch(window,row, col, '*');
            }else if (mapHandler[row][col] == ','){
                continue;
            } else
                // mvwaddstr(window,row, col, ".");
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
    std::cout << xMax << std::endl;
    refresh();

}
int Engine::rand_int(int max) {
    return ((int)rand() / ((int)RAND_MAX + 1.0)) * (max - 1);
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

// void display(WINDOW* win, int y, int x, char letter){
//     mvwaddch(win, y, x, letter);
// }


// int Engine::rand_int(int max) {
// /* return a random number between 0 and max */

//     int divisor = RAND_MAX/(max+1);
//     int retval;

//     do { 
//         retval = rand() / divisor;
//     } while (retval > max);

//     return retval;
// }

// void CreateMalfoy(){
    
// }

// void CreateMalfoy(){

// }