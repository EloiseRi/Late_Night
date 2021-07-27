#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "AScene.hpp"
#include "Play.hpp"
#include "Menu.hpp"

#define SPEED 1500.0f

class Game {
    public:
        Game();
        ~Game();

        void setScenes();
        void CatchEvent();
        void DrawMenu();
        void DrawGame();
        int Loop();

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::View _view;
        sf::Vector2f _viewPos;
        sf::Clock _clock;
        unsigned int _gamePaused;
        Menu _menu;
        Play _play;
};

#endif /* !GAME_HPP_ */
