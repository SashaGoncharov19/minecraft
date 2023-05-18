#include "iostream"
#include "SFML/Graphics.hpp"
#include "src/include/MusicController.h"
#include "src/include/Button.h"

MusicController* MusicController::instance;

int main()
{
    MusicController::init();
    MusicController::instance->loadMusic("assets/sound/music.wav");
    MusicController::instance->play();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML OpenGL");

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    Button button(sf::Vector2f(0, 0), sf::Vector2f(100, 50), font, "Click Me!");

    sf::RectangleShape Player(sf::Vector2f(100, 100));
    Player.setFillColor(sf::Color::Blue);
    Player.setPosition(0, 0);

    sf::Clock clock;

    float movementSpeed = 50.0f;

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                if (button.isMouseOver(window))
                    Button::handleClick();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            Player.move(0, -movementSpeed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            Player.move(0, movementSpeed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            Player.move(-movementSpeed * deltaTime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            Player.move(movementSpeed * deltaTime, 0);

        window.clear();
        window.draw(Player);
        button.draw(window);

        window.display();
    }

    return 0;
}