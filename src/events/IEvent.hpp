/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** IEvent
*/

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

class IEvent {
    public:
        virtual ~IEvent() {};
        virtual bool isCancelable() = 0;
        virtual bool isCanceled() = 0;
        virtual void setCanceled(bool canceled) = 0;
    protected:
    private:
};

#endif /* !IEVENT_HPP_ */
