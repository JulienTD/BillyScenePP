/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

#include <SFML/Graphics/RectangleShape.hpp>
#include "window/IWindow.hpp"
#include "components/IComponent.hpp"

namespace bs {
    class Button : public bs::IComponent, public sf::RectangleShape {
        public:
            Button(std::string id);
            ~Button();
            std::string getId() override;
            bool render(IWindow *window) override;
        protected:
        private:
            std::string _id;
    };
}
#endif /* !BUTTON_HPP_ */
