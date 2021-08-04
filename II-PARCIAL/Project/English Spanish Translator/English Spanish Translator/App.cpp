#include "App.h"
#include <fstream>
using namespace std;
int Application::run()
{
    init();
    return 0;
}

void Application::init()
{
    std::vector<MenuOption> menu_item
    {
        {1, "ADMINISTRADOR", validate_account},
        {2, "USUARIO", user_menu},
        {3, "SALIR", exit_program}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::manager_menu() {
    std::vector<MenuOption> menu_item
    {
        {1,"TRADUCIR",traductor_menu()},
        {2,"MOSTRAR",print_menu()},
        {3,"DESPLEGAR ARBOL",prueba()},
        {4,"AGREGAR PALABRA",prueba()},
        {5,"ELIMINAR PALABRA",prueba()},
        {6,"MODIFICAR PALABRA",prueba()},
        {7,"MODIFICAR CUENTA",menu_of_modify()},
        {8,"REGRESAR",init()}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::user_menu() {
    std::vector<MenuOption> menu_item
    {
        {1,"TRADUCIR",traductor_menu},
        {2,"MOSTRAR",print_menu},
        {3,"DESPLEGAR ARBOL",prueba},        
        {4,"REGRESAR", init}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::menu_of_modify() {
    std::vector<MenuOption> menu_item
    {
        {1,"MODIFICAR USUARIO",modify_user},
        {2,"MODIFICAR CLAVE",modify_password},
        {3,"REGRESAR", manager_menu}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::traductor_menu() {
    std::vector<MenuOption> menu_item
    {
        {1,"ESPANOL-INGLES",modify_user},
        {2,"INGLES-ESPANOL",modify_password},
        {3,"REGRESAR", manager_menu}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::print_menu() {
    std::vector<MenuOption> menu_item
    {
        {1,"INORDEN",prueba},
        {2,"PREORDEN",prueba},
        {3,"POSTORDEN", prueba},
        {4,"REGRESAR", prueba}
    };
    Menu menu{ menu_item };
    menu.navigation();
}

void Application::prueba() {
    std::cout << "Prueba" << std::endl;
    system("pause");
    user_menu();
}

void Application::exit_program()
{
    exit(0);
}

void Application::validate_account() {
    string user;
    string password;
    string _user;
    string _password;
    _user = read();
    stringstream input(_user);
    getline(input, _user, ',');
    getline(input, _password, ',');
    cout << "Ingrese su nombre de usuario:";
    cin >> user;
    cout << "Ingrese su clave:";
    cin >> password;
    if (user==_user && password == _password)
    {
        manager_menu();
    }
    else {
        cout << "Datos incorrectos" << endl;
    }
    system("pause");
    init();
}

void Application::write(string data) {
    ofstream file;
    file.open("user.txt",ios::out);
    if (file.fail()) {
        cout << "No se pudo abrir en archivo" << endl;
        exit(1);
    }
    file << data;
    file.close();
}

string Application::read() {
    ifstream file;
    string data;
    file.open("user.txt", ios::in);
    if (file.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    while (!file.eof())
    {
        getline(file, data);
    }
    file.close();
    return data;
}

void Application::modify_user() {
    string new_user;
    cout << "Ingrese su nuevo nombre de usuario:";
    cin >> new_user;
    string user;
    string password;
    string data;
    user = read();
    stringstream input(user);
    getline(input, user, ',');
    getline(input, password, ',');
    data = new_user + "," + password;
    cout << "Se ha modificado su usuario" << endl;
    write(data);
    system("pause");
    menu_of_modify();
}

void Application::modify_password() {
    string new_password;
    cout << "Ingrese su nueva clave:";
    cin >> new_password;
    string user;
    string password;
    string data;
    user = read();
    stringstream input(user);
    getline(input, user, ',');
    getline(input, password, ',');
    data = user + "," + new_password;
    cout << "Se ha modificado su clave" << endl;
    write(data);
    system("pause");
    menu_of_modify();
}
