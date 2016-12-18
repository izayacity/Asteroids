#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <assert.h>
#include "Lazer.h"
#include "GameObject.h"

class Ship : public GameObject {
public:
	const float pi = 3.14159f;
	float acceleration;
	float velocity;
	float angular_velocity;
	sf::Texture shipTexture1;
	sf::Sprite sprite;
	sf::CircleShape collider;
	sf::Vector2f origin;
	
	Ship::Ship () : acceleration(125.f), angular_velocity(150.f) {
		sprite.setPosition (sf::Vector2f (400.f, 300.f));
		assert (shipTexture1.loadFromFile ("resources/ship1.png"));
		sprite.setTexture (shipTexture1);
		sprite.setScale (sf::Vector2f (0.05f, 0.05f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, 0.f);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
	}

	Ship::~Ship () {
	}

	virtual void update () {
		sprite.move (sin (sprite.getRotation () / 360 * 2 * pi) * velocity, -cos (sprite.getRotation () / 360 * 2 * pi) * velocity);
	}

	virtual void draw (sf::RenderWindow &window) {
		window.draw (sprite);
	}

	virtual void checkCollisionWith (std::shared_ptr<GameObject> obj) {
		
	}

	virtual sf::Vector2f getCenter () {
		return sprite.getPosition();
	}

	virtual int getRenderBucket () {
		return 1;
	}

	virtual std::string getTag () {
		return "ship";
	}

	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2) {
		sf::Vector2f Distance = Object1.getOrigin () - Object2.getOrigin ();
		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Object1.getRadius () + Object2.getRadius ()) * (Object1.getRadius () + Object2.getRadius ()));
	}
};
