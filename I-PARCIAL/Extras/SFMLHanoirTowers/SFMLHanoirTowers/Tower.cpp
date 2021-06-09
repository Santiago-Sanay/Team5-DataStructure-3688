#include "Tower.h"
#include <iostream>
Tower::Tower()
{
	_base.setSize(sf::Vector2f(300, 10));
	_tower.setSize(sf::Vector2f(10, 220));

}
void Tower::draw_structure(sf::RenderWindow* _window)
{
	sf::Vector2f _base_position(_position.x, _tower.getSize().y + _position.y);
	sf::Vector2f _tower_position((_position.x + _base.getSize().x / 2) - _tower.getSize().x, _position.y);
	_base.setPosition(_base_position);
	_tower.setPosition(_tower_position);
	_window->draw(_base);
	_window->draw(_tower);

	int i = 0;
	for (auto _disk : _disks)
	{
		_disk->set_position(
			sf::Vector2f(
				_tower.getPosition().x - (_disk->get_size().x / 2) + (_tower.getSize().x / 2),
				_base.getPosition().y - _disk->get_size().y - (_disk->get_size().y + 2) * i));
		_disk->draw_disk(_window);
		++i;
	}
}


void Tower::add_disk(Disk* disk)
{
	_disks.push_back(disk);
}

void Tower::set_position(sf::Vector2f _new_position)
{
	this->_position = _new_position;
}

Disk* Tower::get_disk()
{
	Disk* disk = _disks.at(_disks.size() - 1);
	_disks.pop_back();
	return disk;
}

sf::Vector2f Tower::get_size()
{
	return sf::Vector2f(_base.getSize().x, _base.getSize().x + _tower.getSize().x);
}


