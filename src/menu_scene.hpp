#pragma once

#include "intro_scene.hpp"

class MenuScene : public Scene {

public:
    void Start();
    void Update(float const);
    void UpdateEvents(sf::Event const&);
    void Render(sf::RenderWindow*);

private:
    Button quitButton = Button("QUIT", 24, sf::Vector2f(20, 10), sf::Color(0x0C, 0x7B, 0x93), sf::Color(0x27, 0x49, 0x6D), sf::Color(0x14, 0x85, 0x50));
    
};