#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>

class Ship {
public:
	float acceleration;
	float velocity;
	float angular_velocity;
	sf::Texture shipTexture1;
	sf::Sprite sprite;

	Ship::Ship () : acceleration(125.f), angular_velocity(150.f) {
		sprite.setPosition (sf::Vector2f (400.f, 300.f));
		assert (shipTexture1.loadFromFile ("resources/ship1.png"));
		sprite.setTexture (shipTexture1);
		sprite.setScale (sf::Vector2f (0.05f, 0.05f)); // absolute scale factor
	}

	Ship::~Ship () {
	}
};
