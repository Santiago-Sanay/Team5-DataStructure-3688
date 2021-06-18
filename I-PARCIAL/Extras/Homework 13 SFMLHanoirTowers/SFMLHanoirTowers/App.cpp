#include "App.h"
App::App(sf::RenderWindow* _new_window)
{
	this->window = _new_window;
	this->_tower_a = new Tower;
	this->_tower_b = new Tower;
	this->_tower_c = new Tower;
}
void App::create_element()
{
	sf::Vector2f size = _tower_a->get_size();
	_tower_a->set_position(sf::Vector2f(25, 90));
	_tower_b->set_position(sf::Vector2f(25 * 2 + size.x, 90));
	_tower_c->set_position(sf::Vector2f((25 * 3) + (size.x * 2), 90));

	int total_disks = 7;
	for (int i = total_disks; i >= 1; i--)
	{

		int _width = (280 / total_disks) * i;
		int _height = (200 / total_disks);
		if (_height > 30)
		{
			_height = 30;
		}
		Disk* disk = new Disk(sf::Vector2f(_width, _height));
		disk->set_color(sf::Color(random_int(0, 255), random_int(0, 255), random_int(0, 255)));
		_tower_a->add_disk(disk);
	}

	hanoi(total_disks, _tower_a, _tower_c, _tower_b);
}

void App::app_draw(sf::Time& timer)
{
	_tower_a->draw_structure(window);
	_tower_b->draw_structure(window);
	_tower_c->draw_structure(window);

	if (!_move_list.empty() && timer.asMilliseconds() > 500)
	{
		auto movement = _move_list.at(0);
		_move_list.erase(_move_list.begin());
		Tower* tower_1 = movement.at(0);
		Tower* tower_2 = movement.at(1);
		Disk* disk = tower_1->get_disk();
		tower_2->add_disk(disk);
		timer = sf::milliseconds(0);
	}
}

void App::hanoi(int n, Tower* _tower_a, Tower* _tower_c, Tower* _tower_b)
{
	if (n == 1)
	{
		std::cout << "Move disk 1 from rod "
			<< "A"
			<< " to rod "
			<< "C" << std::endl;
		_move_list.push_back({ _tower_a, _tower_c });
	}
	else
	{
		hanoi(n - 1, _tower_a, _tower_b, _tower_c);
		std::cout << "Move disk " << n << " from rod "
			<< "A"
			<< " to rod "
			<< "C" << std::endl;
		_move_list.push_back({ _tower_a, _tower_c });
		hanoi(n - 1, _tower_b, _tower_c, _tower_a);
	}
}

int App::random_int(int min, int max)
{
	std::random_device rd;
	std::uniform_int_distribution<> dist(min, max);
	static std::mt19937_64 random_generator(
		std::chrono::system_clock::now().time_since_epoch().count());

	return dist(random_generator);
}
