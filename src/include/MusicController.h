//
// Created by Sasha on 4/2/2023.
//

#ifndef MYGAME_MUSICCONTROLLER_H
#define MYGAME_MUSICCONTROLLER_H

#include <SFML/Audio.hpp>

class MusicController {
public:
    MusicController() {}

    static void init();

    static MusicController* instance;

    bool loadMusic(const std::string& filename);

    void play();

    void stop();
private:
    sf::Music music;
};

#endif //MYGAME_MUSICCONTROLLER_H
