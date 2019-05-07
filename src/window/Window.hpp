/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

#include <vector>
#include <functional>
#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
// #include <SFML/System/Thread.hpp>
#include "window/IWindow.hpp"

namespace bs {
    class Window : public bs::IWindow, public sf::RenderWindow {
        public:
            Window(std::string id, sf::VideoMode mode, const sf::String& title, \
                    sf::Uint32 style = sf::Style::Default, \
                    const sf::ContextSettings& settings = sf::ContextSettings());
            ~Window();
            std::string getId() const override;
            unsigned int getWidth() const override;
            unsigned int getHeight() const override;
            std::string getTitle() const override;
            bool start() override;
            bool stop() override;
            bool registerScene(std::unique_ptr<IScene> &scene, bool loadSceneComponents) override;
            bool startScene(std::string sceneId) override;
            bool stopScene() override;
            sf::RenderWindow *getRenderWindow() override;
            // void onCreate() override; // Maybe useless
            // void onResize() override; // Maybe useless
        protected:
            bool render() override; // Thread
            bool interpretEvents() override; // Thread
        private:
            std::string _id;
            std::vector<std::unique_ptr<IScene>> _scenes;
            IScene *_currScene;
            bool _isRunning;
            std::chrono::high_resolution_clock::time_point _timeRender;
            std::chrono::high_resolution_clock::time_point _timeLogic;
            // sf::RenderWindow *_rw;
            std::unique_ptr<std::thread> _renderThread; // Only renderr
            std::unique_ptr<std::thread> _logicThread; // Only logic
    };
}

#endif /* !WINDOW_HPP_ */
