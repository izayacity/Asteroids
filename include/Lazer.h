#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>

class Lazer {
public:
	sf::Sprite sprite;
	sf::Texture lazer_texture;

	Lazer () {
		sprite.setPosition (sf::Vector2f (100.f, 100.f));
		assert (lazer_texture.loadFromFile ("resources/lazer.png"));
		sprite.setTexture (lazer_texture);
		sprite.setScale (sf::Vector2f (0.05f, 0.05f)); // absolute scale factor
	}
};