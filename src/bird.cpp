#include "../include/Bird.hpp"

Bird::Bird(int x, int y)
{
    iniciado = false;
    vivo = true;
    estadoAnimacion = 0;
    timerEstado = 10;
    estados.resize(3);
    if (!estados[0].loadFromFile("assets/sprites/birdupflap.png"))
    { // si hay un error al cargar la textura birdupflap entonces...
        std::cout << "Error al cargar la textura: assets/sprites/birdupflap.png" << '\n';
    }
    if (!estados[1].loadFromFile("assets/sprites/birdmidflap.png"))
    { // si hay un error al cargar la textura birdupflap entonces...
        std::cout << "Error al cargar la textura: assets/sprites/birdmidflap.png" << '\n';
    }
    if (!estados[2].loadFromFile("assets/sprites/birddownflap.png"))
    { // si hay un error al cargar la textura birdupflap entonces...
        std::cout << "Error al cargar la textura: assets/sprites/birddownflap.png" << '\n';
    }

    sprite.setTexture(estados[estadoAnimacion]);
    sprite.setOrigin(estados[estadoAnimacion].getSize().x / 2, estados[estadoAnimacion].getSize().y / 2);
    sprite.setPosition(x, y);
    sprite.setScale(2, 2);
    move = 0;
}

void Bird::Update()
{

    if (!vivo)
    {
        if (sprite.getPosition().y < 700 - 136)
        {
            sprite.move(0, 12);
            sprite.setRotation(sprite.getRotation() + 10); // Al momento de morir el sprite hara que gire como descontrolado
        }
        return;
    }

    timerEstado--;
    if (timerEstado == 0)
    {
        estadoAnimacion++;
        estadoAnimacion %= (int)estados.size();
        sprite.setTexture(estados[estadoAnimacion]);
        sprite.setOrigin(estados[estadoAnimacion].getSize().x / 2, estados[estadoAnimacion].getSize().y / 2);
        timerEstado = 10;
    }

    if (!iniciado)
        return;

    sprite.move(0, move);
    move += 0.5f;

    if (move > 8 && move < 15)
        sprite.setRotation(sprite.getRotation() + 4);
}

void Bird::Saltar()
{
    move = -8;
    sprite.setRotation(-15);
}

sf::Vector2f Bird::Getposition()
{
    return sprite.getPosition();
}

bool Bird::GetLive(){
    return vivo;
}

void Bird::Morir(){
    vivo = false;
}

void Bird::Initiated(){
    iniciado = true;
}

void Bird::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
    rt.draw(sprite,rs);
}
