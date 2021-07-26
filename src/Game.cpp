#include "Game.hpp"
#include <iostream>

Game::Game() :
_window(sf::VideoMode(800, 600, 32), "Late Night", sf::Style::Default),
_event(), _gamePaused(1)
{
    _window.setFramerateLimit(60);
}

Game::~Game()
{
}

void Game::setScenes()
{
    _menu.Initialize();
}

void Game::CatchEvent()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window.close();

        _gamePaused = _menu.catchEvent(_window, _event);
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

int Game::Loop()
{
    this->setScenes();
    while (_window.isOpen())
    {
        this->CatchEvent();
        _window.clear();

        if (_gamePaused) {
            this->DrawMenu();
        } else {
            // _play.Draw();
            std::cout << "GAME" << std::endl;
        }

        _window.display();
    }
    return EXIT_SUCCESS;
}
