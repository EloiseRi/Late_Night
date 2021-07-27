#include "Play.hpp"

Play::Play()
{
}

Play::~Play()
{
}

std::vector<Entity *> Play::GetSprites()
{
    return _sprites;
}

void Play::LoadSprites()
{
    _sprites.push_back(new Entity("img/play/background.png"));
    // _sprites.push_back(new Entity("img/play/paralax_1v.png"));
    _sprites.push_back(new Entity("img/play/City_scene.png"));

    _sprites[1]->_sprite.setScale(3.5, 3.5);
    _sprites[1]->_sprite.setPosition(0, -270);
}

void Play::Initialize()
{
    this->LoadSprites();
}

int Play::catchEvent(sf::RenderWindow &window, sf::Event &event)
{
    return 1;
}