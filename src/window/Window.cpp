/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** Window
*/

#include "Window.hpp"

bs::Window::Window(std::string id, sf::VideoMode mode, const sf::String& title, \
                    sf::Uint32 style, const sf::ContextSettings& settings):
sf::RenderWindow(mode, title, style, settings),
_id(id),
_scenes(std::vector<std::unique_ptr<IScene>>()),
_currScene(nullptr),
_isRunning(false),
_timeRender(std::chrono::high_resolution_clock::now()),
_timeLogic(std::chrono::high_resolution_clock::now())
{
    // TODO: DESACTIVATE THE WINDOW
}

bs::Window::~Window()
{
    // this->getRenderWindow()->~RenderWindow();
    // sf::Window::~Window();
    // sf::RenderWindow::~RenderWindow();
    // printf("release !\n");
    // if (this->_logicThread.get() != nullptr)
        // this->_logicThread.reset();
    // if (this->_renderThread.get() != nullptr)
        // this->_renderThread.reset();
    // this->~RenderWindow();
    // delete(this->getRenderWindow());
}

std::string bs::Window::getId() const
{
    return (this->_id);
}

unsigned int bs::Window::getWidth() const
{
    return (this->getSize().x);
}

unsigned int bs::Window::getHeight() const
{
    return (this->getSize().y);
}

std::string bs::Window::getTitle() const
{
    return (this->getTitle());
}

bool bs::Window::start()
{
    if (this->_isRunning == true)
        return (false);
    printf("[Window] Starts the window !\n");
    this->_isRunning = true;
    this->setActive(true);
    // this->_logicThread = std::make_unique<std::thread>(&Window::interpretEvents, this);
    while (this->_isRunning == true) {
        if (this->isOpen() == false)
            continue;
        if (this->_currScene == nullptr)
            continue;
        this->interpretEvents();
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_timeRender).count();

        if (elapsedTime < (this->_currScene->getMaxFramePerSecond() / 60))
            continue;
        this->clear(sf::Color::Black);
        this->_currScene->render(this);
        this->display();
        this->_timeRender = now;
    }
    // this->_renderThread = std::make_unique<std::thread>(&Window::render, this);
    return (true);
}

bool bs::Window::stop()
{
    if (this->_isRunning == false)
        return (false);
    printf("[Window] Stops the window !\n");
    // if (this->_renderThread.get() != nullptr)
    //     this->_renderThread->join();
    // if (this->_logicThread.get() != nullptr)
    //     this->_logicThread->join();
    // if (this->_logicThread->joinable())
    //     this->_logicThread->join();
    this->_isRunning = false;
    this->close();
    // delete scenes
    return (true);
}

bool bs::Window::registerScene(std::unique_ptr<IScene> &scene, bool loadSceneComponents)
{
    for (const auto &scene : this->_scenes) {
        if (scene->getId() == scene->getId())
            return (false);
    }
    this->_scenes.insert(this->_scenes.begin(), std::move(scene));
    return (true);
}

bool bs::Window::startScene(std::string sceneId)
{
    for (const auto &scene : this->_scenes) {
        if (scene->getId() == scene->getId()) {
            this->_currScene = scene.get();
            if (this->_currScene == nullptr) {
                printf("Error: The scene is null !\n");
                continue;
            }
            this->setFramerateLimit(this->_currScene->getMaxFramePerSecond());
            return (true);
        }
    }
    return (false);
}

bool bs::Window::stopScene()
{
    if (this->_currScene == nullptr)
        return (false);
    this->_currScene = nullptr;
    return (true);
}

sf::RenderWindow *bs::Window::getRenderWindow()
{
    return (dynamic_cast<sf::RenderWindow *>(this));
}

bool bs::Window::render() // TODO: Gerer la partie render ici, c'est a dire gérer les ticks, ainsi que les fps ici
{
    printf("Start rendering !\n");
    while (this->_isRunning == true) {
        if (this->isOpen() == false)
            continue;
        if (this->_currScene == nullptr)
            continue;
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_timeRender).count();

        if (elapsedTime < (this->_currScene->getMaxFramePerSecond() / 60))
            continue;
        this->clear(sf::Color::Black);
        this->_currScene->render(this);
        this->display();
        this->_timeRender = now;
    }
    return (true);
}

bool bs::Window::interpretEvents() // les ticks ici && les events sans ticks
{
    // while (this->_isRunning = true) {
    //     if (this->isOpen() == false)
    //         continue;
    //     if (this->_currScene == nullptr)
    //         continue;
        sf::Event event;
        while (this->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                printf("Request to close\n");
                this->stop();
                return (true);
            }
        }
        if (this->_isRunning == false)
            return (true);
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_timeLogic).count();

        if (elapsedTime < (this->_currScene->getMaxTick() / 60))
            return (false);
            // continue;
        // this->_currScene->render(this);
        this->_timeLogic = now;
    // }
    return (true);
}

// void bs::Window::onCreate()
// {
//     // printf("[Event] THE WINDOW HAS BEEN CREATED !\n");
//     // this->setVisible(false);
// }

// void bs::Window::onResize()
// {
//     //Dispatch resize events
// }