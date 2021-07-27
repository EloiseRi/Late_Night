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

void Play::SetMusic()
{
    if (_loopMusic == false)
        _loopMusic = true;

    if (_loopMusic)
        _music.setVolume(35);
}

void Play::HandleMusic()
{
    if (!_music.openFromFile("music/jazzy.ogg"))
        throw 1;
    _music.setLoop(true);
    _music.setVolume(0);
    _music.play();
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
    this->HandleMusic();
    this->LoadSprites();
}

int Play::catchEvent(sf::RenderWindow &window, sf::Event &event)
{
    return 1;
}