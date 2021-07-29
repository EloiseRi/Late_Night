#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "AScene.hpp"
#include "Play.hpp"
#include "Menu.hpp"
#include "Character.hpp"

enum class State { MENU, PLAY, PAUSE };

class Game {
    public:
        Game();
        ~Game();

        void setMusics();
        void setScenes();
        void CatchEvent();
        void DrawMenu();
        void DrawGame();
        int Loop();

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Vector2f _rectPos;
        sf::View _view;
        sf::Vector2f _viewPos;
        std::map<std::string, sf::Music *> _musics;
        State _state;
        Menu _menu;
        Play _play;
        Character _player;
};

#endif /* !GAME_HPP_ */
