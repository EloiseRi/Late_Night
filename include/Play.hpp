#ifndef PLAY_HPP_
#define PLAY_HPP_

#include "AScene.hpp"

class Play : public Scene
{
    public:
        Play();
        ~Play();

        void Initialize();
        void LoadSprites();
        int catchEvent(sf::RenderWindow&, sf::Event&);

    private:
        std::vector<Entity> _entities;
};

#endif /* !PLAY_HPP_ */
