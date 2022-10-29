#include "application.hpp"

Application::Application(sf::VideoMode _videoMode, std::string _windowName) {

    this->videoMode = _videoMode;
    this->windowName = _windowName;

    this->Initialize();
    ApplicationManager::Initialize();

}

void Application::Initialize() {

    this->window = new sf::RenderWindow(this->videoMode, this->windowName, sf::Style::Resize | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
    this->window->setFramerateLimit(60);

}

void Application::Start() {

    this->AddScene(&this->introScene);

}

void Application::Run() {

    this->Start();

    while(this->window->isOpen()) {

        this->Update();
        this->UpdateEvents();
        this->Render();

    }

}

void Application::Update() {

    this->deltaTime = this->clock.restart().asSeconds();

    if(this->scenes.size() > 0) {
        
        this->scenes.top()->Update(deltaTime);
        
        if(this->scenes.top()->quit)
            this->QuitScene();

    }

    if(this->scenes.size() == 0)
        this->Quit();

}

void Application::UpdateEvents() {

    sf::Event _event;
    while(this->window->pollEvent(_event)) {

        if(_event.type == sf::Event::Closed)
            this->Quit();

        if(this->scenes.size() > 0)
            this->scenes.top()->UpdateEvents(_event);

    }

}

void Application::Render() {

    this->window->clear();
    if(this->scenes.size() > 0)
        this->scenes.top()->Render(this->window);
    this->window->display();

}

void Application::Quit() {

    std::cout << "Quitting" << std::endl;
    this->window->close();

}

void Application::QuitScene() {

    if(this->scenes.size() > 0)
        this->scenes.pop();

}

void Application::AddScene(Scene *_scene) {

    this->scenes.push(_scene);
    this->scenes.top()->Start();

}