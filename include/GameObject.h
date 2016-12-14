#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	virtual void update (float dt) = 0;
	virtual void draw () = 0;
	virtual sf::Vector2f getCenter () = 0;
	virtual int getRenderBucket () = 0;
	virtual void checkCollisionWith (GameObject * obj) = 0;
};