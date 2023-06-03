#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
#include "Malfoy.h"
#include "Potter.h"

class Engine{

private:
    WINDOW *window;
    Malfoy *player;
    Potter *bot_potter;
    std::string map_filename;
    std::vector<std::string> mapHandler;
    int height_map;
    int width_map;
    int yMax;
    int xMax;
    std::vector<std::pair<int, int>> availablePositions;
    std::vector<std::pair<int, int>> notAvailablePositions;

public:
    Engine(const std::string map_filename);
    ~Engine();
    void StartCurses();
    void ReadMapFile(const std::string &);
    void GenerateMap();
    void GenerateMalfoy();
    // void GenerateMalfoy(int, int);
    void GeneratePotter();
    void GenerateGem();
    // std::pair<int, int> PickRandomPosition();

    void display_Malfoy(int, int, int);
    int rand_int(int);
    bool check_collisions(int, int, int);
};

#endif