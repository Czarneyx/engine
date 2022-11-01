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
    sf::Clock clock;

    const float startDelay = 2;
    const float skipDelay = .87;
    const float alphaSpeed = 67;
    const int nativeSize = 512;
    
    float alphaValue;
    bool waitingToSkip;
    bool fading;

};