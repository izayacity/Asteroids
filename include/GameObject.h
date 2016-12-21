#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class GameObject {
public:	
	int delete_flag = 0;
	virtual void update () = 0;
	virtual void draw (sf::RenderWindow &window) = 0;
	virtual sf::Vector2f getCenter () = 0;
	virtual float getRotation () = 0;
	virtual void setRotation (float new_rotation) = 0;
	virtual int getRenderBucket () = 0;
	virtual int checkCollisionWith (GameObject* obj) = 0;
	virtual std::string getTag () = 0;
	virtual float getRadius () = 0;
};