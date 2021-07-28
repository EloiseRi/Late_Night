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
        int catchEvent(sf::RenderWindow&, sf::Event&, std::map<std::string, sf::Music *> &musics);

    private:
        std::vector<Entity *> _sprites;
        sf::Clock _catClock;
        sf::Uint8 _catAlphaChan = 0;
        bool _catEyes = true;
};

#endif /* !PLAY_HPP_ */
