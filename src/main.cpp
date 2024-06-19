
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../include/Bird.hpp"
#include "../include/Parallax.hpp"


int main(int argc, char const *argv[])
{
    bool initiated;
    bool presionado;

    sf::RenderWindow window(sf::VideoMode(400, 700), "Flappy Bird");
    window.setFramerateLimit(60);

    presionado = false;

    while (window.isOpen())
    {

        //
        // inicializacion
        //
        Bird *bird = new Bird(210, 350);
        Parallax * parallax = new Parallax;
        initiated = false;

        while (true)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
            }

            bird->Update();

            if(bird->GetLive()){
                parallax->Update();
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!presionado){
                    bird->Saltar();
                    presionado = true;
                    if(!initiated){
                        initiated = true;
                        bird->Initiated();
                        parallax->Initiated();
                    }
                }
                
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!presionado){
                presionado = true; //REINICIO DEL JUEGO
                break;
            }
            sf::IntRect rect(bird->Getposition().x-23,bird->Getposition().y-21,44,40);
            if(parallax->Collision(rect)){
                bird->Morir();
            }

            if(bird->Getposition().y < 0 || bird->Getposition().y > 700-136){
                bird->Morir();
            }


            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                presionado = false;
            }

            window.clear();
            window.draw(*parallax);
            window.draw(*bird);
            window.display();
        }
        delete bird;
        delete parallax;
    }
    return 0;
}
