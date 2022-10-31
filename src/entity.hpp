#pragma once

#include "application_manager.hpp"

class Entity {

public:
    void SetTexture(std::string const);
    void SetPosition(sf::Vector2f const);
    void Render(sf::RenderWindow*);
    void SetScale(sf::Vector2f const);
    sf::Texture GetTexture();

private:
    void InitTexture();

    sf::Texture texture;
    sf::Sprite sprite;

};