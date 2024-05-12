#include<ftxui/component/animation.hpp>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include<ftxui/screen/color.hpp>

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
    int velocidadVertical = 1;
    bool ascendiendo = false;

    while (true)
    {

        Dimensions alto = Dimension::Full();
        Dimensions ancho = Dimension::Full();

        if(true){
            if (ascendiendo)
            {
                posY -= velocidadVertical;
                if(posY <= 0 + 1)
                ascendiendo = false;
            }
            else{
                posY += velocidadVertical;
                if(posY >= alto.dimy-textos.size() - 1)
                ascendiendo = true;
            }
            
        }

        Element dibujo = border({
            hbox()
        });

        Screen pantalla = Screen::Create(ancho, alto);
        
        Render(pantalla, dibujo);

        int l = 0;
        for (auto &&texto : textos){
            int i = 0;

            for (auto &&letra : texto)
            {
                //if (posX + i < ancho.dimx){
                    pantalla.PixelAt(posX + i, posY + l).character = letra;
                //}
                i++;
            }
            l++;
            
        }
        posX++;

        if(posX >= ancho.dimx){
            posX = 0;
        }

        pantalla.Print();
        reset = pantalla.ResetPosition();

        cout<<reset;
        fotograma++;
        this_thread::sleep_for(0.1s);

    }
    
    
    return 0;
}

