#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
#include "Malfoy.h"
#include "Potter.h"
#include "Gem.h"

class Engine{

private:
    WINDOW *window;
    Malfoy *player;
    Potter *bot_potter;
    Gem *gem;
    std::string map_filename;
    std::vector<std::string> mapHandler;
    int height_map;
    int width_map;
    int yMax;
    int xMax;
    int rand_X;
    int rand_Y;

    std::vector<std::pair<int, int>> availablePositions;
    std::vector<std::pair<int, int>> notAvailablePositions;
    std::vector<std::pair<int, int>> entitiesPositions;

public:
    Engine(const std::string map_filename);
    ~Engine();
    void StartCurses();
    void ReadMapFile(const std::string &);
    void GenerateMap();

    void GenerateMalfoy();
    void GeneratePotter();
    void GenerateGem();
    void CreateEntities();

    // std::pair<int, int> PickRandomPosition();
    int rand_int(int);
    void rand_pos();

    void renderPath(int, int, int);
    void make_move(int, int, int);
    void move_AI(int, int, int);
    bool check_collisions(int, int, int);
};

#endif