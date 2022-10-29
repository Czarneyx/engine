#include "application.hpp"

Application::Application(sf::VideoMode _videoMode, std::string _windowName) {

    this->videoMode = _videoMode;
    this->windowName = _windowName;

    this->Initialize();
    ApplicationManager::Initialize();

}

void Application::Initialize() {

    this->window = new sf::RenderWindow(this->videoMode, this->windowName, sf::Style::None | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
    this->window->setFramerateLimit(60);

}

void Application::Start() {

    this->AddScene(&this->introScene);
    
    this->OverloadGui.push_back(&this->performanceScene);
    this->performanceScene.Start();

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

    for(Scene* scene : this->OverloadGui)
        if(!scene->quit)
            scene->Update(this->deltaTime);

}

void Application::UpdateEvents() {

    sf::Event event;
    while(this->window->pollEvent(event)) {

        if(event.type == sf::Event::Closed)
            this->Quit();

        if(this->scenes.size() > 0)
            this->scenes.top()->UpdateEvents(event);

        for(Scene* scene : this->OverloadGui)
            scene->UpdateEvents(event);
    
    }

}

void Application::Render() {

    this->window->clear();

    if(this->scenes.size() > 0)
        this->scenes.top()->Render(this->window);

    for(Scene* scene : this->OverloadGui)
        if(!scene->quit)
            scene->Render(this->window);

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