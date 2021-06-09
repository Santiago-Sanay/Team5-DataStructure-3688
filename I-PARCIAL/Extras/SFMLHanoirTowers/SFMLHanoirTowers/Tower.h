#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Disk.h"
class Tower
{
private:
	std::vector<Disk*> _disks;
	sf::RectangleShape _base;
	sf::RectangleShape _tower;
	sf::Vector2f _position = sf::Vector2f(0, 0);

public:
	Tower();
	void draw_structure(sf::RenderWindow*);
	void add_disk(Disk*);
	void set_position(sf::Vector2f);
	Disk* get_disk();
	sf::Vector2f get_size();
};
