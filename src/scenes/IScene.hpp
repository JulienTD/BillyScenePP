/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
    #define ISCENE_HPP_


#include <string>
#include <memory>
// #include "window/IWindow.hpp"
#include "components/IComponent.hpp"

namespace bs {
    class IWindow;
    class IScene {
        public:
            virtual ~IScene() {};

            /**
             * @brief Gets the scene's id
             *
             * @return std::string scene's id
             */
            virtual std::string getId() = 0;

            /**
             * @brief Ticks the scene
             *
             * @return true if the function has been ticked successfully
             * @return false if the function hasn't been ticked properly
             */
            virtual bool tick() = 0;

            /**
             * @brief Renders the scene
             *
             * @param window window to render on it
             * @return true if the window has been rendered successfully
             * @return false if the window hasn't been rendered properly
             */
            virtual bool render(IWindow *window) = 0;

            /**
             * @brief Stopped the scene
             *
             * @return true if the scene has been stopped
             * @return false if the scene hasn't been stopped
             */
            virtual bool stop() = 0;

            /**
             * @brief Get the Max Tick object
             * 
             * @return unsigned int 
             */
            virtual unsigned int getMaxTick() = 0;
            virtual unsigned int getMaxFramePerSecond() = 0;
            virtual bool add(std::unique_ptr<IComponent> &component, std::string group = "") = 0;
        protected:
        private:
    };
}

#endif /* !ISCENE_HPP_ */
