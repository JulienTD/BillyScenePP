/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** EventDispatcher
*/

#include "EventDispatcher.hpp"

EventDispatcher::EventDispatcher()
{
}

EventDispatcher::~EventDispatcher()
{
}

void EventDispatcher::dispatchEvents(sf::Event &event)
{
    switch (event.type) {
        case sf::Event::Closed:
            printf("Closed event\n");
            break;
        default:
    }
}