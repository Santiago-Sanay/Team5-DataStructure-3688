#include <iostream>
#include "Math.h"
#include "Vector.h"

int main()
{

	Vector* v = new Vector[]{ {7,4,5 }, { 6,7,8 } };
	Math m;
	Vector v3 = m.operator+(v);
	std::cout << "(" << v3.get_x() << ", " << v3.get_y() << ", " << v3.get_z() << ")" << std::endl;
	std::cout << "(" << m.operator++(v[0].get_x()) << ", " << m.operator++(v[0].get_y()) << ", " << m.operator++(v[0].get_z()) << ")";

	return EXIT_SUCCESS;
}