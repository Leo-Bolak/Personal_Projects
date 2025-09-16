#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Segment.h"

class Game
{
public:
    Game();
    void run();

private:
    void init();
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    sf::Time timePerFrame;

    const static int FISH_LENGTH = 10;

    Segment fish[FISH_LENGTH] = { 15, 25, 35, 35, 30, 25, 20, 15, 10, 5 };

    sf::Vector2f mousePos;

};