#pragma once 

#include "menu_scene.hpp"

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
    std::vector<Scene*> OverloadGui;
    sf::Clock clock;
    float deltaTime;

    IntroScene introScene;
    MenuScene menuScene;
    PerformanceScene performanceScene;

};