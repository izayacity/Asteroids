#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "GameObject.h"

class Lazer : public GameObject {
public:
	sf::RectangleShape rect;
	sf::Texture lazer_texture;
	sf::CircleShape collider;
	sf::Vector2f origin;
	float velocity;
	const float pi = 3.14159f;

	Lazer () : velocity (9.f) {
		rect.setFillColor (sf::Color::Green);
		rect.setSize (sf::Vector2f(2.f, 10.f));
		origin = rect.getOrigin ();
		collider.setOrigin (origin);
		collider.setRadius (5.f);
	}

	virtual void update () {
		rect.move (sin (rect.getRotation () / 360 * 2 * pi) * velocity, -cos (rect.getRotation () / 360 * 2 * pi) * velocity);
	}

	virtual void draw (sf::RenderWindow &window) {
		window.draw (rect);
	}

	virtual void checkCollisionWith (std::shared_ptr<GameObject> obj) {

	}

	virtual sf::Vector2f getCenter () {
		return rect.getPosition ();
	}

	virtual int getRenderBucket () {
		return 2;
	}

	virtual std::string getTag () {
		return "lazer";
	}

	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2) {
		sf::Vector2f Distance = Object1.getOrigin () - Object2.getOrigin ();
		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Object1.getRadius () + Object2.getRadius ()) * (Object1.getRadius () + Object2.getRadius ()));
	}
};