#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
#include "Malfoy.h"

class Engine{

private:
    WINDOW *window;
    Malfoy *player;
    std::string map_filename;
    std::vector<std::string> mapHandler;
    int height_map;
    int width_map;
    int yMax;
    int xMax;
    std::vector<std::pair<int, int>> availablePositions;

public:
    // using Malfoy::Malfoy;
    Engine(const std::string map_filename);
    ~Engine();
    void StartCurses();
    void ReadMapFile(const std::string &);
    void GenerateMap();
    std::pair<int, int> PickRandomPosition();

    // void diplay_Malfoy(WINDOW*, int, int, char);
    int rand_int(int);
    // void display_Malfoy(Malfoy*);
};

#endif