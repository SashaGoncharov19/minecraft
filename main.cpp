#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "random.h"

#include "matrix.hpp"
#include "vector.h"
#include "cube.h"

constexpr float PI = 3.14159265359;

class MusicController {
public:
    MusicController() {}

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

int main()
{
    glEnable(GL_TEXTURE_2D);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Minecraft", sf::Style::Close); // | sf::Style::Fullscreen

    MusicController musicController;
    musicController.loadMusic("assets/sound.wav");
    musicController.play();

    Cube cube(Vector3(-100.f, -100.f, 100.f), Vector3(200.f, 200.f, 200.f), Vector3());

    Vector3 cameraPos(0.f, 0.f, 0.f);

    sf::Clock deltaClock;
    sf::Clock timePassed;

    float randomRotation = 1.f;

    while (window.isOpen()) {
        sf::Event event;

        float dt = deltaClock.restart().asSeconds();

        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) cameraPos += Vector3(50.f*dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  cameraPos -= Vector3(50.f*dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  cameraPos += Vector3(0.f, 50.f*dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    cameraPos -= Vector3(0.f, 50.f*dt);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))     cameraPos += Vector3(0.f, 0.f, 50.f*dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))     cameraPos -= Vector3(0.f, 0.f, 50.f*dt);

        randomRotation += (static_cast<float>(rand() % 100) - 50.f) / 1000.f * dt;

        cube.rotate(Vector3(PI * dt * .4 * randomRotation, PI * dt * .6 * randomRotation, PI * dt * .34 * randomRotation));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) cube.rotate(Vector3(-PI / 2 * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) cube.rotate(Vector3(PI/2 * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)) cube.rotate(Vector3(0.f, -PI/2 * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) cube.rotate(Vector3(0.f, PI/2 * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) cube.rotate(Vector3(0.f, 0.f, PI/2 * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) cube.rotate(Vector3(0.f, 0.f, -PI/2 * dt));

        window.clear();

        cube.draw(
                window,
                cameraPos
        );

        window.display();
    }
}