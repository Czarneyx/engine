#include "menu_scene.hpp"

void MenuScene::Start() {

    this->quit = false;
    this->quitButton.SetPosition(sf::Vector2f(ApplicationManager::sizeX/2, ApplicationManager::sizeY/2));

}

void MenuScene::Update(float const _dt) {



}

void MenuScene::UpdateEvents(sf::Event const &_event) {

    this->quitButton.UpdateEvents(_event);

    if(this->quitButton.IsPressed())
        this->quit = true;

}

void MenuScene::Render(sf::RenderWindow *_window) {

    this->quitButton.Render(_window);

}