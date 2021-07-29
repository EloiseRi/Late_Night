#ifndef PLAY_HPP_
#define PLAY_HPP_

#include "AScene.hpp"

#define SCREENWIDTH 800
#define SCREENHEIGHT 600
class Play : public Scene
{
    public:
        Play();
        ~Play();

        /* Getter */
        std::vector<Entity *> GetSprites();

        /* Setter */
        void SetShader();

        void Initialize();
        void LoadSprites();
        void openCatEyes();
        void Parallax();
        void Flickering();
        void Blinking();
        int catchEvent(sf::RenderWindow&, sf::Event&, std::map<std::string, sf::Music *> &musics);

    private:
        std::vector<Entity *> _sprites;
        sf::Clock _catClock;
        sf::Clock _blinkClock;
        sf::Clock _flickClock;
        sf::Clock _scrollClock;
        sf::Uint8 _catAlphaChan = 0;
        sf::Uint8 _flickAlphaChan = 0;
        sf::Uint8 _blinkAlphaChan = 0;
        bool _flickering = true;
        bool _blinking = true;
        bool _catEyes = true;
};

#endif /* !PLAY_HPP_ */
