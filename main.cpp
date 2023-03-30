#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <valarray>

class MusicController {
public:
    MusicController() {}

    static void init() {
        instance = new MusicController;
    };

    static MusicController* instance;

    bool loadMusic(const std::string& filename) {
        if (!music.openFromFile(filename)) {
            std::cout << "ERROR" << std::endl;
            return false;
        }

        music.setLoop(true);
        return true;
    }

    void play() {
        music.play();
    }

    void stop() {
        music.stop();
    }
private:
    sf::Music music;
};

MusicController* MusicController::instance;

int main()
{
    MusicController::init();

    glEnable(GL_TEXTURE_2D);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Minecraft", sf::Style::Close); // | sf::Style::Fullscreen

//    MusicController::instance->loadMusic("assets/sound/music.wav");
//    MusicController::instance->play()

    sf::View camera;
    sf::Vector2f lastMousePos;
    float cameraRotationSpeed = 0.1f;
    float maxRotationSpeed = 1.0f;
    bool isMouseDragging = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseMoved:
                    if (isMouseDragging) {
                        // Получение изменения положения курсора мыши
                        sf::Vector2f mousePos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                        sf::Vector2f delta = mousePos - lastMousePos;

                        // Обработка изменения камеры по оси X
                        float rotationX = delta.x * cameraRotationSpeed;
                        rotationX = std::min(std::max(rotationX, -maxRotationSpeed), maxRotationSpeed);
                        camera.rotate(rotationX);

                        // Обработка изменения камеры по оси Y
                        float rotationY = delta.y * cameraRotationSpeed;
                        rotationY = std::min(std::max(rotationY, -maxRotationSpeed), maxRotationSpeed);
                        camera.rotate(rotationY);

                        lastMousePos = mousePos;
                    }
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isMouseDragging = true;
                        lastMousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isMouseDragging = false;
                    }
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        window.setView(camera);

        sf::RectangleShape rect(sf::Vector2f(100, 100));

        rect.setFillColor(sf::Color::Red);
        rect.setOrigin(rect.getSize() / 2.0f);
        rect.setPosition(150.f, 150.f);

        window.clear();

        window.draw(rect);

        window.display();
    }
}
