#pragma once
#include <string>
class Calendario
{
private:
	
	std::string fecha[100];
public:
	Calendario(std::string [100]);
	
	void set_fecha(std::string [100]);
	std::string* get_fecha();


};

