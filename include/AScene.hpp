#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <SFML/Audio.hpp>
#include "Entity.hpp"

class Scene {
    public:
        ~Scene() = default;

        virtual void Initialize() = 0;
        virtual void LoadSprites() = 0;
        virtual int catchEvent(sf::RenderWindow&, sf::Event&, std::map<std::string, sf::Music *> &musics) = 0;
};

#endif /* !SCENE_HPP_ */
