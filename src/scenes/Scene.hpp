/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

#include <memory>
#include <vector>
#include "scenes/IScene.hpp"
#include "window/IWindow.hpp"
#include "components/IComponent.hpp"

namespace bs {
    class Scene : public bs::IScene {
        public:
            Scene(std::string sceneId, unsigned int maxTick, unsigned int maxFramePerSecond);
            ~Scene();
            std::string getId() override;
            bool tick() override;
            bool render(IWindow *window) override;
            bool stop() override;
            unsigned int getMaxTick() override;
            unsigned int getMaxFramePerSecond() override;
            bool add(std::unique_ptr<IComponent> &component, std::string group) override;
        protected:
            std::string _sceneId;
            unsigned int _currTick;
            unsigned int _maxTick;
            unsigned int _maxFramePerSecond;
            std::vector<std::shared_ptr<IComponent>> _components;
        private:
    };
}

#endif /* !SCENE_HPP_ */
