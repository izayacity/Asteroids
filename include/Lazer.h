#pragma once
#include <SFML/Graphics.hpp>

class Lazer {
public:
	sf::RectangleShape rect;
	sf::Texture lazer_texture;
	sf::CircleShape collider;
	float velocity;

	Lazer () : velocity (9.f) {
		rect.setFillColor (sf::Color::Green);
		rect.setSize (sf::Vector2f(2.f, 10.f));
		/*collider.setOrigin (rect.getOrigin ());
		collider.setRadius ((rect.getTexture ()->getSize ().x * 1.f + rect.getTexture ()->getSize ().y * 1.f) / 2);*/
	}
};