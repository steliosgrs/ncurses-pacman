all : main

test:
	g++ main.cpp -o main -lncurses

main : main.cpp
	g++ main.cpp babis.cpp -o main -lncurses
	
map : main.cpp
	g++ main.cpp Game.cpp -o main -lncurses

babis: main.cpp
	g++ main.cpp Game.cpp Babis.cpp -o main -lncurses

entity: main.cpp
	g++ main.cpp Game.cpp Babis.cpp Entity.cpp -o main -lncurses

clean : 
	rm main