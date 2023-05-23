#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>

class Engine{

private:
    WINDOW *window;
    std::string map_filename;
    // std::ifstream mapfile;
    std::vector<std::string> mapHandler;
    std:vector<std:int[]> availablePositions;
    int height_map;
    int width_map;

public:
    Engine(const std::string map_filename);
    // Engine(const std::string &);
    ~Engine();
    void StartCurses();
    void ReadMapFile(const std::string &);
    void GenerateMap();
};

#endif