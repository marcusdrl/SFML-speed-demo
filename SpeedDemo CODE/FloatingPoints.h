#pragma once
#include "Point.h"

class FloatingPoints
{
private:
	sf::CircleShape body;
	Point points;
	float speed = 100.0f;
	sf::Vector2f velocity;

public:
	FloatingPoints();
	~FloatingPoints();

	void updateSpeed(float deltaTime, sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setPosition(sf::RenderWindow &window);
};

