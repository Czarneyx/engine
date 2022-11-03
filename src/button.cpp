#include "button.hpp"

Button::Button() {

    this->Initialization();

}

Button::Button(std::string const _msg, int const _characterSize, sf::Vector2f const _margin, sf::Color const _normalColor, sf::Color const _highlightedColor, sf::Color const _pressedColor, std::string _fontPath) {

    this->msg = _msg;
    this->characterSize = _characterSize;
    this->margin = _margin;
    this->normalColor = _normalColor;
    this->highlightedColor = _highlightedColor;
    this->pressedColor = _pressedColor;

    this->LoadFont(_fontPath);

    this->Initialization();

}

void Button::Initialization() {

    this->text = sf::Text(this->msg, this->font, this->characterSize);
    this->bgRect = sf::RectangleShape(sf::Vector2f(this->text.getGlobalBounds().width + this->margin.x * 2, this->text.getGlobalBounds().height + this->margin.y * 2));

    this->bgRect.setFillColor(this->normalColor);

    this->text.setOrigin(sf::Vector2f(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2));
    this->bgRect.setOrigin(sf::Vector2f(this->bgRect.getSize().x / 2, this->bgRect.getSize().y / 2));

}

void Button::LoadFont(std::string _fontPath) {

    this->font = sf::Font();
    this->font.loadFromFile(_fontPath);

}

void Button::SetPosition(sf::Vector2f const _position) {

    this->text.setPosition(_position);
    this->bgRect.setPosition(_position);

}

void Button::UpdateEvents(sf::Event const &_event ) {

    bool overButton = this->bgRect.getGlobalBounds().contains(sf::Mouse::getPosition(*ApplicationManager::window).x, sf::Mouse::getPosition(*ApplicationManager::window).y);
    
    if(_event.type == sf::Event::MouseButtonPressed)
        if(_event.mouseButton.button == sf::Mouse::Left) 
            this->pressing = true;

    if(overButton) {
        this->bgRect.setFillColor(highlightedColor);
    
        if(_event.type == sf::Event::MouseButtonReleased)
            if(_event.mouseButton.button == sf::Mouse::Left) {
                    this->isPressed = true;
                    this->pressing = false;
            }

        if(pressing)
            this->bgRect.setFillColor(pressedColor);

    } 
    else
        this->bgRect.setFillColor(normalColor);

    sf::RectangleShape ori = sf::RectangleShape(sf::Vector2f(5,5));

}

bool Button::IsPressed() {

    bool _tmp = this->isPressed;
    this->isPressed = false;
    return _tmp;

}

void Button::Render(sf::RenderWindow *_window) {

    _window->draw(this->bgRect);
    _window->draw(this->text);

}