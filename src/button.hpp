#pragma once

#include "application_manager.hpp"

class Button {

public:
    Button();
    Button(std::string const, int const, sf::Vector2f const, sf::Color const, sf::Color const, sf::Color const, std::string = ApplicationManager::defaultFontPath);
    void UpdateEvents(sf::Event const&);
    void Render(sf::RenderWindow*);
    void LoadFont(std::string);
    void SetPosition(sf::Vector2f const);
    bool IsPressed();

private:
    void Initialization();

    std::string msg = "Button";
    int characterSize = 24;
    sf::Vector2f margin = sf::Vector2f(8,4);
    sf::Color normalColor  = sf::Color(220, 55, 55);
    sf::Color highlightedColor  = sf::Color(55, 220, 55);
    sf::Color pressedColor  = sf::Color(55, 55, 220);

    sf::Font font;
    sf::Text text;
    sf::RectangleShape bgRect;

    bool isPressed = false;
    bool pressing = false;

};