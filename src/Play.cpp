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
    _sprites[1]->_sprite.setColor(sf::Color(255, 255, 255, _flickAlphaChan));
    _sprites[2]->_sprite.setColor(sf::Color(255, 255, 255, _blinkAlphaChan));
    _sprites[4]->_sprite.setColor(sf::Color(255, 255, 255, _catAlphaChan));
}

void Play::Blinking()
{
    _sprites[2]->_sprite.setColor(sf::Color(0, 0, 0, _blinkAlphaChan));

    if (_blinkClock.getElapsedTime().asSeconds() > 1.4f && _blinkAlphaChan < 255.f && _blinking == true) {
        _blinkAlphaChan = 255;
        _blinkClock.restart();

        if (_blinkAlphaChan == 255)
            _blinking = false;
    } else if (_blinkClock.getElapsedTime().asSeconds() > 1.4f && _blinkAlphaChan > 0.f && _blinking == false) {
        _blinkAlphaChan = 0;
        _blinkClock.restart();

        if (_blinkAlphaChan == 0)
            _blinking = true;
    }
}

void Play::Flickering()
{
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    _sprites[1]->_sprite.setColor(sf::Color(0, 0, 0, _flickAlphaChan));

    if (_blinkClock.getElapsedTime().asSeconds() > r && _flickAlphaChan < 255.f && _flickering == true) {
        _flickAlphaChan = 255;
        _flickClock.restart();

        if (_flickAlphaChan == 255)
            _flickering = false;
    } else if (_flickClock.getElapsedTime().asSeconds() > r && _flickAlphaChan > 0.f && _flickering == false) {
        _flickAlphaChan = 0;
        _flickClock.restart();

        if (_flickAlphaChan == 0)
            _flickering = true;
    }
}

void Play::openCatEyes()
{
    _sprites[4]->_sprite.setColor(sf::Color(0, 0, 0, _catAlphaChan));

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
    _sprites.push_back(new Entity("img/play/city.png"));
    _sprites.push_back(new Entity("img/play/HotelLight.png"));
    _sprites.push_back(new Entity("img/play/PharmaLight.png"));
    _sprites.push_back(new Entity("img/play/catOE.png"));
    _sprites.push_back(new Entity("img/play/catCE.png"));
    _sprites.push_back(new Entity("img/play/Light.png"));

    for (int i = 0; i <= 3; i++) {
        _sprites[i]->_sprite.setScale(3, 3);
        _sprites[i]->_sprite.setPosition(0, -150);
    }
    _sprites[5]->_sprite.setScale(3, 3);
    _sprites[5]->_sprite.setPosition(0, -150);

    _sprites[3]->_sprite.setScale(2, 2);
    _sprites[4]->_sprite.setScale(2, 2);
    _sprites[3]->_sprite.setPosition(205, -320);
    _sprites[4]->_sprite.setPosition(205, -320);
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