#include "intro_scene.hpp"

void IntroScene::Start() {

    this->quit = false;

    this->logo.SetTexture("./res/img/logo.png");
    this->logo.SetPosition(sf::Vector2f(ApplicationManager::SIZE_X/2, ApplicationManager::SIZE_Y/2));

}

void IntroScene::Update(float const _dt) {

    // std::cout << "FPS: " << 1/_dt << std::endl;

}

void IntroScene::UpdateEvents(sf::Event const &_event) {

    if(_event.type == sf::Event::KeyPressed)
        if(_event.key.code == sf::Keyboard::Escape) 
            this->quit = true;

}

void IntroScene::Render(sf::RenderWindow *_window) {

    this->logo.Render(_window);

}
