#include "Disk.h"
Disk::Disk(sf::Vector2f size)
{
	_disk.setSize(size);
}

void Disk::draw_disk(sf::RenderWindow *_window)
{
	_window->draw(_disk);
}

void Disk::set_color(sf::Color __new_color)
{
	_disk.setFillColor(__new_color);
}

void Disk::set_position(sf::Vector2f _new_position)
{
	this->_position = _new_position;
	_disk.setPosition(_new_position);
}

sf::Vector2f Disk::get_position()
{
	return this->_position;
}
sf::Vector2f Disk::get_size()
{
	return _disk.getSize();
}