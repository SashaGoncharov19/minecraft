//
// Created by Sasha on 4/2/2023.
//

#include "iostream"
#include "../include/MusicController.h"

using namespace std;

void MusicController::init() {
    instance = new MusicController;
}

bool MusicController::loadMusic(const string &filename) {
    if (!music.openFromFile(filename)) {
        cout << "ERROR" << endl;
        return false;
    }

    music.setLoop(true);
    return true;
}

void MusicController::play() {
    music.play();
}

void MusicController::stop() {
    music.stop();
}