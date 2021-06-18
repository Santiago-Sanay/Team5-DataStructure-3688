#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Disk.h"
#include <vector>
#include <chrono>
#include <random>
class App
{
private:
	sf::RenderWindow *window;
	Tower *_tower_a, *_tower_b, *_tower_c;
	std::vector<std::vector<Tower *>> _move_list;

public:
	App() = default;
	App(sf::RenderWindow *);
	void create_element();
	void app_draw(sf::Time &timer);
	void hanoi(int, Tower *, Tower *, Tower *);
	int random_int(int min, int max);
};
