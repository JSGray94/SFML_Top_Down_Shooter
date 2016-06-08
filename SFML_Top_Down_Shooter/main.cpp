/*
This is a game application that serves the purpose of a tutorial. The end product
will result in a type of top-down shooter game.
*/

#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFLM TOP DOWN SHOOTER");
	sf::CircleShape shape;
	shape.setRadius(40.0f);
	shape.setFillColor(sf::Color::Cyan);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}