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
    tubos.push_back(Tubo(tuboTexture, 850, 100 + rand() % 250));

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
            bases.erase(bases.begin() + i);
            continue;
        }

        if (bases[i].getPosition().x <= 0)
        {
            sf::Sprite niuSprite = bases[(int)bases.size()-1];

            niuSprite.setPosition(niuSprite.getPosition().x + 336 * 1.5f, 700 - 112);

            bases.push_back(niuSprite);
        }
    }

    for (int i = 0; i < (int)bases.size(); i++)
    {
        bases[i].move(-2.5f, 0);
    }

    if (!initiated) return;

    int ult = (int)tubos.size()-1;

    for (int i = 0; i < (int)tubos.size(); i++)
    {
        if(tubos[i].GetPosition().x < 0 && tubos[i].GetPosition().x >= -3){
            tubos.push_back(Tubo(tuboTexture, tubos[ult].GetPosition().x+350,100+rand()%250));
        }

        if(tubos[i].GetPosition().x < 100 && i > last){
            last = i;
            score++;
        }

        if(tubos[i].GetPosition().x <= -100) tubos.erase(tubos.begin()+i);
    }

    for (int i = 0; i < (int)tubos.size(); i++)
    {
        tubos[i].Update();
    }



}


bool Parallax::Collision(sf:: IntRect rect){
    for(int i = 0; i < (int)tubos.size(); i++){
        if(tubos[i].Collision(rect)) return true;
    }
    return false;
}

int Parallax::ConsultScore(){
    return score;
}

void Parallax::Initiated(){
    initiated = true;
}

void Parallax::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
    for(int i = 0; i < (int)tubos.size(); i++) rt.draw(tubos[i], rs);
        for(int i = 0; i < (int)bases.size(); i++) rt.draw(bases[i],rs);

}