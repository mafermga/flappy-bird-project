#include<../FTXUI/include/ftxui/component/animation.hpp>
#include<../FTXUI/include/ftxui/dom/elements.hpp>
#include<../FTXUI/include/ftxui/screen/screen.hpp>
#include<../FTXUI/include/ftxui/screen/color.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <experimental/random>
#include <list>
#include<fstream>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    list<string> textos;

    fstream imagen;
    imagen.open("./assets/imagen.txt");
    string linea;
    while (getline(imagen, linea))
    {
        textos.push_back(linea);
    }

    imagen.close();

    int fotograma = 0;
    string reset;

    int posX = 0;
    int posY = 6;

    

    while (true)
    {
        Dimensions alto = Dimension::Full();
        Dimensions ancho = Dimension::Full();

        Screen pantalla = Screen::Create(ancho,alto);

        int l = 0;
        for (auto &&texto : textos){
            int i = 0;

            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
            
        }
        posX++;

        pantalla.Print();
        reset = pantalla.ResetPosition();

        cout<<reset;
        fotograma++;
        this_thread::sleep_for(0.1s);

    }
    
    
    return 0;
}

