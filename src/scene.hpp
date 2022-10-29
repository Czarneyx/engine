#pragma once

#include "entity.hpp"

class Scene {

public:
    void virtual Start() = 0;
    void virtual Update(const float) = 0;
    void virtual UpdateEvents(const sf::Event&) = 0;
    void virtual Render(sf::RenderWindow*) = 0;
    bool quit;

};