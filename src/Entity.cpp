#include "Entity.hpp"

Entity::Entity(const std::string& filepath)
{
    if (!_texture.loadFromFile(filepath))
        throw 1;
    else {
        _sprite.setTexture(_texture);
    }
}

Entity::~Entity()
{
}

void Entity::SetTexture(const std::string& filepath)
{
    if (!_texture.loadFromFile(filepath))
        throw 1;
    else {
        _sprite.setTexture(_texture);
    }
}