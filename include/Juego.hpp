#pragma once 
#include <list>
#include <Bird.hpp>
#include <Tubo.hpp>

using namespace std;

class Juego
{
private:
    int score;
    Bird pajaro;
    list<Tubo> tubos;
public:
    void start(){}
    void chocar(){}
    void aumentarScore(){}
    void gameOver(){}
};


