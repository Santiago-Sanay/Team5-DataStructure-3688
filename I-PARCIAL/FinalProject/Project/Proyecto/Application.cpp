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
        {2, "CREAR CREDITO", create_credit},
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
    phone = std::to_string(Utils::Validation::validateDigits(10)).insert(0, "0");
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

void Application::create_credit() {
    bool validate_id = true;
    bool search = false;
    char aswer;
    std::string id;

    while (validate_id)
    {
        std::cout << "Ingrese el numero de cedula: ";
        id = std::to_string(Utils::Validation::validateDigits(10));
        search= File::search(id);
        validate_id = (search || Utils::Validation::validate_id(id));
        std::cin.clear();
    }
    if (search) {

    }
    else {
        std::cout << std::endl;
        std::cout << "Desea crear un credito (S/N):? ";
        std::cin >> aswer;
        if (aswer == 'S'|| aswer=='s') {
            double amount = 0.0;
            int interest=0, months=0;
            std::string date;
            char typeAmt;
            bool validate = true;
            while (validate) {
                std::cout << "Ingrese monto de credito a solicitar : ";
                std::cin >> amount;
                validate = Utils::Validation::validate_input_number(amount);
            } 
            validate = true;
            while (validate) {
                std::cout << "Ingrese numero de meses a pagar ";
                std::cin >> months;
                validate = Utils::Validation::validate_input_number(months);
            } 
            validate = true;
            while (validate) {
                std::cout << "Ingrese la fecha de primer pago segun formato ";
                std::cin >> date;
                validate = Utils::Validation::validate_date(date);
            } 
            validate = true;
            while (validate) {
                std::cout << "Ingrese Tasa de Interes % ";
                std::cin >> interest;
                validate = Utils::Validation::validate_input_number(interest);
            }
            validate = true;
            std::cout << "Que tipo de Amortizacion va a utilizar Aleman o Frances (A/F)";
            std::cin >> typeAmt;
        }
        else {
            exit(0);
        }
    }

}


