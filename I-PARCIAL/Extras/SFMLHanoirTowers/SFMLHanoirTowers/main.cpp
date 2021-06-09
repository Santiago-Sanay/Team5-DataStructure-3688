
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "App.h"

int main()
{
	Tower tower;

	int width = 1000;
	int height = 400;
	sf::RenderWindow window(sf::VideoMode(width, height), "Hanoi Towers", sf::Style::Close);
	App app{&window};
	app.create_element();
	sf::Time delta;
	sf::Time elapsed;
	sf::Clock clock;
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		elapsed += clock.getElapsedTime();
		delta = clock.getElapsedTime();
		clock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		app.app_draw(elapsed);
		window.display();
	}
	return 0;
}