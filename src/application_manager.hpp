#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include <cmath>

class ApplicationManager {

public:
    static void Initialize();

    static bool pause;
    static const int SIZE_X = 720;
    static const int SIZE_Y = 480;

};