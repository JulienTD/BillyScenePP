/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** EventDispatcher
*/

#ifndef EVENTDISPATCHER_HPP_
#define EVENTDISPATCHER_HPP_

#include <SFML/Graphics.hpp>

class EventDispatcher {
    public:
        EventDispatcher();
        ~EventDispatcher();
        void dispatchEvents(sf::Event &event);
    protected:
    private:
};

#endif /* !EVENTDISPATCHER_HPP_ */
