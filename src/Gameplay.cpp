#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include "../include/Gameplay.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <assert.h>

int Gameplay::init () {
	isShoot = 0;
	std::srand (static_cast<unsigned int>(std::time (NULL)));
	window.setFramerateLimit (60); // call it once, after creating the window
	
	assert (thrust_sound_buffer.loadFromFile ("resources/thrust.wav"));
	thrust_sound.setBuffer (thrust_sound_buffer);

	// Load the text font
	if (!fontHNMed.loadFromFile ("resources/HelveticaNeueMed.ttf"))
		return EXIT_FAILURE;
	if (!fontHNM.loadFromFile ("resources/HelveticaNeue Medium.ttf"))
		return EXIT_FAILURE;
	if (!fontHNL.loadFromFile ("resources/HelveticaNeue Light.ttf"))
		return EXIT_FAILURE;

	// Life text
	lifeText.setFont (fontHNMed);
	lifeText.setCharacterSize (30);
	lifeText.setOutlineThickness (1);
	lifeText.setOutlineColor (sf::Color::White);
	lifeText.setFillColor (sf::Color::Red);
	lifeText.setString ("Life: 3");
	lifeText.setPosition (10.f, gameHeight - 40.f);

	// Score text
	score.setFont (fontHNL);
	score.setCharacterSize (30);
	score.setFillColor (sf::Color (239, 187, 56));

	// Welcome background
	bgTex.loadFromFile ("resources/bg.jpg");
	sf::Vector2f sz ((float)window.getSize ().x, (float)window.getSize ().y);
	shape.setSize (sz);
	shape.setTexture (&bgTex);

	// Select game mode
	gameState = selectMode (window);
	//restart ();

	// Game loop window
	while (window.isOpen ()) {
		while (window.pollEvent (event)) {
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
				gameState = selectMode (window);  //To be made as resumeWindow ()
				//restart ();
				if (gameState == -1)
					return EXIT_SUCCESS;
				break;
			}

			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space)) {				
				isShoot = 1;
				lazers.push_back (Lazer ());
				if (!lazers.empty () && shotClock.getElapsedTime().asSeconds() >= 0.25f) {
					lazers.back ().rect.setRotation (ship.sprite.getRotation ());
					lazers.back ().rect.setPosition (ship.sprite.getPosition ());
				}
				shotClock.restart ();
			}
			/*if (gameState == MODE1 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				gameState = RESUME1;
			}*/
		}

		deltaTime = clock.restart ().asSeconds ();

		if (gameState == MODE1) {
			gameMode1 ();
		}

		renderFrame ();
		window.display ();
	}

	return EXIT_SUCCESS;
}

void Gameplay::renderFrame () {
	// Win text
	sf::Text wonText ("You won!\nPress esc to menu.", fontHNM, 40);
	wonText.setPosition (gameWidth / 2 - wonText.getGlobalBounds ().width / 2, gameHeight / 2 - wonText.getGlobalBounds ().height / 2);
	wonText.setFillColor (sf::Color::White);

	// Lost text
	sf::Text lostText ("You lost!\nPress esc to menu.", fontHNM, 40);
	lostText.setPosition (gameWidth / 2 - lostText.getGlobalBounds ().width / 2, gameHeight / 2 - lostText.getGlobalBounds ().height / 2);
	lostText.setFillColor (sf::Color::White);

	window.clear ();
	window.draw (shape);
	window.draw (lifeText);
	window.draw (ship.sprite);

	if (gameState == MODE1 || gameState == RESUME1) {
		int i = 0;
		for (std::vector<Lazer>::iterator it = lazers.begin (); it != lazers.end (); ++it) {
			it->rect.move (sin (it->rect.getRotation () / 360 * 2 * pi) * it->velocity, -cos (it->rect.getRotation () / 360 * 2 * pi) * it->velocity);
			window.draw (it->rect);
		}
	} else if (gameState == P1LOST) {
		window.draw (lostText);
	} else if (gameState == P1WIN) {
		window.draw (wonText);
	}
}

int Gameplay::selectMode (sf::RenderWindow& window) {
	life = 3;

	// Welcome text
	sf::Text welcome[5];
	std::string msg[5] = { "Press 1 - You VS Ai", "2 - You + Friend VS 2 Ai" , "Player1 uses WSAD", "Player2 uses Arrow Keys.", "Press Esc to exit." };
	for (int i = 0; i < 5; i++) {
		welcome[i].setPosition (50.0f, 50.0f * (i + 1));
		welcome[i].setFillColor (sf::Color (239, 187, 56));
		welcome[i].setCharacterSize (30);
		welcome[i].setString (msg[i]);
		welcome[i].setFont (fontHNMed);
	}

	// Main loop
	while (true) {
		sf::Event event;
		while (window.pollEvent (event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close ();
				return -1;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num1) {
				gameState = MODE1;
				//level1 ();
				window.clear ();
				shotClock.restart ();
				return gameState;
			} else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num2) {
				gameState = MODE2;
				window.clear ();
				shotClock.restart ();
				return gameState;
			}
		}
		window.clear ();
		// Put text and wait for select
		window.draw (shape);
		for (int i = 0; i < 5; i++)
			window.draw (welcome[i]);

		window.display ();
	}
}

int Gameplay::gameMode1 () {
	if (ship.velocity > 0.f) {
		ship.velocity -= deltaTime;
		if (isUp == 1) {
			ship.sprite.move (sin (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity, -cos (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity);
		} else if (isUp == -1) {
			ship.sprite.move (-sin (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity, cos (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity);
		}
	} else if (ship.velocity < 0.f) {
		ship.velocity = 0.f;
		isUp = 0;
	}

	// Move the player's ship
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up)) {
		isUp = 1;
		ship.velocity = ship.acceleration * deltaTime;
		ship.sprite.move (sin (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity, -cos (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity);
	}

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down)) {
		thrust_sound.play ();
		isUp = -1;
		ship.velocity = ship.acceleration * deltaTime;
		ship.sprite.move (-sin (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity, cos (ship.sprite.getRotation () / 360 * 2 * pi) * ship.velocity);		
	}

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left)) {
		ship.sprite.rotate(- ship.angular_velocity * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right)) {
		ship.sprite.rotate (ship.angular_velocity * deltaTime);
	}
	
	if (!lazers.empty () && (lazers.front ().rect.getPosition ().x < 0 ||
		lazers.front ().rect.getPosition ().x > gameWidth ||
		lazers.front ().rect.getPosition ().y < 0 ||
		lazers.front ().rect.getPosition ().y > gameHeight)) {
		lazers.erase(lazers.begin());
		std::cout << "Succeed in erasing the laser!!!!!!!!!!!!!!!!!!" << std::endl;
	}

	return gameState;
}
