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
		delete_flag = 0;
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

	virtual int checkCollisionWith (GameObject* obj) {
		return 0;
	}

	virtual sf::Vector2f getCenter () {
		return rect.getPosition ();
	}

	virtual float getRotation () {
		return rect.getRotation ();
	}

	virtual void setRotation (float new_rotation) {
		rect.setRotation (new_rotation);
	}

	virtual int getRenderBucket () {
		return 2;
	}

	virtual std::string getTag () {
		return "lazer";
	}

	virtual float getRadius () {
		return collider.getRadius ();
	}
};