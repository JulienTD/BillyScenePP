/*
** EPITECH PROJECT, 2019
** BillyScenePP
** File description:
** main
*/

#include <unistd.h>
#include "window/Window.hpp"
#include "scenes/Scene.hpp"
#include "components/button/Button.hpp"


#include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }

int main(void)
{
    std::unique_ptr<bs::Window> window = std::make_unique<bs::Window>("main_window", sf::VideoMode(800, 600), "my title");
    std::unique_ptr<bs::IScene> scene = std::make_unique<bs::Scene>("my_custom_scene", 20, 60);
    std::unique_ptr<bs::IComponent> button = std::make_unique<bs::Button>("custom button");

    printf("MAIN: Scene id: %s\n", scene->getId().c_str());
    printf("MAIN: Button id: %s\n", button->getId().c_str());

    scene->add(button);
    window->registerScene(scene, false);
    if (window->startScene("my_custom_scene") == true)
        printf("The scene has been started !\n");
    else
        printf("Error while starting the scene !\n");
    window->start();

    // sleep(10);
    // window->stop();
    return (0);
}