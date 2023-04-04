#include "SFML/Graphics.hpp"
#include <GL/glu.h>

#include "src/include/MusicController.h"

#include "iostream"

MusicController* MusicController::instance;

float angle = 0.0f;

float angle2 = 0.0f;

int main()
{
    MusicController::init();

    sf::Clock clock;

    // Створення вікна
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML OpenGL");

    // Налаштування OpenGL
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST); // Включаємо тест глибини
    glDisable(GL_BLEND);     // Вимикаємо змішування кольорів
    glLoadIdentity();
    gluPerspective(45.0f, (float)window.getSize().x / (float)window.getSize().y, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    // Головний цикл програми
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        // Обробка подій
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Очищення буферів екрану та глибини
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Налаштування камери та виконання перетворення для позиції частини куба
        glLoadIdentity();
        glTranslatef(-1.5f, 0.0f, -6.0f);

        const float rotation_speed = 100.0f;

        angle += rotation_speed * deltaTime;
        angle2 += 110 * deltaTime;
        std::cout << deltaTime << " " << angle << std::endl;

        if (angle > 360.f) {
            angle = 0;
        }

        // Налаштування матеріалу для куба
        GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
        GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
        GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat mat_shininess[] = { 50.0f };
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

// Налаштування джерела світла
        GLfloat light_position[] = { 0.0f, 0.0f, 5.0f, 1.0f };
        GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
        GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);

        GLfloat colors[6][3] = {
                {1.0f, 0.0f, 0.0f}, // Червоний
                {0.0f, 1.0f, 0.0f}, // Зелений
                {0.0f, 0.0f, 1.0f}, // Синій
                {1.0f, 1.0f, 0.0f}, // Жовтий
                {1.0f, 0.0f, 1.0f}, // Фіолетовий
                {0.0f, 1.0f, 1.0f}  // Бірюзовий
        };


        for (int i = 0; i < 2; ++i) {
            glPushMatrix();
            glRotatef(i * 120.0f + angle, 1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
            glColor3fv(colors[i]); // Унікальний колір для кожної сторони
            glVertex3f(-1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glEnd();
            glPopMatrix();
        }

        window.display();
    }

    return 0;
}