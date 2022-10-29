#include "scene.hpp"

class PerformanceScene : public Scene {

public:
    void Start();
    void Update(float const);
    void UpdateEvents(sf::Event const&);
    void Render(sf::RenderWindow*);
    
    // Quit is used as an active / distractive state 

private:
    sf::Text frameRateText;
    sf::Font frameRateTextFont;
    
    int lastFrame; 
    int fpsArrayLength = 50;
    float *fpsArray;

    bool canSwitchState;

};