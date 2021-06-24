#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Node.h"
#include "Person.h"
#include "LinkedList.h"
#include "json.hpp"

using json = nlohmann::json;
class File
{
public:
	static void delete_account();
	static void add(LinkedList<Person>&);
	static void update();
	static bool search(std::string &);
	static LinkedList<Person>read();
	static void to_json_objet(json& j,  Person value);
	static void to_object_json(json& j, Person& value, std::string);
	template <typename T>
	static void from_json(const json& j, Person& value);
};

