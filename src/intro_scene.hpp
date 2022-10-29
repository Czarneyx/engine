#include "scene.hpp"

class IntroScene : public Scene {

public:
    void Start();
    void Update(const float);
    void UpdateEvents(const sf::Event&);
    void Render(sf::RenderWindow*);

private:
    Entity logo;

};