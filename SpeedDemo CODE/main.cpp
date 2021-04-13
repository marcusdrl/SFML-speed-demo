#include "FloatingPoints.h"
#include <iostream>
#include <vector>
int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SPEED DEMO", sf::Style::Close);

	sf::Font font;
	if (!font.loadFromFile("Roboto-BoldItalic.ttf"))
	{
		std::cerr << "Nao foi possivel encontrar o arquivo Roboto-BoldItalic.ttf" << std::endl;
	}

	sf::Text texto1;
	texto1.setFont(font);
	texto1.setString("Speed = 100 pixels/second");
	texto1.setCharacterSize(13);
	texto1.setPosition(sf::Vector2f(10.0f, 10.0f));

	sf::Text texto2;
	texto2.setFont(font);
	texto2.setString("Speed = 80 pixels/second");
	texto2.setCharacterSize(13);
	texto2.setPosition(sf::Vector2f(10.0f, 138.0f));

	sf::Text texto3;
	texto3.setFont(font);
	texto3.setString("Speed = 50 pixels/second");
	texto3.setCharacterSize(13);
	texto3.setPosition(sf::Vector2f(10.0f, 266.0f));

	sf::Text texto4;
	texto4.setFont(font);
	texto4.setString("Speed = 15 pixels/second");
	texto4.setCharacterSize(13);
	texto4.setPosition(sf::Vector2f(10.0f, 394.0f));

	sf::Vertex line1[] = {sf::Vertex(sf::Vector2f(0.0f, 128.0f)), sf::Vertex(sf::Vector2f(static_cast<float>(window.getSize().x), 128.0f))};
	sf::Vertex line2[] = {sf::Vertex(sf::Vector2f(0.0f, 256.0f)), sf::Vertex(sf::Vector2f(static_cast<float>(window.getSize().x), 256.0f))};
	sf::Vertex line3[] = {sf::Vertex(sf::Vector2f(0.0f, 384.0f)), sf::Vertex(sf::Vector2f(static_cast<float>(window.getSize().x), 384.0f))};

	std::vector<FloatingPoints> circles;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evt;

		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{	
			FloatingPoints newFloatingPoint;
			newFloatingPoint.setPosition(window);
			circles.emplace_back(newFloatingPoint);
		}

		for (auto &circle : circles) {
			circle.updateSpeed(deltaTime, window);
		}

		window.clear();

		for (auto &circle : circles) 
			circle.draw(window);

		window.draw(line1, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(line3, 2, sf::Lines);

		window.draw(texto1);
		window.draw(texto2);
		window.draw(texto3);
		window.draw(texto4);

		window.display();

	}

	return 0;
}