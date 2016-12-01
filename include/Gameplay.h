#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <vector>
#include "../include/Ship.h"
#include "../include/Lazer.h"

class Gameplay {
private:
	const float pi = 3.14159f;
	const int gameWidth = 800;
	const int gameHeight = 600;

public:
	sf::Font fontHNMed;
	sf::Font fontHNM;
	sf::Font fontHNL;
	sf::Text pauseMessage;
	sf::Clock AITimer;
	sf::Text score;
	sf::Text lifeText;
	sf::Texture bgTex;    //background texture
	sf::RectangleShape shape;    //background shape
	sf::RenderWindow window;
	sf::SoundBuffer thrust_sound_buffer;
	sf::Sound thrust_sound;	

	// Define the paddles properties
	const sf::Time AITime = sf::seconds (0.1f);
	sf::Clock clock;
	sf::Event event;

	enum states { INTRO, MODE1, MODE2, RESUME1, RESUME2, P1WIN, P1LOST };
	int gameState = INTRO;
	int life = 3;
	float deltaTime;
	int isUp;

	Ship ship;
	Lazer lazer;

	Gameplay () : window (sf::VideoMode (gameWidth, gameHeight, 32), "Asteroid") {

	}
	int init ();
	void restart ();
	void updateScore ();
	void updateLife ();
	int selectMode (sf::RenderWindow& window);
	int gameMode1 ();
	void gameMode2 ();
	void level1 ();
	void level2 ();
	void renderFrame (); // Draw game objects
	int isWin ();
};