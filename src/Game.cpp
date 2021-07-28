#include "Game.hpp"
#include <iostream>

Game::Game() :
_window(sf::VideoMode(800, 600, 32), "Late Night", sf::Style::Default),
_event(), _view(sf::FloatRect(0, 0, 800, 600)), _state(State::MENU)
{
    _window.setFramerateLimit(120);
    _view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    _window.setView(_view);
}

Game::~Game()
{
   delete _musics.at("menu");
   delete _musics.at("game");
}

void Game::setMusics()
{
    _musics.insert(std::make_pair<std::string, sf::Music *>(std::string("menu"), new sf::Music()));
    _musics.insert(std::make_pair<std::string, sf::Music *>(std::string("game"), new sf::Music()));

    if (!_musics.at("menu")->openFromFile("music/cyberpunk.ogg"))
        throw 1;
    if (!_musics.at("game")->openFromFile("music/jazzy.ogg"))
        throw 1;

    _musics.at("menu")->play();
}

void Game::setScenes()
{
    _menu.Initialize();
    _play.Initialize();
}

void Game::CatchEvent()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window.close();

        if (_menu.catchEvent(_window, _event, _musics) == 0)
            _state = State::PLAY;
    }
}

void Game::DrawMenu()
{
    _menu.FadingLight();
    _menu.Blinking();
    _menu.Flickering();
    _menu.SetShader();

    for (auto &sprite : _menu.GetSprites())
        _window.draw(sprite->_sprite);

    for (auto &button : _menu.GetButtons())
        _window.draw(button->_sprite);
    _window.draw(_menu.GetTitle());
}

void Game::DrawGame()
{
    for (auto &sprite : _play.GetSprites())
        _window.draw(sprite->_sprite);
}

int Game::Loop()
{
    sf::RectangleShape _rect(sf::Vector2f(20, 20));
    _rect.setFillColor(sf::Color::Red);

    this->setMusics();
    this->setScenes();
    while (_window.isOpen())
    {
        _clock.restart();
        this->CatchEvent();
        _window.clear();

        if (_state == State::MENU) {
            this->DrawMenu();
        } else {
            this->DrawGame();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                _rect.move(SPEED * _clock.getElapsedTime().asSeconds(), 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                _rect.move(-SPEED * _clock.getElapsedTime().asSeconds(), 0);

            _viewPos.x = _rect.getPosition().x + 10 - (800 / 2);
            _viewPos.y = _rect.getPosition().y + 10 - (600 / 2);

            if (_viewPos.x < 0)
                _viewPos.x = 0;
            if (_viewPos.x > 2000)
                _viewPos.x = 2000;
            if (_viewPos.y < 0)
                _viewPos.y = 0;
        }

        _view.reset(sf::FloatRect(_viewPos.x, _viewPos.y, 800, 600));

        _window.setView(_view);
        _window.draw(_rect);

        _window.display();
    }
    return EXIT_SUCCESS;
}
