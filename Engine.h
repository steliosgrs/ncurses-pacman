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
    std::vector<std::string> mapHandler;
    int height_map;
    int width_map;
    std::vector<std::pair<int, int>> availablePositions;

public:
    Engine(const std::string map_filename);
    ~Engine();
    void StartCurses();
    void ReadMapFile(const std::string &);
    void GenerateMap();
    std::pair<int, int> PickRandomPosition();
};

#endif