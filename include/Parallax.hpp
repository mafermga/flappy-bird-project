#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tubo.hpp"

class Parallax : public sf::Drawable
{
private:
    int score;
    bool initiated;
    sf::Texture tuboTexture;
    sf::Texture baseTexture;
    std::vector<sf::Sprite> bases;
    std::vector<Tubo> tubos;

public:
    Parallax();
    void Update();
    bool Collision(sf::IntRect);
    void Initiated();
    int Score();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};