#include "../include/Tubo.hpp"

Tubo::Tubo(sf::Texture &texture, int x, int y){
    upSprite.setTexture(texture);   //se asignan las texturas
    downSprite.setTexture(texture);

    //Cambiar origen, posicion
    upSprite.setOrigin(texture.getSize(),0);
    upSprite.setRotation(180);

    upSprite.setPosition(x,y);
    downSprite.setPosition(x,y+150);

    upSprite.setScale(1.5f, 1.5f);
    downSprite.setScale(1.5f, 1.5f);
}

