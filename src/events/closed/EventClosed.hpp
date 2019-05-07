/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** EventClosed
*/

#ifndef EVENTCLOSED_HPP_
#define EVENTCLOSED_HPP_

#include "events/IEvent.hpp"

namespace bs {
    class EventClosed : public IEvent {
        public:
            EventClosed();
            ~EventClosed();
            bool isCancelable() override;
            bool isCanceled() override;
            void setCanceled(bool canceled) override;
        protected:
        private:
            bool _isCanceled;
    };
}
#endif /* !EVENTCLOSED_HPP_ */
