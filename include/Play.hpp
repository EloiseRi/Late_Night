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

        void Initialize();
        void LoadSprites();
        int catchEvent(sf::RenderWindow&, sf::Event&);

    private:
        std::vector<Entity *> _sprites;
};

#endif /* !PLAY_HPP_ */
