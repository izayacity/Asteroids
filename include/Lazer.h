#pragma once
#include <SFML/Graphics.hpp>

class Lazer {
public:
	sf::RectangleShape rect;
	sf::Texture lazer_texture;
	sf::CircleShape collider;
	sf::Vector2f origin;
	float velocity;

	Lazer () : velocity (9.f) {
		rect.setFillColor (sf::Color::Green);
		rect.setSize (sf::Vector2f(2.f, 10.f));
		origin = rect.getOrigin ();
		collider.setOrigin (origin);
		collider.setRadius (5.f);
	}
};