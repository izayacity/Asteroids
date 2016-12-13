#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>
#include "Lazer.h"

class Ship {
public:
	const float pi = 3.14159f;
	float acceleration;
	float velocity;
	float angular_velocity;
	sf::Texture shipTexture1;
	sf::Sprite sprite;
	sf::CircleShape collider;
	
	Ship::Ship () : acceleration(125.f), angular_velocity(150.f) {
		sprite.setPosition (sf::Vector2f (400.f, 300.f));
		assert (shipTexture1.loadFromFile ("resources/ship1.png"));
		sprite.setTexture (shipTexture1);
		sprite.setScale (sf::Vector2f (0.05f, 0.05f)); // absolute scale factor
		sprite.setOrigin (sprite.getTexture ()->getSize ().x * 1.f / 2, 0.f);
	}

	Ship::~Ship () {
	}
};
