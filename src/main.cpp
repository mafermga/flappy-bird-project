
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(400, 700), "Flappy Bird");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        //
        // inicializacion
        //

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
            window.clear();
            window.display();
        }
    }
    return 0;
}
