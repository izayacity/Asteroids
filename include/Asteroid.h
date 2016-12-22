#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <assert.h>
#include <iostream>
#include "GameObject.h"

class Asteroid : public GameObject {
public:
	Asteroid () {
		velocity = 5.f;
		delete_flag = 0;
	}
	
	void small (sf::Texture astTexture) {
		type = 0;
		sprite.setRadius (20.f);
		//sprite.setTexture (&astTexture);
		sprite.setOrigin (20.f, 20.f);
		//sprite.setScale (sf::Vector2f (0.15f, 0.15f)); // absolute scale factor
		sprite.setFillColor (sf::Color::Yellow);
	}

	void medium (sf::Texture astTexture) {
		type = 1;
		sprite.setRadius (35.f);
		//sprite.setTexture (&astTexture);
		sprite.setOrigin (35.f, 35.f);
		//sprite.setScale (sf::Vector2f (0.25f, 0.25f)); // absolute scale factor
		sprite.setFillColor (sf::Color::Yellow);
	}

	void large (sf::Texture astTexture) {
		type = 2;
		sprite.setRadius (50.f);
		//sprite.setTexture (&astTexture);
		sprite.setOrigin (50.f, 50.f);
		//sprite.setScale (sf::Vector2f (0.4f, 0.4f)); // absolute scale factor
		sprite.setFillColor (sf::Color::Yellow);
	}

	virtual void update () {
		sprite.move (sin (sprite.getRotation () / 360 * 2 * pi) * velocity, -cos (sprite.getRotation () / 360 * 2 * pi) * velocity);
	}

	virtual void draw (sf::RenderWindow &window) {
		window.draw (sprite);
	}

	virtual int checkCollisionWith (GameObject* o2) {	
		sf::Vector2f Distance = getCenter () - o2->getCenter ();

		if (Distance.x * Distance.x + Distance.y * Distance.y <=
			(sprite.getRadius () + o2->sprite.getRadius ()) * (sprite.getRadius () + o2->sprite.getRadius ())) {
			std::string o2_type = o2->getTag ();

			if (o2_type.compare ("asteroid") == 0) {				
				// bounce off
				float rotation1 = (getRotation () > 180.f) ? getRotation () - 180.f : getRotation () + 180.f;
				//float rotation2 = (o2->getRotation () > 180.f) ? o2->getRotation () - 180.f : o2->getRotation () + 180.f;
				setRotation (rotation1);
				//o2->setRotation (rotation2);
			} else if (o2_type.compare ("ship") == 0) {
				delete_flag = 1;
				std::cout << "Ship is hit!" << std::endl;
				return -1;
			} else if (o2_type.compare ("lazer") == 0) {
				std::cout << "Lazer hit the asteroid!" << std::endl;
				// small asteroid
				if (type == 0) {
					delete_flag = 1;
					o2->delete_flag = 1;
				} else if (type == 1) {
					// medium asteroid, delete_flag 2 add two small asteroids to the vector
					delete_flag = 2;
					o2->delete_flag = 1;
				} else if (type == 2) {
					// large asteroid, delete_flag 3 add two medium asteroids to the vector
					delete_flag = 3;
					o2->delete_flag = 1;
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
};