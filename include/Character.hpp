/*
** EPITECH PROJECT, 2021
** Late_Night
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "Entity.hpp"

#define SPEED_PLAYER 1.6f

enum class Position { IDLE, WALK };
class Character
{
    public:
        Character();
        ~Character();

        Entity GetSprites();
        void Animation();
        sf::Vector2f catchEvent();

    private:
        Position _state = Position::IDLE;
        Entity _idle;
        Entity _walk;
        sf::Clock _animClock;
};

#endif /* !CHARACTER_HPP_ */