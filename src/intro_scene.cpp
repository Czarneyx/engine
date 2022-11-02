#include "intro_scene.hpp"

void IntroScene::Start() {

    this->quit = false;
    this->fading = false;
    this->waitingToSkip = false;
    this->alphaValue = 0;

    this->logo.SetTexture("./res/img/logo.png");
    this->logo.SetPosition(sf::Vector2f(ApplicationManager::sizeX/2, ApplicationManager::sizeY/2));
    
    float logoScale = (ApplicationManager::sizeX * this->nativeSize / 1920.0) / this->logo.GetTexture().getSize().x;
    
    this->logo.SetScale(sf::Vector2f(logoScale, logoScale));
    this->logo.SetAlpha(0);

    this->clock.restart();

}

void IntroScene::Update(float const _dt) {

    if(!this->waitingToSkip && this->clock.getElapsedTime().asSeconds() > this->startDelay) {

        if(!this->fading) {

            this->alphaValue += this->alphaSpeed * _dt;

            if(this->alphaValue >= 255) {

                this->alphaValue = 255;
                this->fading = true;

            }

        }
        else {

            this->alphaValue -= this->alphaSpeed * _dt;

            if(this->alphaValue <= 0) {

                this->alphaValue = 0;
                this->waitingToSkip = true;
                this->clock.restart();

            }

        }

    }
    
    if(this->waitingToSkip && this->clock.getElapsedTime().asSeconds() > this->skipDelay)
        this->quit = true;

    this->logo.SetAlpha(this->alphaValue);

}

void IntroScene::UpdateEvents(sf::Event const &_event) {

    if(_event.type == sf::Event::KeyPressed)
        if(_event.key.code == sf::Keyboard::Escape) 
            this->quit = true;
            
}

void IntroScene::Render(sf::RenderWindow *_window) {

    this->logo.Render(_window);

}
