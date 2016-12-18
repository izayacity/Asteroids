#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <assert.h>
#include "GameObject.h"

class Asteroid : public GameObject {
public:	
	sf::Sprite sprite;
	sf::CircleShape collider;
	sf::Vector2f origin;
	float velocity;
	int type;
	const float pi = 3.14159f;

	Asteroid () : velocity (2.25f) {
	
	}
	
	void small (sf::Texture *astTexture) {
		type = 0;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.15f, 0.15f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
	}

	void medium (sf::Texture *astTexture) {
		type = 1;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.25f, 0.25f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
	}

	void large (sf::Texture *astTexture) {
		type = 2;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.4f, 0.4f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
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
		return sprite.getPosition ();
	}

	virtual int getRenderBucket () {
		return 0;
	}

	virtual std::string getTag () {
		return "asteroid";
	}

	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2) {
		sf::Vector2f Distance = Object1.getOrigin () - Object2.getOrigin ();
		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Object1.getRadius () + Object2.getRadius ()) * (Object1.getRadius () + Object2.getRadius ()));
	}
};