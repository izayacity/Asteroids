#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <vector>
#include "../include/Ship.h"
#include "../include/Lazer.h"
#include "../include/Asteroid.h"

class Gameplay {
private:
	const float pi = 3.14159f;
	const int gameWidth = 800;
	const int gameHeight = 600;

public:
	Lazer lazer;
	std::vector<Lazer> lazers;
	std::vector<Asteroid> asteroids;
	Ship ship;
	
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
	sf::Texture largeTexture;
	sf::Texture mediumTexture;
	sf::Texture smallTexture;
	
	// Define the paddles properties
	const sf::Time AITime = sf::seconds (0.1f);
	sf::Clock clock;
	sf::Event event;
	sf::Clock shotClock;
	sf::Clock astClock;

	enum states { INTRO, MODE1, MODE2, RESUME1, RESUME2, P1WIN, P1LOST };
	int gameState = INTRO;
	int life = 3;
	int isUp;
	float deltaTime;
	float astTime;

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
	void astSpawn (); // Spawn Asteroids
	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2);
};