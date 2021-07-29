#include "Play.hpp"
#include <iostream>

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

void Play::SetShader()
{
    _sprites[5]->_sprite.setColor(sf::Color(255, 255, 255, _catAlphaChan));
}

void Play::openCatEyes()
{
    _sprites[5]->_sprite.setColor(sf::Color(0, 0, 0, _catAlphaChan));

    if (_catClock.getElapsedTime().asSeconds() > 8.f && _catAlphaChan < 255.f && _catEyes == true) {
        _catAlphaChan = 255;
        _catClock.restart();

        if (_catAlphaChan == 255)
            _catEyes = false;
    } else if (_catClock.getElapsedTime().asSeconds() > 0.4f && _catAlphaChan > 0.f && _catEyes == false) {
        _catAlphaChan = 0;
        _catClock.restart();

        if (_catAlphaChan == 0)
            _catEyes = true;
    }
}

void Play::LoadSprites()
{
    _sprites.push_back(new Entity("img/play/background_long.png"));
    _sprites.push_back(new Entity("img/play/paralax1.png"));
    _sprites.push_back(new Entity("img/play/paralax2.png"));
    _sprites.push_back(new Entity("img/play/City_scene.png"));
    _sprites.push_back(new Entity("img/play/catOE.png"));
    _sprites.push_back(new Entity("img/play/catCE.png"));

    _sprites[3]->_sprite.setScale(3, 3);
    _sprites[3]->_sprite.setPosition(0, -150);
    _sprites[4]->_sprite.setScale(2, 2);
    _sprites[5]->_sprite.setScale(2, 2);
    _sprites[4]->_sprite.setPosition(205, -320);
    _sprites[5]->_sprite.setPosition(205, -320);
}

void Play::Initialize()
{
    this->LoadSprites();
}

int Play::catchEvent(sf::RenderWindow &window, sf::Event &event, std::map<std::string, sf::Music *> &musics)
{
    (void)window;
    (void)event;
    (void)musics;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
    sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        std::cout << "PAUSE" << std::endl;
    return 1;
}