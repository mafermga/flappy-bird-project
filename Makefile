bin/ani : src/main.cpp
	g++ src/main.cpp -o bin/ani -I FTXUI/include/ -L FTXUI/build -lftxui-component -lftxui-dom -lftxui-screen -std=c++17


	

run : bin/ani
	./bin/ani