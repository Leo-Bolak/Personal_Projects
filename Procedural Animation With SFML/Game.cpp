#include "Game.h"

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const float FPS = 60.0f;

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Procedural Animation")
    , timePerFrame(sf::seconds(1.0f / FPS))
{
    window.setFramerateLimit(static_cast<unsigned int>(FPS));
    init();
}

void Game::init()
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate >= timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processEvents();
            update(timePerFrame);
        }

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();
    }
}

void Game::update(sf::Time deltaTime)
{
    mousePos = { static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };
    std::cout << "X: " << mousePos.x << " Y: " << mousePos.y << std::endl;

    fish[0].setPosition(mousePos); // constantly sets fish head to the mouse position

    for (int count = 1; count < FISH_LENGTH; count++) // loops through fish body to adjust each segments position
    {
        fish[count].distanceConstraint(fish[count - 1].getPosition());
    }
}

void Game::render()
{
    window.clear();
    for (int count = 0; count < FISH_LENGTH; count++)
    {
        fish[count].draw(window);
    }
    window.display();
}