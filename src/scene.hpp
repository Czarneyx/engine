#pragma once

#include "entity.hpp"

class Scene {

public:
    void virtual Start() = 0;
    void virtual Update(float const) = 0;
    void virtual UpdateEvents(sf::Event const&) = 0;
    void virtual Render(sf::RenderWindow*) = 0;
    bool quit;

};