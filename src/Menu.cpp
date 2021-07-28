#include "Menu.hpp"
#include <iostream>

Menu::Menu()
{
}

Menu::~Menu()
{
}

std::vector<Entity *> Menu::GetSprites()
{
    return _sprites;
}

std::vector<Entity *> Menu::GetButtons()
{
    return _buttons;
}

sf::Text Menu::GetTitle()
{
    return _title;
}

void Menu::SetShader()
{
    _sprites[1]->_sprite.setColor(sf::Color(255, 255, 255, _fadeAlphaChannel));
    _sprites[2]->_sprite.setColor(sf::Color(255, 255, 255, _blinkAlphaChannel));
    _sprites[3]->_sprite.setColor(sf::Color(255, 255, 255, _flickAlphaChannel));
}

void Menu::SetTitle()
{
    if (!_font.loadFromFile("font/8bits.ttf"))
        throw 1;

    _title.setFont(_font);
    _title.setString("Late Night");
    _title.setFillColor(sf::Color::White);
    _title.setCharacterSize(64);

    sf::FloatRect textRect = _title.getLocalBounds();
    _title.setOrigin(textRect.left + textRect.width/2.0f,
                textRect.top  + textRect.height/2.0f);
    _title.setPosition(SCRWIDTH/2.0f,SCRHEIGHT/2.2f);
}

void Menu::LoadSprites()
{
    _sprites.push_back(new Entity("img/menu/cyberpunk-street.png"));
    _sprites.push_back(new Entity("img/menu/shader1.png"));
    _sprites.push_back(new Entity("img/menu/shader2.png"));
    _sprites.push_back(new Entity("img/menu/shader3.png"));

    for (auto &sprite : _sprites)
        sprite->_sprite.setScale(3, 3.5);
}

void Menu::MakeButtons()
{
    _buttons.push_back(new Entity("img/buttons/idle/idle1.png"));
    _buttons.push_back(new Entity("img/buttons/idle/idle2.png"));
    _buttons.push_back(new Entity("img/buttons/idle/idle3.png"));

    for (auto &button : _buttons)
        button->_sprite.setScale(4, 4);

    _buttons[0]->_sprite.setPosition(SCRWIDTH/3.5f,SCRHEIGHT/1.5f);
    _buttons[1]->_sprite.setPosition(SCRWIDTH/2.25f,SCRHEIGHT/1.5f);
    _buttons[2]->_sprite.setPosition(SCRWIDTH/1.65f,SCRHEIGHT/1.5f);
}

void Menu::Initialize()
{
    this->SetTitle();
    this->LoadSprites();
    this->MakeButtons();
}

void Menu::FadingLight()
{
    _sprites[1]->_sprite.setColor(sf::Color(0, 0, 0, _fadeAlphaChannel));

    if (_fadeClock.getElapsedTime().asSeconds() > 0.1f && _fadeAlphaChannel < 255.f && _faded == true) {
        _fadeAlphaChannel += 5;
        _fadeClock.restart();

        if (_fadeAlphaChannel == 255)
            _faded = false;
    } else if (_fadeClock.getElapsedTime().asSeconds() > 0.1f && _fadeAlphaChannel > 0.f && _faded == false) {
        _fadeAlphaChannel -= 5;
        _fadeClock.restart();

        if (_fadeAlphaChannel == 0)
            _faded = true;
    }
}

void Menu::Blinking()
{
    _sprites[2]->_sprite.setColor(sf::Color(0, 0, 0, _blinkAlphaChannel));

    if (_blinkClock.getElapsedTime().asSeconds() > 1.4f && _blinkAlphaChannel < 255.f && _blinking == true) {
        _blinkAlphaChannel = 255;
        _blinkClock.restart();

        if (_blinkAlphaChannel == 255)
            _blinking = false;
    } else if (_blinkClock.getElapsedTime().asSeconds() > 1.4f && _blinkAlphaChannel > 0.f && _blinking == false) {
        _blinkAlphaChannel = 0;
        _blinkClock.restart();

        if (_blinkAlphaChannel == 0)
            _blinking = true;
    }
}

void Menu::Flickering()
{
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    _sprites[3]->_sprite.setColor(sf::Color(0, 0, 0, _flickAlphaChannel));

    if (_blinkClock.getElapsedTime().asSeconds() > r && _flickAlphaChannel < 255.f && _flickering == true) {
        _flickAlphaChannel = 255;
        _flickClock.restart();

        if (_flickAlphaChannel == 255)
            _flickering = false;
    } else if (_flickClock.getElapsedTime().asSeconds() > r && _flickAlphaChannel > 0.f && _flickering == false) {
        _flickAlphaChannel = 0;
        _flickClock.restart();

        if (_flickAlphaChannel == 0)
            _flickering = true;
    }
}

void Menu::HoveringButtons(sf::RenderWindow &window)
{
    int increase = 1;
    std::string idlePath;
    std::string pressedPath;

    for (auto &button : _buttons) {
        idlePath = "img/buttons/idle/idle" + std::to_string(increase) + ".png";
        pressedPath = "img/buttons/pressed/pressed" + std::to_string(increase) + ".png";
        if (button->_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            button->SetTexture(pressedPath);
        else
            button->SetTexture(idlePath);
        increase++;
    }
}

int Menu::catchEvent(sf::RenderWindow &window, sf::Event &event, std::map<std::string, sf::Music *> &musics)
{
    this->HoveringButtons(window);

    if (_buttons[0]->_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
    && event.type == sf::Event::MouseButtonPressed) {
        musics.at("menu")->stop();
        musics.at("game")->play();
        return 0;
    }

    if (_buttons[1]->_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
    && event.type == sf::Event::MouseButtonPressed)
        return 1;

    if (_buttons[2]->_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
    && event.type == sf::Event::MouseButtonPressed)
        window.close();

    return 1;
}