#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Lazer : GameObject {
public:
	sf::RectangleShape rect;
	sf::Texture lazer_texture;
	sf::CircleShape collider;
	sf::Vector2f origin;
	float velocity;

	Lazer () : velocity (9.f) {
		rect.setFillColor (sf::Color::Green);
		rect.setSize (sf::Vector2f(2.f, 10.f));
		origin = rect.getOrigin ();
		collider.setOrigin (origin);
		collider.setRadius (5.f);
	}

	virtual void update (float dt) {

	}

	virtual void draw () {

	}

	virtual void checkCollisionWith (GameObject * obj) {

	}

	virtual sf::Vector2f getCenter () {
		return origin;
	}

	virtual int getRenderBucket () {
		return 2;
	}

	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2) {
		sf::Vector2f Distance = Object1.getOrigin () - Object2.getOrigin ();
		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Object1.getRadius () + Object2.getRadius ()) * (Object1.getRadius () + Object2.getRadius ()));
	}
};