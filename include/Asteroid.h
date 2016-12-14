#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>

class Asteroid {
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
};