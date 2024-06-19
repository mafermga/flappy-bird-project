#include "../include/Parallax.hpp"

Parallax::Parallax()
{
    initiated = false;
    score = 0;
    if (!tuboTexture.loadFromFile("assets/sprites/pipe.png"))
    {
        std::cout << "Error al cargar la textura pipe." << '\n';
    }

    if (!baseTexture.loadFromFile("assets/sprites/base.png"))
    {
        std::cout << "Error al cargar la textura base." << '\n';
    }

    srand(time(NULL));

    tubos.push_back(Tubo(tuboTexture, 500, 100 + rand() % 250));
    tubos.push_back(Tubo(tuboTexture, 800, 100 + rand() % 250));

    sf::Sprite niuSprite;
    niuSprite.setTexture(baseTexture);
    niuSprite.setPosition(0, 700 - 112);
    niuSprite.setScale(1.5f, 1.5f);
    bases.push_back(niuSprite);
}

void Parallax::Update()
{
    for (int i = 0; i < (int)bases.size(); i++)
    {
        if (bases[i].getPosition().x < -(336 * 1.5f))
        {
            bases[i].erase(bases.begin() + i);
            continue;
        }

        if (bases[i].getPosition().x <= 0)
        {
            sf::Sprite niuSprite = bases[i];

            niuSprite.setPosition(niuSprite.getPosition().x + 336 * 1.5f, 700 - 112);

            bases.push_back(niuSprite);
        }
    }

    for (int i = 0; i < (int)bases.size(); i++)
    {
        bases[i].move(-2.5f, 0);
    }

    if (!initiated)
        return;

    for (int i = 0; i < (int)tubos.size(); i++)
    {
        tubos.Update();
    }
}