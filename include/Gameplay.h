#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <vector>
#include <utility>
#include <memory>
#include "../include/Ship.h"
#include "../include/Lazer.h"
#include "../include/Asteroid.h"
#include "../include/GameObject.h"

class Gameplay {
private:
	const float pi = 3.14159f;
	const int gameWidth = 800;
	const int gameHeight = 600;
public:
	const float BUCKET_WIDTH = 100;
	const float BUCKET_HEIGHT = 100;
	static const int COLUMNS = 10;
	static const int ROWS = 10;	
	std::vector<GameObject*> objects;
	std::vector<GameObject*> grid[COLUMNS][ROWS];
	Lazer lazer;
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

	enum states { INTRO, MODE1, P1LOST };
	int gameState = INTRO;
	int life = 3;
	int isUp;
	float deltaTime;
	float astTime;

	Gameplay () : window (sf::VideoMode (gameWidth, gameHeight, 32), "Asteroid") {
		
	}
	int init ();
	int selectMode (sf::RenderWindow& window);
	void update_state ();
	void renderFrame (); // Draw game objects
	void astSpawn (); // Spawn Asteroids
	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2); // Cheeck collisions for colliders
	sf::Vector2i getBucket (sf::Vector2f pos);
	void bucket_add (sf::Vector2i b, GameObject* obj);
	void bucket_remove (sf::Vector2i b, GameObject* obj);
	void detect_collisions (GameObject* obj, sf::Vector2i b);
	int count_objects (std::string type);
	void check_delete_flag ();
};