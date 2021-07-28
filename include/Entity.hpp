#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>

class Entity {
    public:
        Entity(const std::string&);
        ~Entity();

        void SetTexture(const std::string&);

        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::IntRect _rect;
};

#endif /* !ENTITY_HPP_ */
