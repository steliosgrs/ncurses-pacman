#include <iostream>
#include <ncurses.h>
#include "Engine.h"
// #include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	Engine engine(argv[1]);
	
    // getch();
    endwin(); 
	return 0;
}
