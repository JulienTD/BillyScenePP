/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Scene
*/

#include "Scene.hpp"

bs::Scene::Scene(std::string sceneId, unsigned int maxTick, unsigned int maxFramePerSecond):
_sceneId(sceneId),
_currTick(0),
_maxTick(maxTick),
_maxFramePerSecond(maxFramePerSecond),
_components(std::vector<std::shared_ptr<IComponent>>())
{
    printf("Scene has been created! \nName: %s\n", sceneId.c_str());
}

bs::Scene::~Scene()
{
    for (auto ptr : this->_components) {
        ptr.reset();
    }
}

std::string bs::Scene::getId()
{
    return (this->_sceneId);
}

bool bs::Scene::tick()
{
    return (true);
}

bool bs::Scene::render(IWindow *window)
{
    for (auto component : this->_components)
        component->render(window);
    return (true);
}

bool bs::Scene::stop()
{
    return (true);
}

unsigned int bs::Scene::getMaxTick()
{
    return (this->_maxTick);
}

unsigned int bs::Scene::getMaxFramePerSecond()
{
    return (this->_maxFramePerSecond);
}

bool bs::Scene::add(std::unique_ptr<IComponent> &component, std::string group = "") // panel system
{
    this->_components.insert(this->_components.begin(), std::move(component));
    return (true);
}
