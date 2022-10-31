#include "intro_scene.hpp"

void IntroScene::Start() {

    this->quit = false;
    this->nativeSize = 512;

    this->logo.SetTexture("./res/img/logo.png");
    this->logo.SetPosition(sf::Vector2f(ApplicationManager::sizeX/2, ApplicationManager::sizeY/2));
    
    float logoScale = (ApplicationManager::sizeX * this->nativeSize / 1920.0) / this->logo.GetTexture().getSize().x;
    
    this->logo.SetScale(sf::Vector2f(logoScale, logoScale));

}

void IntroScene::Update(float const _dt) {

    

}

void IntroScene::UpdateEvents(sf::Event const &_event) {

    if(_event.type == sf::Event::KeyPressed)
        if(_event.key.code == sf::Keyboard::Escape) 
            this->quit = true;

}

void IntroScene::Render(sf::RenderWindow *_window) {

    this->logo.Render(_window);

}
