bin/ani : src/main.cpp
	g++ src/main.cpp -o bin/ani -I include FTXUI/include/ -std=c++17 

	

run : bin/ani
	./bin/ani