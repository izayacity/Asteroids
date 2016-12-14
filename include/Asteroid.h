#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>
#include "GameObject.h"

class Asteroid : GameObject {
public:	
	sf::Sprite sprite;
	sf::CircleShape collider;
	sf::Vector2f origin;

	float velocity;
	int type;

	Asteroid () : velocity (2.f) {
	
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
		return 0;
	}

	bool CircleTest (sf::CircleShape Object1, sf::CircleShape Object2) {
		sf::Vector2f Distance = Object1.getOrigin () - Object2.getOrigin ();
		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Object1.getRadius () + Object2.getRadius ()) * (Object1.getRadius () + Object2.getRadius ()));
	}
};