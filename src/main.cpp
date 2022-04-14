#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <math.h>
#include "player.hpp"
#include "ball.hpp"
#include "tools.hpp"

int main()
{
    // Window creation
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Soccer");

    // Refresh time creation
    std::chrono::milliseconds refreshTime(10);

    // PlayGround creation
    sf::Texture playGroundTexture;
    if (!playGroundTexture.loadFromFile("images/playground.png"))
        std::cerr << "Error while loading image, check file name." << std::endl;
    sf::Sprite playGround ;
    playGround.setTexture(playGroundTexture);
    playGround.setPosition(0,0);
    

    // Player creation
    Player player1("images/player1.png");
    player1.setPosition(100., WINDOW_HEIGHT/2);
    // player1.setPosition(-28.28,-28.28);
    player1.setVelocity(0);
    player1.setRotation(0);

    Player player2("images/player2.png");
    player2.setPosition(WINDOW_WIDTH-100., WINDOW_HEIGHT/2);
    player2.setVelocity(0);
    player2.setRotation(180);
    
    // Ball creation
    Ball ball("images/ball.png");
    ball.setVelocity(1);
    ball.setRotation(180);
    ball.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    
    

    
    // Refresh loop
    while (window.isOpen())
    {
        
        // Manage event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }   

        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                window.close();
                break;
            case sf::Keyboard::Up:
                player1.accelerate();
                player2.accelerate();
                break;
            case sf::Keyboard::Left:
                player1.moveLeft();
                break;
            case sf::Keyboard::Right:
                player1.moveRight();
                break;
            case sf::Keyboard::Down:
                player1.slowDown();
                break;
            case sf::Keyboard::Z:
                player2.accelerate();
                break;
            case sf::Keyboard::Q:
                player2.moveLeft();
                break;
            case sf::Keyboard::S:
                player2.slowDown();
                break;
            case sf::Keyboard::D:
                player2.moveRight();
                break;
            
            default:
                break;
            }
            
        }

        // Update player movement
        if (player1.isCollision(ball))
            player1.collisions(&ball);
        if (player2.isCollision(ball))
            player2.collisions(&ball);
            
            
        
        player1.movePlayer();
        player2.movePlayer();
        ball.moveBall();

        // Refresh window
        window.clear(sf::Color(0x66, 0xCC, 0x66));
        window.draw(playGround);
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();


        // Wait 
        std::this_thread::sleep_for(refreshTime);
    }
    return 0;
}