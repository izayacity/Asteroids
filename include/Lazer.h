#pragma once
#include <SFML/Graphics.hpp>
#include <assert.h>

class Lazer {
public:
	sf::RectangleShape rect;
	sf::Texture lazer_texture;
	float velocity;

	Lazer () : velocity (9.f) {
		rect.setFillColor (sf::Color::Green);
		rect.setSize (sf::Vector2f(2.f, 10.f));
	}
};