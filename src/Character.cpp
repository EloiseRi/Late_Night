/*
** EPITECH PROJECT, 2021
** Late_Night
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>

Character::Character() :
_idle("img/character/idle.png"), _walk("img/character/walk.png")
{
    _idle._rect = sf::IntRect(0, 0, 64, 64);
    _idle._sprite.setTextureRect(_idle._rect);
    _idle._sprite.setScale(3, 3);
    _idle._sprite.setPosition(300, 410);

    _walk._rect = sf::IntRect(0, 0, 64, 64);
    _walk._sprite.setTextureRect(_walk._rect);
    _walk._sprite.setScale(3, 3);
    _walk._sprite.setPosition(300, 410);
}

Character::~Character()
{
}

Entity Character::GetSprites()
{
    if (_state == Position::IDLE)
        return _idle;
    else
        return _walk;
}

void Character::Animation()
{
    if (_state == Position::IDLE) {
        if (_animClock.getElapsedTime().asSeconds() > 0.24f) {
            if (_idle._rect.left >= 192)
                _idle._rect.left = 0;
            else
                _idle._rect.left += 64;
            _idle._sprite.setTextureRect(_idle._rect);
            _animClock.restart();
        }
    } else if (_state == Position::WALK) {
        if (_animClock.getElapsedTime().asSeconds() > 0.1f) {
            if (_walk._rect.left >= 448)
                _walk._rect.left = 0;
            else
                _walk._rect.left += 64;
            _walk._sprite.setTextureRect(_walk._rect);
            _animClock.restart();
        }
    }
}

sf::Vector2f Character::catchEvent()
{
    // _moveClock.restart();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && _walk._sprite.getPosition().x > 32) {
        _walk._rect.top = 64;
        _state = Position::WALK;
        _walk._sprite.move(-SPEED_PLAYER, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _walk._sprite.getPosition().x < 2230) {
        _walk._rect.top = 0;
        _state = Position::WALK;
        _walk._sprite.move(SPEED_PLAYER, 0);
    } else
        _state = Position::IDLE;

    _idle._sprite.setPosition(_walk._sprite.getPosition());

    return _walk._sprite.getPosition();
}
