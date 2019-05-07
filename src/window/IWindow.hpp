/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "scenes/IScene.hpp"

namespace bs {
    class IWindow {
        public:
            virtual ~IWindow() {};

            /**
             * @brief Gets the window's id
             *
             * @return std::string window's id
             */
            virtual std::string getId() const = 0;

            /**
             * @brief Gets the window's width
             *
             * @return unsigned int window' width
             */
            virtual unsigned int getWidth() const = 0;

            /**
             * @brief Gets the window's height
             *
             * @return unsigned int window's height
             */
            virtual unsigned int getHeight() const = 0;

            /**
             * @brief Gets the window's title
             *
             * @return std::string window's title
             */
            virtual std::string getTitle() const = 0;

            /**
             * @brief Starts the window
             *
             * @return true if the window has been started successfully
             * @return false if the window hasn't been started
             */
            virtual bool start() = 0;

            /**
             * @brief Stops the window
             *
             * @return true if the window has been stopped successfully
             * @return false if the window hasn't been stopped
             */
            virtual bool stop() = 0;

            /**
             * @brief Register a scene to the window
             *
             * @param scene unique ptr of the scene, be careful once the scene registered you can't modify it directly by the pointer you provided to the function
             * @param loadSceneComponents if the scene's components must be initialize directly or later during the function @ref startScene()
             * @return true if the scene has been registered
             * @return false if the scene hasn't been registered
             */
            virtual bool registerScene(std::unique_ptr<bs::IScene> &scene, bool loadSceneComponents) = 0;

            /**
             * @brief Starts a scene by its id
             *
             * @param sceneId id of the requested scene
             * @return true if the scene has been started
             * @return false if the scene has not been started
             */
            virtual bool startScene(std::string sceneId) = 0;

            /**
             * @brief Stops the current scene
             *
             * @return true if the scene has been stopped
             * @return false if the scene has not been stopped
             */
            virtual bool stopScene() = 0;

            /**
             * @brief Gets the render window
             *
             * @return sf::RenderWindow* render window to render components
             */
            virtual sf::RenderWindow *getRenderWindow() = 0;
        protected:
            /**
             * @brief Renders the scene. This function is used only in internal.
             *
             * @return true if the window has been rendered
             * @return false if the window has not been rendered
             */
            virtual bool render() = 0;

            /**
             * @brief Interprets the scene/window's events. This function is used only in internal.
             *
             * @return true if the window has been rendered
             * @return false if the window has not been rendered
             */
            virtual bool interpretEvents() = 0;
        private:
    };
}

#endif /* !IWINDOW_HPP_ */
