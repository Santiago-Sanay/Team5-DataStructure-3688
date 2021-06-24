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
	 std::cout << std::setw(4) << file_json<< std::endl << std::endl;
}

void File::update()
{
}

bool File::search(Person &person)
{
	std::ifstream file("persons.json");
	json file_json;
	file >> file_json;
	std::string key = person.get_id();
	if (person.get_id() == file_json[key]["id"].get<std::string>())
	{
		std::cout << "El usuario ingresado ya existe" << std::endl;
		return true;
	}
	return false;
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

	std::ifstream file("persons.json");
	json file_json;
	file >> file_json;
	Person person;
	for (int i = 0; i < count_key; ++i)
	{
		std::string key = keys_vector[i];
		to_object_json(file_json, person, key);
		list.add(person);
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
	j[key]["email"] = value.get_email();
	j[key]["number"] = value.get_number();
	j[key]["addres"] = value.get_addres();
}

void File::to_object_json(json& j, Person& value, std::string key)
{
	value.set_id(j[key]["id"].get<std::string>());
	value.set_name(j[key]["name"].get<std::string>());
	value.set_last_name(j[key]["last_name"].get<std::string>());
	value.set_date_of_birth(j[key]["date_of_birth"].get<std::string>());
	value.set_email(j[key]["email"].get<std::string>());
	value.set_number(j[key]["number"].get<std::string>());
	value.set_addres(j[key]["addres"].get<std::string>());
}