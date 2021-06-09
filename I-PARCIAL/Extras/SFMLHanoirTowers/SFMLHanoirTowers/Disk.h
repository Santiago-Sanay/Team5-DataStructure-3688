#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Disk
{
private:
	sf::RectangleShape _disk;
	sf::Vector2f _position = sf::Vector2f(0, 0);
	sf::Color _color;
	sf::Vector2f _size;

public:
	Disk(sf::Vector2f);
	void draw_disk(sf::RenderWindow*);
	void set_color(sf::Color);
	void set_position(sf::Vector2f);
	sf::Vector2f get_position();
	sf::Vector2f get_size();
};
