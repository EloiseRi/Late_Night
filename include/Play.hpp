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
        void SetMusic();

        void Initialize();
        void LoadSprites();
        void HandleMusic();
        int catchEvent(sf::RenderWindow&, sf::Event&);

    private:
        std::vector<Entity *> _sprites;
        bool _loopMusic = false;
        sf::Music _music;
};

#endif /* !PLAY_HPP_ */
