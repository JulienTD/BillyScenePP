/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

#include <string>
// #include "window/IWindow.hpp"

namespace bs {
    class IWindow;
    class IComponent {
        public:
            virtual ~IComponent() {};
            virtual std::string getId() = 0;
            virtual bool render(IWindow *window) = 0;
        protected:
        private:
    };
}
#endif /* !ICOMPONENT_HPP_ */
