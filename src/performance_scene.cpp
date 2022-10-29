#include "performance_scene.hpp"

void PerformanceScene::Start() {

    quit = true;
    canSwitchState = true;

    this->frameRateTextFont.loadFromFile("./res/font/display_font.ttf");
    this->frameRateText.setFont(this->frameRateTextFont);
    this->frameRateText.setFillColor(sf::Color::Green);
    this->frameRateText.setCharacterSize(24);

    this->fpsArray = new float[fpsArrayLength];
    this->lastFrame = 0;

}

void PerformanceScene::Update(float const _dt) {

    this->fpsArray[this->lastFrame] = 1/_dt;
    this->lastFrame = (this->lastFrame+1) % this->fpsArrayLength;

    float average = 0;
    for(int i = 0; i < this->fpsArrayLength; i++)
        average += fpsArray[i];

    average /= fpsArrayLength;

    this->frameRateText.setString(std::to_string(int(std::round(average))));

}

void PerformanceScene::Render(sf::RenderWindow *_window) {

    _window->draw(this->frameRateText);

}

void PerformanceScene::UpdateEvents(sf::Event const &_event) {

    if(_event.type == sf::Event::KeyPressed)
        if(_event.key.code == sf::Keyboard::Numpad0) 
            if(this->canSwitchState) {
                
                this->quit = !this->quit;
                this->canSwitchState = false;

            }

    if(_event.type == sf::Event::KeyReleased)
        if(_event.key.code == sf::Keyboard::Numpad0) 
            if(!this->canSwitchState) 
                this->canSwitchState = true;

}