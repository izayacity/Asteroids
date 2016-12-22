#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "GameObject.h"

class Lazer : public GameObject {
public:
	Lazer () {
		velocity = 9.f;
		delete_flag = 0;
		sprite.setOrigin (1.f, 5.f);
		sprite.setRadius (5.f);
		sprite.setFillColor (sf::Color::Green);
	}

	virtual void update () {
		sprite.move (sin (sprite.getRotation () / 360 * 2 * pi) * velocity, -cos (sprite.getRotation () / 360 * 2 * pi) * velocity);
	}

	virtual void draw (sf::RenderWindow &window) {
		window.draw (sprite);
	}

	virtual int checkCollisionWith (GameObject* obj) {
		return 0;
	}

	virtual sf::Vector2f getCenter () {
		return sprite.getPosition ();
	}

	virtual float getRotation () {
		return sprite.getRotation ();
	}

	virtual void setRotation (float new_rotation) {
		sprite.setRotation (new_rotation);
	}

	virtual int getRenderBucket () {
		return 2;
	}

	virtual std::string getTag () {
		return "lazer";
	}
};