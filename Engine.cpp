#include <iostream>
#include "Engine.h"
#include "Malfoy.h"
// #include <new>
Engine::Engine(const std::string map_filename){

    // StartCurses();
    ReadMapFile(map_filename);
    window = newwin(height_map,width_map,0,0);
    GenerateMap();
    std::pair<int, int> random_point = PickRandomPosition();
    // Malfoy malfoy = Malfoy(random_point.first, random_point.second, 'M');//, "i");
    // CreateMalfoy(random_point);
    // CreatePotter();
    
    // Refresh the window
    wrefresh(window);

}

// Destructor
Engine::~Engine(){
    clear();
    werase(window);
    endwin(); 
    delwin(window);
}

void Engine::StartCurses(){
    // Initialize the screen, setup memory
    initscr(); 

    // 
    cbreak();
    noecho();

    intrflush(stdscr, FALSE);
    // Arrows
    keypad(stdscr, TRUE);
    // start_color();

    // Memory refresh
    refresh(); 
    // halfdelay(5);
    // renderer = new Renderer(&levelMap);
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

    for(int row = 0; row < mapHandler.size(); row++)
        for(int col = 0; col < mapHandler[row].size()+1; col++){
            if (mapHandler[row][col] == '*' ){
                mvwaddstr(window,row, col, "*");
            }else if (mapHandler[row][col] == ','){
                continue;
            } else
                mvwaddstr(window,row, col, ".");
                availablePositions.push_back(std::make_pair(row, col));
        }
        refresh();
        

}

std::pair<int, int> Engine::PickRandomPosition(){

    int index;
    index = std::rand() * availablePositions.size();
    return availablePositions[index];
}

// void CreateMalfoy(){
    
// }

// void CreateMalfoy(){

// }