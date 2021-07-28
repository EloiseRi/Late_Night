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
    _sprites.push_back(new Entity("img/play/background_long.png"));
    _sprites.push_back(new Entity("img/play/paralax1.png"));
    _sprites.push_back(new Entity("img/play/paralax2.png"));
    _sprites.push_back(new Entity("img/play/City_scene.png"));

    _sprites[3]->_sprite.setScale(3.5, 3.5);
    _sprites[3]->_sprite.setPosition(0, -270);
}

void Play::Initialize()
{
    this->LoadSprites();
}

int Play::catchEvent(sf::RenderWindow &window, sf::Event &event, std::map<std::string, sf::Music *> &musics)
{
    return 1;
}