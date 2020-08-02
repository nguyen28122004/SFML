#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>

using namespace sf;
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    //Creat player
    RectangleShape player(Vector2f(200,200));
    player.setOrigin(player.getSize().x / 2 , player.getSize().y / 2);
    player.setPosition(player.getSize().x / 2 , player.getSize().y / 2);
    bool face = true;
    //Player texture
    Texture player_texture;
    player_texture.loadFromFile("chim.png");

    player.setTexture(&player_texture);

    //creat Animation
    Animation animation(&player_texture , Vector2u(3, 3) , 0.1f);
    Clock clock;
    float deltaTime = 0.0f;


	// Start the game loop
    while (app.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
        //Control player
        if(Mouse::isButtonPressed(Mouse::Left)){
            player.setPosition(Mouse::getPosition(app).x , Mouse::getPosition(app).y);
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::A)){
            player.move(-0.1f , 0);
            face = true;
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::D)){
            player.move(0.1f , 0);
            face = false;
        }




        // Clear screen
        app.clear();
        //Update player
        std::cout << (bool)face << std::endl;
        animation.Update(deltaTime ,face);

        player.setTextureRect(animation.uvRect);
        // Draw
        app.draw(player);



        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
