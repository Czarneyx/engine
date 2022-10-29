#pragma once

#include "application_manager.hpp"

class Entity {

public:
    void SetTexture(const std::string);
    void SetPosition(const sf::Vector2f);
    void Render(sf::RenderWindow*);

private:
    void InitTexture();

    sf::Texture texture;
    sf::Sprite sprite;

};