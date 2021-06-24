#include "Application.h"
int Application::run()
{
    init();
    return 0;
}

void Application::init()
{
    std::vector<MenuOption> menu_item
    {
        {1, "CREAR CUENTA", create_account},
        {2, "CREAR CREDITO", nullptr},
        {3, "MOSTRAR CREDITO", nullptr},
        {4, "MOSTRAR TABLA DE AMORTIZACION", nullptr},
        {5, "GENERAR PDF", nullptr},
        {6, "SALIR", nullptr}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::create_account()
{
    bool validate_id = true;
    std::string id;

    while (validate_id)
    {
        std::cout << "Ingrese el numero de cedula: ";
        id = std::to_string(Utils::Validation::validateDigits(10));
        validate_id =  (File::search(id) || Utils::Validation::validate_id(id));
        std::cin.clear();
    }
    
    std::cout << std::endl;
    bool validate = true;
    std::string name;
    while (validate)
    {
        std::cout << "Ingrese el nombre: ";
        std::getline(std::cin, name);
        validate = Utils::Validation::validate_string(name);
    }

    validate = true;
    std::string last_name;
    while (validate)
    {
        std::cout << "Ingrese el apellido: ";
        std::getline(std::cin, last_name);
        validate = Utils::Validation::validate_string(last_name);
    }
    validate = true;

    std::string date_of_birth;
    while (validate)
    {
        std::cout << "Ingrese la fecha de nacimiento: ";
        std::getline(std::cin, date_of_birth);
        validate = Utils::Validation::validate_date(date_of_birth);
    }
    validate = true;

    std::string phone;
    std::cout << "Ingrese un numero telefonico: ";
    phone = std::to_string(Utils::Validation::validateDigits(10));
    std::cout << std::endl;


    std::string addres;
    std::cout << "Ingrese la dirreccion: ";
    std::getline(std::cin, addres);
  
 
    LinkedList<Person> persons = Application::container();
    int age = Utils::Generator::calculate_age(date_of_birth);
    std::string email = Utils::Generator::create_email(persons, name, last_name);
    
    Person new_person(id, name, last_name, date_of_birth, phone, addres);
    new_person.set_age(age);
    new_person.set_email(email);
    persons.add(new_person); 
    File::add(persons);
}

LinkedList<Person> &Application::container()
{
    LinkedList<Person> persons = File::read();
    return persons;
}


