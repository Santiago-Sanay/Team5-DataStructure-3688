#include "Utils.h"
#pragma warning(disable : 4996);
using namespace Utils;

bool Validation::validate_id(std::string& _id)
{
    LinkedList<int> v1;
    if (is_digit(_id))
    {
        return false;
    }

    int _id_num = std::stoi(_id);

    if (int(std::log10(_id_num) + 1) != 10)
    {
        return false;
    }
    int temp;
    int sum_par = 0;
    int sum_impar = 0;
    int sum;
    while (_id_num > 0)
    {
        int temp = _id_num % 10;
        _id_num /= 10;
        v1.add(temp);
    }
    for (int i = 1; i < _id.size(); i++)
    {
        if (i % 2) {
            temp = v1.at(i)->get_data() * 2;
            if (temp > 9) {
                temp -= 9;
            }
            sum_par += temp;
        }
        else {
            sum_impar += v1.at(i)->get_data();
        }
    }
    sum = sum_par + sum_impar;
    if ((10 - (sum % 10)) == v1.at(0)->get_data()) {
        return true;
    }
    else {
        std::cout << "\nLa cedula ingresada es invalida" << std::endl;
        return false;
    }
}

bool Utils::Validation::is_digit(const std::string& str)
{
       for(auto &c : str)
       {
           if (!isdigit(c))
           {
               return true;
           }
       }
     return false;
}

bool Validation::validate_string(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (!isalpha(c) && !isspace(c))
        {
            std::cout << "Error!, Solo debe tener letras." << std::endl;
            return true;
        }
    }
    return false;
}

bool Validation::validate_input_number(int& number)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Ingrese solo numeros!" << std::endl;
        return true;
    }
    return false;
}

bool Validation::validate_input_number(double& number)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Ingrese solo numeros!" << std::endl;
        return true;
    }
    return false;
}

bool Validation::validate_input_number(float& number)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Ingrese solo numeros!" << std::endl;
        return true;
    }
    return false;
}

bool Validation::validate_three_digits(long number)
{
    int size = int(std::log10(number) + 1);
    if (size == 10)
    {
        return false;
    }
    return true;
}

long Validation::validateDigits(int digits)
{
    std::string cad;
    int i = 0;
    char c = 0;
    while (i != digits) {
        (c = _getch());
        if (c >= '0' && c <= '9') {
            std::cout << c;
            cad += c;
            i++;
        }
    }
    long datos = std::stoll(cad);
    return datos;
}

inline float Validation::validate_float()
{
    std::string cad;
    //Si se necesita decimales -> decimal = false
    bool decimal = false;
    char c = 0;
    while (c != 13) {
        c = _getch();
        if ((c >= '0' && c <= '9') || c == '.') {
            if (c == '.' && decimal == false) {
                cad += c;
                decimal = true;
                //cout << "entro" << endl;
                std::cout << c;
            }
            else {
                if (c != '.') {
                    cad += c;
                    std::cout << c;
                }
            }
        }
    }
    std::cout << "" << std::endl;
    const char* ca = cad.c_str();
    float f = std::strtof(ca, 0);
    return f;
}

template <typename T>
T Validation::validation_numbers(std::string str)
{
    char error = 'a';
    T number;
    int again = 1;
    while (again == 1)
    {
        try
        {
            std::cout << str << " : ";
            std::cin >> number;
            if (!std::cin)
            {
                throw error = -1;
            }
            again = 0;
        }
        catch (...)
        {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(9999, '\n');
            std::cout << "Dato incorrecto intente de nuevo" << std::endl;
            again = 1;
        }
    }
    return number;
}

bool Validation::validate_date(std::string input)
{
    std::regex pattern("^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|(?:(?:29|30)(\\/|-|\\.)(?:0?[1,3-9]|1[0-2])\\2))(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$");

    input.erase(std::remove_if(
        input.begin(),
        input.end(),
        ::isspace
    ), input.end());

    std::smatch sm;

    if (!std::regex_match(input, sm, pattern)) {
        std::cout << "Formato incorrecto!" << std::endl;
        return true;
    }
    std::string date = sm[0].str().c_str();
    std::string actual_date = Generator::return_current_time_and_date();

    std::regex regex{ R"([\/]+)" };
    std::sregex_token_iterator it{ date.begin(), date.end(), regex, -1 };
    std::vector<std::string> parts{ it, {} };

    int day = std::stoi(parts[0]);
    int month = std::stoi(parts[1]);
    int year = std::stoi(parts[2]);
   

    std::sregex_token_iterator it_actual{ actual_date.begin(), actual_date.end(), regex, -1 };
    std::vector<std::string> token{ it_actual, {} };

    int actual_day = std::stoi(token[0]);
    int actual_month = std::stoi(token[1]);
    int actual_year = std::stoi(token[2]);

    if (!(year < actual_year))
    {
        return true;
    }
    return false;
}


int Generator::random_int(const int min, const int max)
{
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(
        std::chrono::system_clock::now().time_since_epoch().count());

    return dist(random_generator);
}

std::string Generator::return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y");
    return ss.str();
}

int Generator::calculate_age(std::string birth_date_) 
{
    int day = stoi(birth_date_.substr(0, 2));
    int month = stoi(birth_date_.substr(3, 2));
    int year = stoi(birth_date_.substr(6, 9));
    int age;
    std::string date = Generator::return_current_time_and_date();
    int day_actual = stoi(date.substr(0, 2));
    int month_actual = stoi(date.substr(3, 2));
    int year_actual = stoi(date.substr(6, 9));
    if (day_actual < day) {
        day_actual = day + 30;
        month_actual -= 1;
    }
    if (month_actual < month) {
        month_actual += 12;
        year_actual -= 1;
    }
    age = year_actual - year;
    return age;
}

std::string Generator::create_email(LinkedList<Person> people, std::string name1, std::string last)
{
    if (people.is_empty())
    {
        return "\0";
    }
    std::string name, last_name;
    name = lower_case(name1);

    last_name = Generator::lower_case(last);

    std::string email;
    email += name.substr(0, 1);

    email += name.substr(name.find(" ", 0) + 1, 1);

    if (last_name.find(" ", 0) < last_name.length()) {
        email += last_name.substr(last_name.find(" ", 0), 1);
    }
    else {
        email += last_name;
    }

    std::string domain = "@espe.fin.ec";
    std::string email_temp, useremail;
    Node<Person>* person1 = people.get_front();
    size_t positiondomain = 0;
    int last_digit = 0;
    while (person1) {
        email_temp = person1->get_data().get_email();
        positiondomain = email_temp.find("@", 0);
        useremail = email_temp.substr(0, positiondomain);

        if (useremail.length() == email.length()) {

            if (useremail.find(email, 0) == 0) {
                if (Validation::is_digit(useremail.substr(useremail.length() - 1, 1))) {
                    last_digit = std::stoi(email.substr(email.length() - 1, 1));
                    last_digit = last_digit + 1;
                    email = email.substr(0, email.length() - 1) + std::to_string(last_digit);
                }
                else {
                    email += "1";
                }
            }
        }
        person1 = person1->get_next();
    }
    return email += domain;
}

std::string Generator::lower_case(std::string cad)
{
    for (int i = 0; i < cad.length(); i++) cad[i] = tolower(cad[i]);
    return cad;
}