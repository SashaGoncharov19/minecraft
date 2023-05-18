//
// Created by Sasha on 5/19/2023.
//

#ifndef MYGAME_BUTTON_H
#define MYGAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Font& font, const std::string& text)
    {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color::Green);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(24);
        label.setFillColor(sf::Color::Black);
        label.setPosition(position.x + size.x / 2 - label.getLocalBounds().width / 2,
                          position.y + size.y / 2 - label.getLocalBounds().height / 2);
    }

    bool isMouseOver(sf::RenderWindow& window)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f buttonPosition = shape.getPosition();
        sf::Vector2f buttonSize = shape.getSize();

        return (mousePosition.x >= buttonPosition.x && mousePosition.x <= buttonPosition.x + buttonSize.x &&
                mousePosition.y >= buttonPosition.y && mousePosition.y <= buttonPosition.y + buttonSize.y);
    }

    static void handleClick()
    {
        std::cout << "Button Clicked!" << std::endl;
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(label);
    }

private:
    sf::RectangleShape shape;
    sf::Text label;
};



#endif //MYGAME_BUTTON_H
