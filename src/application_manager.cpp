#include "application.hpp"

bool ApplicationManager::pause;
int ApplicationManager::sizeX = 1920*2/3; 
int ApplicationManager::sizeY = 1080*2/3; 
std::string ApplicationManager::defaultFontPath = "./res/font/default_font.ttf";
sf::RenderWindow *ApplicationManager::window;

void ApplicationManager::Initialize(sf::RenderWindow *_window) {

    ApplicationManager::pause = false;
    ApplicationManager::window = _window;

}