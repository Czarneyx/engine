#include "application.hpp"

bool ApplicationManager::pause;
int ApplicationManager::sizeX = 1920*2/3; 
int ApplicationManager::sizeY = 1080*2/3; 

void ApplicationManager::Initialize() {

    ApplicationManager::pause = false;

}