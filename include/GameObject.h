#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class GameObject {
public:
	virtual void update () = 0;
	virtual void draw (sf::RenderWindow &window) = 0;
	virtual sf::Vector2f getCenter () = 0;
	virtual int getRenderBucket () = 0;
	virtual void checkCollisionWith (std::shared_ptr<GameObject> obj) = 0;
	virtual std::string getTag () = 0;
};