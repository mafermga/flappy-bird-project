#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Bird : public sf::Drawable
{
private:
    int estadoAnimacion;
    int timerEstado;
    bool iniciado;
    bool vivo;
    std::vector<sf::Texture> estados;
    sf::Sprite sprite;
    float move;

public:
    Bird(int, int);

    void Update();

    void Saltar();

    void Morir();

    bool GetLive();

    sf::Vector2f Getposition();
    void Initiated();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};
