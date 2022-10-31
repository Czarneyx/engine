#include "application.hpp"

int main() {
    
    Application app(sf::VideoMode(ApplicationManager::sizeX, ApplicationManager::sizeY), "Application engine");
    app.Run();

}