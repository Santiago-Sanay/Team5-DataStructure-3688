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
        {3, "MOSTRAR TABLA DE AMORTIZACION", print_amortization_table},
        {4, "GENERAR PDF", create_pdf},
        {5, "SALIR", nullptr}
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
        getline(std::cin, id);
        validate_id =  (File::search(id) || Utils::Validation::validate_id(id));
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
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
    init();
}

LinkedList<Person> &Application::container()
{
    LinkedList<Person> persons = File::read();
    return persons;
}

LinkedList<Doubt>& Application::container_credits()
{
    LinkedList<Doubt> credits = File::read("credits.json");
    return credits;
}

void Application::create_credit() {
    bool validate_id = true;
    bool search = false;
    bool search_credit = false;
    bool bandera = false;
    LinkedList<Person> persons = Application::container();
    LinkedList<Doubt> credits = Application::container_credits();
   
    std::string id;

    while (validate_id)
    {
        std::cout << "Ingrese el numero de cedula: ";
        getline(std::cin, id);
        validate_id =  !Utils::Validation::validate_id(id);
        


        if (validate_id)
        {
            search = File::search(id);
            if (search)
            {
                search_credit = File::search_credits(id);
                if (search_credit)
                {
                    bandera = false;
                }
                else
                {
                    bandera = true;
                    validate_id = false;
                }
            }
            else
            {
                std::cout << "El usuario no esta registrado" << std::endl;
                system("pause");
                init();
            }
        }
        else
        {
            validate_id = true;
        }
        
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        
    }

    if (!bandera)
    {
        Application::print_exists(id);
    }
    else
    {
        char answer;
        std::cout << std::endl;
        std::cout << "Desea crear un credito (S/N): ";
        std::cin >> answer;

        if (answer == 'S' || answer == 's') {

            double amount = { 0.0 };
            int interest = { 0 };
            int months{ 0 };

            std::string date;
            char typeAmt;

            bool validate = true;
            while (validate) {
                std::cout << "Ingrese monto de credito a solicitar: ";
                std::cin >> amount;
                validate = Utils::Validation::validate_input_number(amount);
            }
            validate = true;
            while (validate) {
                std::cout << "Ingrese numero de meses a pagar: ";
                std::cin >> months;
                validate = Utils::Validation::validate_input_number(months);
            }
            validate = true;
            while (validate) {
                std::cout << "Ingrese la fecha de primer en formato(dd-mm-AAAA): ";
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
            std::cout << "Ingrese el tipo de Amortizacion Aleman o Frances (A/F): ";
            std::cin >> typeAmt;

            Doubt loan;
            if (typeAmt == 'A' || typeAmt == 'a')
            {
                loan = Doubt(id, amount, date, months, "ALEMAN", interest);
            }
            else
            {
                loan = Doubt(id, amount, date, months, "FRANCES", interest);
            }
            LinkedList<Doubt> doubts;
            doubts.add(loan);
            File::add(doubts);
            std::cout << "SE HA AGREGADO EL CREDITO CON EXITO" << std::endl;
            system("pause");
            init();
        }
        else 
        {
            init();
        }
    }

}

void Application::create_pdf()
{   
    bool validate_id = true;
    bool search = false;
    bool search_credit = false;
    bool bandera = false;
    std::string id;
    while (validate_id)
    {
        std::cout << "Ingrese el numero de cedula: ";
        getline(std::cin, id);
        validate_id = !Utils::Validation::validate_id(id);

        if (validate_id)
        {
            search = File::search(id);
            if (search)
            {
                search_credit = File::search_credits(id);
                if (!search_credit)
                {
                    bandera = false;
                }
                else
                {
                    bandera = true;
                    validate_id = false;
                }
            }
            else
            {
                std::cout << "El usuario no esta registrado" << std::endl;
                system("pause");
                init();
            }
        }
        else
        {
            validate_id = true;
        }

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    if (search_credit)
    {
        TextTable table_text('-', '|', '+');
        LinkedList<Due>  due = Application::amortization(id);
        Person person = File::at_person(id);
        std::ostringstream html;

        html << "<html>"
            "<head><title>Amortizacion</title></head>"
            "<body>";
            html << "<table><thead><tr>"
            "<th>CEDULA</th>"
            "<th>NOMBRE</th>"
            "<th>APELLIDO</th>"
            "</tr></thead><tbody>";
            html << "<tr>";
            html << "<td>" + person.get_id() + "</td>";
            html << "<td>" + person.get_name() + "</td>";
            html << "<td>" + person.get_last_name() + "</td>";
            html << "</tr></tbody></table>";
            html <<
            "<table><thead><tr>"
            "<th>NO</th>"
            "<th>FECHAS DE PAGO</th>"
            "<th>DIA</th>"
            "<th>CAPITAL</th>"
            "<th>INTERES</th>"
            "<th>TOTAL</th>"
            "</tr></thead><tbody>";

        table_text.add("NO");
        table_text.add("FECHAS DE PAGO");
        table_text.add("DIA");
        table_text.add("CAPITAL");
        table_text.add("INTERES");
        table_text.add("TOTAL");
        table_text.endOfRow();
        Node<Due>* node = due.get_front();
        int i = 1;
        while (node)
        {
            table_text.add(std::to_string(i++));
            table_text.add(node->get_data().get_date());
            table_text.add(node->get_data().get_weekday());
            table_text.add(Utils::Generator::to_string(node->get_data().get_capital()));
            table_text.add(Utils::Generator::to_string(node->get_data().get_interest()));
            table_text.add(Utils::Generator::to_string(node->get_data().get_mounthly_amount()));
            table_text.endOfRow();

            html << "<tr>"
                << "<td>" + std::to_string(i-1) + "</td>"
                << "<td>" + node->get_data().get_date() + "</td>"
                << "<td>" + node->get_data().get_weekday() + "</td>"
                << "<td>" + Utils::Generator::to_string(node->get_data().get_capital()) + "</td>"
                << "<td>" + Utils::Generator::to_string(node->get_data().get_interest()) + "</td>"
                << "<td>" + Utils::Generator::to_string(node->get_data().get_mounthly_amount()) + "</td>"
                << "</tr>";
            node = node->get_next();
        }
        table_text.endOfRow();
        table_text.setAlignment(2, TextTable::Alignment::RIGHT);
        std::cout << table_text << std::endl;
        html << "</tbody></table></body></html>";
        
        std::ostringstream plain;
        std::string html_filename = "data_" + id + ".html";
        std::string pdf_filename = "data_" + id + ".pdf";
        std::ofstream out_html(html_filename, std::ios::trunc);
        std::ofstream out_txt("data_" + id + ".txt", std::ios::trunc);

        out_txt << table_text;
        out_html << html.str();
        out_txt.close();
        out_html.close();

        if (std::ifstream(pdf_filename.c_str()).good()) {
            std::remove(pdf_filename.c_str());
        }

        system((std::string("wkhtmltopdf.exe ") + html_filename + " " + pdf_filename).c_str());
        std::cout << std::endl << "archivo pdf generado!";
        system("pause");
        init();
    }
    else
    {
        std::cout << "USUARIO NO ENCONTRADO" << std::endl;
        system("pause");
        init();
    }

}

void Application::print_exists(std::string id)
{
    TextTable table_text('-', '|', '+');
    Doubt doubt = File::at(id);
    Person person = File::at_person(id);

    table_text.add("CEDULA");
    table_text.add("APELLIDOS");
    table_text.add("NOMBRES");
    table_text.add("EDAD");
    table_text.add("EMAIL");
    table_text.add("PHONE");
    table_text.add("DIRECCION");
    table_text.add("CREDITO");
    table_text.add("PLAZO MESES");
    table_text.add("TOTAL");
    table_text.add("TIPO DE AMORTIZACION");
    table_text.endOfRow();

    table_text.add(person.get_id());
    table_text.add(person.get_last_name());
    table_text.add(person.get_name());
    table_text.add(std::to_string(person.get_age()));
    table_text.add(person.get_email());
    table_text.add(person.get_number());
    table_text.add(person.get_addres());
    table_text.add(Utils::Generator::to_string(doubt.get_initial_amount()));
    table_text.add(std::to_string(doubt.get_payment_time()));
    table_text.add(Utils::Generator::to_string(doubt.get_final_amount()));
    table_text.add(doubt.get_rate_of_interest());
    table_text.endOfRow();
    table_text.setAlignment(2, TextTable::Alignment::RIGHT);
    std::cout << table_text;

}

void Application::print_amortization_table()
{
    bool validate_id = true;
    bool search = false;
    bool search_credit = false;
    bool bandera = false;
    std::string id;
    while (validate_id)
    {
        std::cout << "Ingrese el numero de cedula: ";
        getline(std::cin, id);
        validate_id = !Utils::Validation::validate_id(id);

        if (validate_id)
        {
            search = File::search(id);
            if (search)
            {
                search_credit = File::search_credits(id);
                if (!search_credit)
                {
                    bandera = false;
                }
                else
                {
                    bandera = true;
                    validate_id = false;
                }
            }
            else
            {
                std::cout << "El usuario no esta registrado" << std::endl;
                system("pause");
                init();
            }
        }
        else
        {
            validate_id = true;
        }

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }

    if (search_credit)
    {
        TextTable table_text('-', '|', '+');
        LinkedList<Due>  due = Application::amortization(id);
        Person person = File::at_person(id);

        table_text.add("NO");
        table_text.add("FECHAS DE PAGO");
        table_text.add("DIA");
        table_text.add("CAPITAL");
        table_text.add("INTERES");
        table_text.add("TOTAL");
        table_text.endOfRow();
        Node<Due>* node = due.get_front();
        int i = 1;
        while (node)
        {
            table_text.add(std::to_string(i++));
            table_text.add(node->get_data().get_date());
            table_text.add(node->get_data().get_weekday());
            table_text.add(Utils::Generator::to_string(node->get_data().get_capital()));
            table_text.add(Utils::Generator::to_string(node->get_data().get_interest()));
            table_text.add(Utils::Generator::to_string(node->get_data().get_mounthly_amount()));
            table_text.endOfRow();
            node = node->get_next();
        }
        table_text.endOfRow();
        table_text.setAlignment(2, TextTable::Alignment::RIGHT);
        std::cout << table_text << std::endl;

        system("pause");
        init();
    }
    else
    {
        std::cout << "USUARIO NO ENCONTRADO" << std::endl;
        system("pause");
        init();
    }
}

LinkedList<Due> Application::amortization(std::string &id)
{
    Doubt loan = File::at(id);
    LinkedList<Due> dues;
    CalendarOperation op;
    double final_ammount = loan.get_final_amount();
    if (loan.get_rate_of_interest().compare("ALEMAN") == 0) {
        op.german_amortization(loan.get_initial_date(), loan.get_initial_amount(), loan.get_payment_time(), loan.get_interest(), dues, final_ammount);
    }
    else {
        op.french_amortization(loan.get_initial_date(), loan.get_initial_amount(), loan.get_payment_time(), loan.get_interest(), dues, final_ammount);
    }
    return dues;
}