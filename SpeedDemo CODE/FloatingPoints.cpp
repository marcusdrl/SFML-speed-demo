#include "FloatingPoints.h"

FloatingPoints::FloatingPoints()
{
	body.setRadius(1.0f);
	body.setFillColor(sf::Color::Red);
}

FloatingPoints::~FloatingPoints()
{
}

void FloatingPoints::updateSpeed(float deltaTime, sf::RenderWindow &window)
{
	velocity.x = speed;
	velocity.y = 0.0f;

	//adicionar velocidade de acordo com a posicao na tela
	if (body.getPosition().y >= static_cast<float>(window.getSize().y / 4)
		&& body.getPosition().y <= static_cast<float>(window.getSize().y / 2))
	{
		speed = 80.0f;
		velocity.x = speed;
	}
	else if (body.getPosition().y >= static_cast<float>(window.getSize().y / 2)
		&& body.getPosition().y <= static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y / 4))
	{
		speed = 50.0f;
		velocity.x = speed;
	}
	else if (body.getPosition().y >= static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y / 4)
		&& body.getPosition().y <= static_cast<float>(window.getSize().y) + 10.f)
	{
		speed = 15.0f;
		velocity.x = speed;
	}

	//Movendo particula pela tela
	body.move(velocity * deltaTime);
}

void FloatingPoints::draw(sf::RenderWindow &window)
{
	window.draw(body);
}

void FloatingPoints::setPosition(sf::RenderWindow &window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

	body.setPosition(worldPos);
}

