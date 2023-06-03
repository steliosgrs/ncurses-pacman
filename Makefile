all : main

test:
	g++ main.cpp Engine.cpp -o main -lncurses

move:
	g++ main.cpp Engine.cpp Movement.cpp -o main -lncurses

malfoy: main.cpp
	g++ main.cpp Engine.cpp Movement.cpp Malfoy.cpp -o main -lncurses

potter: main.cpp
	g++ main.cpp Engine.cpp Movement.cpp Malfoy.cpp Potter.cpp -o main -lncurses

gem: main.cpp
	g++ main.cpp Engine.cpp Movement.cpp Malfoy.cpp Potter.cpp Gem.cpp -o main -lncurses

clean : 
	rm main