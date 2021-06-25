#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Node.h"
#include "Person.h"
#include "LinkedList.h"
#include "json.hpp"
#include "Doubt.h" 

using json = nlohmann::json;
class File
{
public:
	static void delete_account();
	static void add(LinkedList<Person>&);
	static void add(LinkedList<Doubt>&);
	static void update();
	static bool search(std::string &);
	static bool search_credits(std::string &);

	static LinkedList<Person>read();
	static LinkedList<Doubt>read(std::string);
	static Doubt at(std::string);
	static Person at_person(std::string);
	static void to_json_objet(json&,  Person);
	static void to_json_objet(json&, Doubt);
	static void to_object_json(json&, Person&, std::string);
	static void to_object_json(json&, Doubt&, std::string );
};

