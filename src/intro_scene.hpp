#pragma once

#include "scene.hpp"

class IntroScene : public Scene {

public:
    void Start();
    void Update(float const);
    void UpdateEvents(sf::Event const&);
    void Render(sf::RenderWindow*);

private:
    Entity logo;

    int nativeSize;

};