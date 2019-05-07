/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Button
*/

#include "Button.hpp"

bs::Button::Button(std::string id):
sf::RectangleShape(sf::Vector2f(100, 200)),
_id(id)
{
    sf::Event::Closed;
}

bs::Button::~Button()
{
}

std::string bs::Button::getId()
{
    return (this->_id);
}

bool bs::Button::render(IWindow *window)
{
    if (window == nullptr)
        return (false);
    this->setFillColor(sf::Color::Blue);
    this->setPosition(sf::Vector2f(10, 10));
    this->setSize(sf::Vector2f(100, 50));
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(5);
    this->setPosition(10, 20);
    window->getRenderWindow()->draw(*dynamic_cast<sf::RectangleShape *>(this));
    return (true);
}
