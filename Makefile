all : main

test:
	g++ main.cpp Engine.cpp -o main -lncurses

move:
	g++ main.cpp Engine.cpp Movement.cpp -o main -lncurses
	
map : main.cpp
	g++ main.cpp Game.cpp -o main -lncurses

babis: main.cpp
	g++ main.cpp Game.cpp Babis.cpp -o main -lncurses

entity: main.cpp
	g++ main.cpp Game.cpp Babis.cpp Entity.cpp -o main -lncurses

clean : 
	rm main