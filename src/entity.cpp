#include "entity.hpp"

void Entity::SetTexture(std::string const _path) {

    this->texture.loadFromFile(_path);
    this->sprite.setTexture(this->texture);
    this->InitTexture();

}

void Entity::InitTexture() {

    this->sprite.setOrigin(sf::Vector2f(this->texture.getSize().x/2.0, this->texture.getSize().y/2.0));

}

void Entity::SetPosition(sf::Vector2f const _target) {

    this->sprite.setPosition(_target);
        
}

void Entity::Render(sf::RenderWindow *_window) {

    _window->draw(this->sprite);

}