#include "Application.h"
int Application::run()
{
    init();
    return 0;
}

void Application::init()
{
    //Crear Menu
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
        validate_id = !Utils::Validation::validate_id(id);
        std::cin.clear(); // Clear error flags
        std::cin.ignore(9999, '\n');
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
    while (validate)
    {
        std::cout << "Ingrese la dirreccion: ";
        std::getline(std::cin, addres);
        validate = Utils::Validation::validate_string(addres);
    }
    validate = true;
    int age = Utils::Generator::calculate_age(date_of_birth);
    std::cout << age << std::endl;
    Person person ("1726137597", "Junior Stalin", "Jurado", "22/07/1999", "0965412895", "Guamani");
    Person person1("1718605155", "Alex Santiago", "Paguay", "16/05/10991", "0965412895", "Sangolqui");
    person.set_email("jsjurado@espe.fin.ec");
    LinkedList<Person> persons;
    persons.add(person);
    persons.add(person1);

    std::string date = Utils::Generator::create_email(persons, "Junior Stalin", "Jurado Pena");

    std::cout << date << std::endl;
    
   //File::add(persons);

    //<Person> persons_test;
    //persons_test = File::read();
    //Node<Person>*node = persons_test.at(0);
    //Node<Person>*node1 = persons_test.at(1);

   // std::cout << persons_test.get_size() << std::endl;
   // std::cout << node->get_data().get_name() << ", "<< persons.get_size() << std::endl;
  //  std::cout << node1->get_data().get_name() << ", " << persons.get_size() << std::endl;
    //std::string email = Utils::Generator::create_email(persons, "Junior Stalin", "Jurado");
    //std::cout << email << std::endl;
}


