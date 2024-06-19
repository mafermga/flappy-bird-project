#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>

class Tubo : public sf::Drawable
{
    private:
        sf::Sprite upSprite;
        sf::Sprite downSprite;

    public:
        Tubo(sf::Texture&, int, int);
        void Update();
        bool Collision(sf::IntRect);
        sf::Vector2f GetPosition();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};


