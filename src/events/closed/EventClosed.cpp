/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** EventClosed
*/

#include "EventClosed.hpp"

bs::EventClosed::EventClosed():
_isCanceled(false)
{
}

bs::EventClosed::~EventClosed()
{
}


bool bs::EventClosed::isCancelable()
{
    return (false);
}

bool bs::EventClosed::isCanceled()
{
    return (this->_isCanceled);
}

void bs::EventClosed::setCanceled(bool canceled)
{
    this->_isCanceled = canceled;
}