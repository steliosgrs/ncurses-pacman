#include "Engine.h"
#include <iostream>

Engine::Engine(const std::string map_filename){

    // StartCurses();
    ReadMapFile(map_filename);
    window = newwin(height_map,width_map,0,0);
    // GenerateMap();
    std::pair<int, int> random_point = PickRandomPosition();
    // CreateMalfoy();
    // CreatePotter();
    
    // Refresh the window
    wrefresh(window);

}

// Destructor
Engine::~Engine(){
    clear();
    werase(window);
    delwin(window);
}

void Engine::StartCurses(){
    // Initialize the screen, setup memory
    initscr(); 

    // 
    cbreak();

    // Arrows
    keypad(stdscr, true);
    noecho();
    start_color();

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

    // char tile;
    for(int row = 0; row < mapHandler.size(); row++)
        for(int col = 0; col < mapHandler[row].size()+1; col++){
            // tile = mapHandler[row][col];
            // mvAddItem(row,col,tile)
            if (mapHandler[row][col] == '*' ){
                mvwaddstr(window,row, col, "*");
            }else if (mapHandler[row][col] == ','){
                continue;
            } else
                mvwaddstr(window,row, col, ".");
                // this->availablePositions.first = row;
                // this->availablePositions.second = col;
                availablePositions.push_back(std::make_pair(row, col));
        }
        refresh();
        

}

// void Engine::PickRandomPosition(){

//     // XY coordinate;
//     int rows = mapHandler.size();
//     // cols = mapHandler[0].size();
//     for(int row = 0; row < mapHandler.size(); row++){
//         for(int col = 0; col < mapHandler[row].size()+1; col++){
//             if (mapHandler[row][col] == '.' ){
//                 XY point = {row,col};
//                 availablePositions.push_back(point);
//                 std::cout << "X: "<< point.x << " Y: "<< point.y << std::endl;
//                 // <>
//             }
//         }
//     }
//     // for (int i = 0; i < availablePositions.size(); i++){
//     //     // cout << availablePositions[i] << endl;
//     //     mvwprintw(window, rows,mapHandler[0],"%d %d" ,availablePositions[i].x, availablePositions[i].y);
//     // }

// }

std::pair<int, int> Engine::PickRandomPosition(){

    int index;
    index = std::rand() * availablePositions.size();
    return availablePositions[index];
}