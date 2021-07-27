#ifndef MENU_HPP_
#define MENU_HPP_

#include "AScene.hpp"

#define SCRWIDTH 800
#define SCRHEIGHT 600
class Menu : public Scene
{
    public:
        Menu();
        ~Menu();

        /* GETTER */
        std::vector<Entity *> GetSprites();
        std::vector<Entity *> GetButtons();
        sf::Text GetTitle();

        /* SETTER */
        void SetTitle();
        void SetShader();

        void HandleMusic();
        void LoadSprites();
        void MakeButtons();
        void Initialize();
        void FadingLight();
        void Blinking();
        void Flickering();
        void HoveringButtons(sf::RenderWindow &window);
        int catchEvent(sf::RenderWindow &window, sf::Event &event);

    private:
        sf::Font _font;
        sf::Text _title;
        sf::Music _music;
        sf::Clock _fadeClock;
        sf::Clock _blinkClock;
        sf::Clock _flickClock;
        sf::Uint8 _blinkAlphaChannel = 0;
        sf::Uint8 _flickAlphaChannel = 0;
        sf::Uint8 _fadeAlphaChannel = 0;
        bool _faded = true;
        bool _blinking = true;
        bool _flickering = true;
        std::vector<Entity *> _sprites;
        std::vector<Entity *> _buttons;
};

#endif /* !MENU_HPP_ */
