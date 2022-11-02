#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include <cmath>

class ApplicationManager {

public:
    static void Initialize(sf::RenderWindow*);

    static bool pause;
    static int sizeX;
    static int sizeY;

    static sf::RenderWindow *window;

};