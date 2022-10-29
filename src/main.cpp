#include "application.hpp"

int main() {
    
    Application app(sf::VideoMode(ApplicationManager::SIZE_X, ApplicationManager::SIZE_Y), "Application engine");
    app.Run();

}