#pragma once 

#include "intro_scene.hpp"

class Application {

public:
    Application(sf::VideoMode, std::string);
    void Run();

private:
    void Initialize();
    void Start(); 
    void Update();
    void UpdateEvents();
    void Render();
    void Quit();

    void QuitScene();
    void AddScene(Scene*);

    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    std::string windowName;
    std::stack<Scene*> scenes;
    sf::Clock clock;
    float deltaTime;

    IntroScene introScene;

};