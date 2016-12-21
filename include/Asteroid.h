#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <assert.h>
#include <iostream>
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
		delete_flag = 0;
	}
	
	void small (sf::Texture *astTexture) {
		type = 0;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.15f, 0.15f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		//collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 0.15f + sprite.getTexture ()->getSize ().y * 0.15f) / 2);
	}

	void medium (sf::Texture *astTexture) {
		type = 1;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.25f, 0.25f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		//collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 0.25f + sprite.getTexture ()->getSize ().y * 0.25f) / 2);
	}

	void large (sf::Texture *astTexture) {
		type = 2;
		sprite.setTexture (*astTexture);
		sprite.setScale (sf::Vector2f (0.4f, 0.4f)); // absolute scale factor
		origin = sf::Vector2f (sprite.getTexture ()->getSize ().x * 1.f / 2, sprite.getTexture ()->getSize ().y * 1.f / 2);
		sprite.setOrigin (origin);
		collider.setOrigin (origin);
		//collider.setRadius ((sprite.getTexture ()->getSize ().x * 1.f + sprite.getTexture ()->getSize ().y * 1.f) / 2);
		collider.setRadius ((sprite.getTexture ()->getSize ().x * 0.4f + sprite.getTexture ()->getSize ().y * 0.4f) / 2);
	}

	virtual void update () {
		sprite.move (sin (sprite.getRotation () / 360 * 2 * pi) * velocity, -cos (sprite.getRotation () / 360 * 2 * pi) * velocity);
	}

	virtual void draw (sf::RenderWindow &window) {
		window.draw (sprite);
	}

	virtual int checkCollisionWith (GameObject* o2) {	
		sf::Vector2f Distance = getCenter () - o2->getCenter ();

		if (Distance.x * Distance.x + Distance.y * Distance.y <= (getRadius () + o2->getRadius ()) * (getRadius () + o2->getRadius ())) {
			delete_flag = 1;
			std::string o2_type = o2->getTag ();

			if (o2_type.compare ("asteroid") == 0) {				
				//std::cout << "Collision between asteroids detected" << std::endl;
				// bound off
				float rotation1 = (sprite.getRotation () > 180.f) ? sprite.getRotation () - 180.f : sprite.getRotation () + 180.f;
				float rotation2 = (o2->getRotation () > 180.f) ? o2->getRotation () - 180.f : o2->getRotation () + 180.f;
				//std::cout << rotation1 << ", " << rotation2 << std::endl;

				sprite.setRotation (rotation1);
				o2->setRotation (rotation2);
			} else if (o2_type.compare ("ship") == 0) {
				std::cout << "Ship is hit!" << std::endl;
				return -1;
			} else if (o2_type.compare ("lazer") == 0) {
				std::cout << "Lazer hit the asteroid!" << std::endl;
				// small asteroid
				if (type == 0) {
					delete_flag = 1;
				} else if (type == 1) {
					// medium asteroid, delete_flag 2 add two small asteroids to the vector
					delete_flag = 2;					
				} else if (type == 2) {
					// large asteroid, delete_flag 3 add two medium asteroids to the vector
					delete_flag = 3;
				}
			}
		}
		return 0;
	}

	virtual float getRotation () {
		return sprite.getRotation ();
	}

	virtual sf::Vector2f getCenter () {
		return sprite.getPosition ();
	}

	virtual void setRotation (float new_rotation) {
		sprite.setRotation (new_rotation);
	}

	virtual int getRenderBucket () {
		return 0;
	}

	virtual std::string getTag () {
		return "asteroid";
	}

	virtual float getRadius () {
		return collider.getRadius ();
	}
};