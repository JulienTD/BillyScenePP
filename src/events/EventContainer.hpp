/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** EventContainer
*/

#ifndef EVENTCONTAINER_HPP_
#define EVENTCONTAINER_HPP_

#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>

class EventContainer {
    public:
        EventContainer();
        ~EventContainer();
        void registerFunction(sf::Event event, std::function<void (...)> func); // not sure about ...
        std::vector<std::function<void>> getFunctionsByEvents(sf::Event event);
    protected:
    private:
};

#endif /* !EVENTCONTAINER_HPP_ */
