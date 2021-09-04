/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/
#include "File.h"
#include <iomanip>

void File::delete_account()
{
}

void File::add(LinkedList<Person> &list)
{
	 std::ofstream keys("keys.txt");
	 int j = 0;
	 while (j < list.get_size())
	 {
		 keys << list.at(j)->get_data().get_id() << "," << "\n";
		 ++j;
	 }
	 keys.close();

	 json file_json;
	 for (int i = 0; i < list.get_size(); ++i)
	 {
			to_json_objet(file_json,list.at(i)->get_data());
	 } 
	 std::ofstream file("persons.json");
	 file << std::setw(4) << file_json << std::endl;
}

void File::add(LinkedList<Doubt>& doubt)
{
	std::ofstream keys("keys.txt");
	int j = 0;
	while (j < doubt.get_size())
	{
		keys << doubt.at(j)->get_data().get_id_person() << "," << "\n";
		++j;
	}
	keys.close();

	json file_json;
	for (int i = 0; i < doubt.get_size(); ++i)
	{
		to_json_objet(file_json, doubt.at(i)->get_data());
	}
	std::ofstream file("credits.json");
	file << std::setw(4) << file_json << std::endl;
}

void File::update()
{
}

bool File::search(std::string &id)
{
	std::ifstream file("persons.json");
	json file_json;
	try
	{
		file >> file_json;	
		if (id == file_json[id]["id"].get<std::string>())
		{
			std::cout << "\nUsuario Existente." << std::endl;
			std::cin.clear(); 
			return true;
		}
	}
	catch (json::exception& e)
	{
		return false;
	}

	return false;
}

bool File::search_credits(std::string& id)
{
	std::ifstream file("credits.json");
	json file_json;
	try
	{
		file >> file_json;
		if (id == file_json[id]["id"].get<std::string>())
		{
			std::cout << "\nEl usuario ya tiene un credito registrado." << std::endl;
			std::cin.clear();
			return true;
		}
	}
	catch (json::exception &e)
	{
		return false;
	}

	return false;
}

Doubt File::at(std::string key)
{
	std::ifstream file("credits.json");
	json file_json;
	Doubt doubt;
	file >> file_json;
	if (key == file_json[key]["id"].get<std::string>())
	{
		to_object_json(file_json, doubt, key);
	}
	return doubt;
}

Person File::at_person(std::string key)
{
	std::ifstream file("persons.json");
	json file_json;
	Person person;
	file >> file_json;
	if (key == file_json[key]["id"].get<std::string>())
	{
		to_object_json(file_json, person, key);
	}
	return person;
}

LinkedList<Person> File::read()
{
	std::vector<std::string> keys_vector;
	LinkedList<Person> list;
	std::ifstream keys("keys.txt");
	std::string str;
	std::string str2;
	int count_key{0};
	while (getline(keys,str))
	{
		std::istringstream ss(str);
		while (getline(ss, str2, ','))
		{
			keys_vector.push_back(str2);
		}
		++count_key;
	}

	try
	{
		std::ifstream file("persons.json");
		json file_json;
		file >> file_json;
		Person person;
		Doubt doubt;
		for (int i = 0; i < count_key; ++i)
		{
			std::string key = keys_vector[i];
			to_object_json(file_json, person, key);
			list.add(person);
		}
	}
	catch (json::exception e)
	{
		return list;
	}
	return list;
}

LinkedList<Doubt> File::read(std::string js)
{
	std::vector<std::string> keys_vector;
	LinkedList<Doubt> list;
	std::ifstream keys("keys.txt");
	std::string str;
	std::string str2;
	int count_key{ 0 };
	std::ifstream file(js);
	json file_json;
	
		while (getline(keys, str))
		{
			std::istringstream ss(str);
			while (getline(ss, str2, ','))
			{
				keys_vector.push_back(str2);
			}
			++count_key;
		}

	try
	{
		file >> file_json;
		Doubt doubt;
		for (int i = 0; i < count_key; ++i)
		{
			std::string key = keys_vector[i];
			if (key == file_json[key]["id"].get<std::string>())
			{
				to_object_json(file_json, doubt, key);
				list.add(doubt);
			}
		}
	}
	catch (json::exception e)
	{
		return list;
	}
	return list;
}

void File::to_json_objet(json& j, Person value)
{
	std::string key = value.get_id();
	j[key]["id"] = value.get_id();
	j[key]["name"] = value.get_name();
	j[key]["last_name"] = value.get_last_name();
	j[key]["date_of_birth"] = value.get_date_of_birth();
	j[key]["age"] = value.get_age();
	j[key]["email"] = value.get_email();
	j[key]["phone"] = value.get_number();
	j[key]["addres"] = value.get_addres();
}

void File::to_json_objet(json& j, Doubt value)
{
	std::string key = value.get_id_person();
	j[key]["id"] = value.get_id_person();
	j[key]["initial_amount"] = value.get_initial_amount();
	j[key]["final_amount"] = value.get_final_amount();
	j[key]["initial_date"] = value.get_initial_date();
	j[key]["interest"] = value.get_interest();
	j[key]["payment_time"] = value.get_payment_time();
	j[key]["rate_of_interest"] = value.get_rate_of_interest();
}

void File::to_object_json(json& j, Person& value, std::string key)
{
	value.set_id(j[key]["id"].get<std::string>());
	value.set_name(j[key]["name"].get<std::string>());
	value.set_last_name(j[key]["last_name"].get<std::string>());
	value.set_date_of_birth(j[key]["date_of_birth"].get<std::string>());
	value.set_email(j[key]["email"].get<std::string>());
	value.set_number(j[key]["phone"].get<std::string>());
	value.set_addres(j[key]["addres"].get<std::string>());
	value.set_age(j[key]["age"].get<int>());
}

void File::to_object_json(json& j, Doubt& value, std::string key)
{
	value.set_id_person(j[key]["id"].get<std::string>());
	value.set_initial_date(j[key]["initial_date"].get<std::string>());
	value.set_rate_of_interest(j[key]["rate_of_interest"].get<std::string>());
	value.set_payment_time(j[key]["payment_time"].get<int>());
	value.set_initial_amount(j[key]["initial_amount"].get<double>());
	value.set_final_amount(j[key]["final_amount"].get<double>());
	value.set_interest(j[key]["interest"].get<double>());
}