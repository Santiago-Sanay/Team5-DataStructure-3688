#pragma once
#include "utils.h"
#include <iostream>
#include <string>
#include "avl_tree.h"
#include <vector>
#include <thread>
#include "menu.h"
#include "hash_table.hpp"

template <typename T = std::string, typename K = std::string>
class HashTable;

class AvlTree;

enum ApplicationState
{
    RUN,
    STOP,
    RUNNING
};

enum Language
{
    ENGLISH = 1,
    SPANISH = 2
};

class Application
{
public:
    static inline int run(int);
    static inline void exit();

private:
    static inline void main_menu();
    static inline void administrator_menu();
    static inline void user_menu();

private:
    static inline void init_tree(AvlTree &, int state, int type);
    static inline void find_word();
    static inline void list_words();
    static inline void print_tree();
    static inline void new_admin();
    static inline void add_word();
    static inline void remove_word();

    ///////////////////////////////////////////////////////////////////

private:
    static inline void administrator_menu_table();
    static inline void user_menu_table();

private:
    template <typename T, typename K>
    static inline void init_table(HashTable<T, K> &, int state, int type);
    static inline void find_word_table();
    static inline void list_words_table();
    static inline void add_word_table();
};

int inline Application::run(int state)
{
    std::cout << "Cargando los elementos necesario....." << std::endl;
    AvlTree tree{};
    AvlTree temp{};
    HashTable<std::string, std::string> table_spanish;
    HashTable<std::string, std::string> table_english;
    if (state == ApplicationState::RUN)
    {
        init_tree(tree, ApplicationState::RUN, Language::ENGLISH);
        init_tree(temp, ApplicationState::RUN, Language::SPANISH);
        init_table(table_english, ApplicationState::RUN, Language::ENGLISH);
        init_table(table_spanish, ApplicationState::RUN, Language::SPANISH);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system("cls");
        main_menu();
    }
    return 0;
}

inline void Application::main_menu()
{
    while (true)
    {
        std::cout << "[1] AVL-TREE" << std::endl;
        std::cout << "[2] HASH-TABLE" << std::endl;
        std::cout << "[3] SALIR" << std::endl;
        int opcion = Utils::Validation::read_int("Seleccione una opcion: ", 1, 1);
        std::cin.ignore();
        switch (opcion)
        {
        case 1:
        {
            std::vector<MenuOption> menu_item{
                {1, "ADMINISTRADOR", administrator_menu},
                {2, "USUARIO", user_menu},
                {3, "SALIR", exit}};
            Menu menu{menu_item};
            menu.navigation();
            break;
        }
        case 2:
        {
            std::vector<MenuOption> menu_item{
                {1, "ADMINISTRADOR", administrator_menu_table},
                {2, "USUARIO", user_menu_table},
                {3, "SALIR", exit}};
            Menu menu{menu_item};
            menu.navigation();
        }
        case 3:
        {
            std::exit(0);
        }
        default:
        {
            std::cout << "Opcion no valida" << std::endl;
            system("cls");
            main_menu();
        }
        }
    }
}

inline void Application::administrator_menu()
{
    std::cout << "Administrador" << std::endl;
    std::string user = Utils::Validation::read_string("Ingrese el usuario: ", Utils::InputType::USER);
    std::string password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
    std::cout << std::endl;

    if (Utils::Login::login(user, password))
    {
        std::vector<MenuOption> menu_item{
            {1, "BUSCAR UNA PALABRA", find_word},
            {2, "LISTAR PALABRAS", list_words},
            {3, "IMPRIMIR ARBOL", print_tree},
            {4, "INGRESAR NUEVA PALABRA", add_word},
            {5, "ELIMINAR UNA PALABRA", remove_word},
            {6, "CREAR ADMINISTRADOR", new_admin},
            {7, "REGRESAR", main_menu},
            {8, "SALIR", exit}};

        Menu menu{menu_item};
        menu.navigation();
    }
    else
    {
        if (!Utils::File::exists_file("user.txt"))
        {
            std::cout << "NO EXISTE NINGUN ADMINISTRADOR PRINCIPAL" << std::endl;
            std::string user = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
            std::string password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
            Utils::Generator::generate_admins(user, password);
            std::cout << "\nAdministrador principal creado" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            main_menu();
        }
        std::cout << "\nUSUARIO O CONTRASEÑA INCORRECTO" << std::endl;
        std::cin.get();
        std::cout << "\033[2J\033[1;1H";
        main_menu();
    }
}

inline void Application::user_menu()
{
    std::vector<MenuOption> menu_item{
        {1, "BUSCAR UNA PALABRA", find_word},
        {2, "LISTAR PALABRAS", list_words},
        {3, "IMPRIMIR ARBOL", print_tree},
        {4, "REGRESAR", main_menu},
    };

    Menu menu{menu_item};
    menu.navigation();
}

inline void Application::user_menu_table()
{
    std::vector<MenuOption> menu_item{
        {1, "BUSCAR UNA PALABRA", find_word_table},
        {2, "LISTAR PALABRAS", list_words_table},
        {4, "REGRESAR", main_menu},
    };

    Menu menu{menu_item};
    menu.navigation();
}

inline void Application::exit()
{
    AvlTree tree;
    init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
    std::cout << "Actualizando datos..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    init_tree(tree, ApplicationState::STOP, Language::ENGLISH);
    std::cout << "Programa finalizado" << std::endl;
    std::exit(0);
}

inline void Application::init_tree(AvlTree &tree, int state, int type)
{

    static AvlTree temp_tree_spanish;
    static AvlTree temp_tree_english;
    if (state == ApplicationState::RUN)
    {
        if (type == Language::ENGLISH)
        {
            Utils::File::load_tree(temp_tree_english, "dic.txt", Language::ENGLISH);
        }
        if (type == Language::SPANISH)
        {
            Utils::File::load_tree(temp_tree_spanish, "dic.txt", Language::SPANISH);
        }
    }
    else if (state == ApplicationState::RUNNING)
    {
        if (type == Language::SPANISH)
        {
            tree = temp_tree_spanish;
        }
        if (type == Language::ENGLISH)
        {
            tree = temp_tree_english;
        }
    }
    else if (state == ApplicationState::STOP)
    {
        Utils::File::save_tree(tree, "dic.txt");
    }
}

inline void Application::find_word()
{
    enum LanguageType
    {
        ENGLISH = 1,
        SPANISH = 2
    };
    int option = 0;
    while (true)
    {
        std::cout << "BUSCAR PALABRA[INGLES/ESPAÑOL] o [ESPAÑOL/INGLES]\n"
                  << std::endl;
        std::cout << "[1] IMPRIMIR INGLES-ESPANOL" << std::endl;
        std::cout << "[2] IMPRIMIR ESPAÑOL-INGLES" << std::endl;
        option = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));

        if (option == ENGLISH || option == SPANISH)
        {
            break;
        }
        std::cout << "\033[2J\033[1;1H";
    }
    std::cin.ignore();
    std::string word = Utils::Validation::read_string(
        "Ingrese la palabra a buscar: ", Utils::InputType::WORD);
    AvlTree tree;
    Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
    if (tree.has(word))
    {
        std::vector<AvlNode *> node = tree.find(word);

        if (option == ENGLISH)
        {
            std::cout << "\nTotal de palabras encontradas: " << node.size() << std::endl;
            int i = 1;
            for (auto &n : node)
            {
                std::cout << "[" << i << "] " << n->english_word() << ": "
                          << n->spanish_word() << std::endl;
                i++;
            }
        }
        if (option == SPANISH)
        {
            std::cout << "\nTotal de palabras encontradas: " << node.size() << std::endl;
            int i = 1;
            for (auto &n : node)
            {
                std::cout << "[" << i << "] " << n->spanish_word() << ": "
                          << n->english_word() << std::endl;
                i++;
            }
        }
        node.clear();
    }
    else
    {
        std::cout << "\nNO EXISTE LA PALABRA EN EL DICCIONARIO" << std::endl;
    }
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
}

inline void Application::list_words()
{
    enum TypeTraversal
    {
        PREORDER = 1,
        INORDER = 2,
        POSTORDER = 3
    };
    enum LanguageType
    {
        ENGLISH = 1,
        SPANISH = 2
    };

    int option = 0;
    while (true)
    {
        std::cout << "LISTAR PALABRAS [PREORDEN] [INORDER] [POSTORDER]" << std::endl;
        std::cout << "[1] PREORDER" << std::endl;
        std::cout << "[2] INORDER[ALFABETICO]" << std::endl;
        std::cout << "[3] POSTORDER" << std::endl;
        option = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
        if (option == PREORDER || option == INORDER || option == POSTORDER)
        {
            break;
        }
        system("cls");
    }
    AvlTree tree_spanish; //[ESPAÑOL/INGLES]
    AvlTree tree_english; //[INGLES/ESPAÑOL]
    Application::init_tree(tree_spanish, ApplicationState::RUNNING, Language::SPANISH);
    Application::init_tree(tree_english, ApplicationState::RUNNING, Language::ENGLISH);

    if (option == PREORDER)
    {
        int op = 0;
        while (true)
        {
            std::cout << "[1] INGLES/ESPAÑOL" << std::endl;
            std::cout << "[2] ESPAÑOL/INGLES" << std::endl;
            op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
            if (op == ENGLISH || op == SPANISH)
            {
                break;
            }
            system("cls");
        }

        if (op == ENGLISH)
        {
            tree_english.for_each_preorder([](AvlNode *node)
                                           { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
        }
        if (op == SPANISH)
        {
            tree_spanish.for_each_preorder([](AvlNode *node)
                                           { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
        }
    }
    if (option == INORDER)
    {
        int op = 0;
        while (true)
        {
            std::cout << "[1] INGLES/ESPAÑOL" << std::endl;
            std::cout << "[2] ESPAÑOL/INGLES" << std::endl;
            op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
            if (op == ENGLISH || op == SPANISH)
            {
                break;
            }
            system("cls");
        }

        if (op == ENGLISH)
        {
            tree_english.for_each_inorder([](AvlNode *node)
                                          { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
            std::cin.get();
            std::cout << "\033[2J\033[1;1H";
        }
        if (op == SPANISH)
        {
            tree_spanish.for_each_inorder([](AvlNode *node)
                                          { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
        }
    }
    if (option == POSTORDER)
    {
        int op = 0;
        while (true)
        {
            std::cout << "[1] INGLES/ESPAÑOL" << std::endl;
            std::cout << "[2] ESPAÑOL/INGLES" << std::endl;
            op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
            if (op == ENGLISH || op == SPANISH)
            {
                break;
            }
            system("cls");
        }

        if (op == ENGLISH)
        {
            tree_english.for_each_postorder([](AvlNode *node)
                                            { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
        }
        if (op == SPANISH)
        {
            tree_spanish.for_each_postorder([](AvlNode *node)
                                            { std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
            std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
        }
    };
    system("pause");
}

inline void Application::print_tree()
{
    enum LanguageType
    {
        ENGLISH = 1,
        SPANISH = 2
    };

    int option = 0;
    while (true)
    {
        std::cout << "Imprimir arbol" << std::endl;
        std::cout << "[1] IMPRIMIR ARBOL EN INGLES" << std::endl;
        std::cout << "[2] IMPRIMIR ARBOL EN ESPAÑOL" << std::endl;
        option = (Utils::Validation::read_int("Ingrese la opcion: ", 1, 1));
        if (option == ENGLISH || option == SPANISH)
        {
            break;
        }
    }
    std::cin.ignore();
    AvlTree tree;
    Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
    if (option == ENGLISH)
    {
        tree.print_tree(tree.get_root(), nullptr, false, ENGLISH);
    }
    if (option == SPANISH)
    {
        tree.print_tree(tree.get_root(), nullptr, false, SPANISH);
    }
    system("pause");
}

inline void Application::new_admin()
{
    std::cout << "Desea Crear un nuevo administrador[s/n]: ";
    char option = 0;
    std::cin >> option;
    std::cin.ignore();
    if (option == 's' || option == 'S')
    {
        system("cls");
        std::cout << "Ingrese los datos del administrador principal: " << std::endl;
        std::string user_admin = Utils::Validation::read_string("Ingrese el usuario: ", Utils::InputType::USER);
        std::string password_admin = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
        std::cout << std::endl;

        if (Utils::Login::login(user_admin, password_admin))
        {
            std::string new_user = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
            std::string new_password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
            Utils::Generator::generate_admins(new_user, new_password);
            std::cout << "Administrado creado con exito" << std::endl;
            main_menu();
        }
        else
        {
            std::cout << "Credenciales incorrectas, regresando al menu principal. " << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            administrator_menu();
        }
    }
    else
    {
        administrator_menu();
    }
}

inline void Application::add_word()
{
    AvlTree tree;
    Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
    while (true)
    {
        std::cout << "Ingrese la palabra a insertar." << std::endl;

        std::string spanish_word = Utils::Validation::read_string("Español: ", Utils::InputType::WORD);
        std::string english_word = Utils::Validation::read_string("Ingles: ", Utils::InputType::WORD);

        if (tree.has(english_word))
        {
            std::cout << "La palabra ya existe en el diccionario." << std::endl;
        }
        else
        {
            tree.insert(spanish_word, english_word);
        }
        std::cout << "Desea agregar otra palabra[s/n]: ";
        char option = 0;
        std::cin >> option;
        std::cin.ignore();
        if (option == 's' || option == 'S')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    system("cls");
    administrator_menu();
}

inline void Application::remove_word()
{

    while (true)
    {
        std::cout << "ELIMINAR PALABRAS" << std::endl;
        std::cout << "Ingrese la palabra a eliminar." << std::endl;
        std::string word = Utils::Validation::read_string("\nPalabra: ", Utils::InputType::WORD);
        AvlTree tree;
        Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);

        if (tree.has(word))
        {
            tree.remove(word);
            std::cout << "ELIMINACION EXITOSA" << std::endl;
        }
        else
        {
            std::cout << "LA PALABRA INGRESADA NO EXISTE EN EL DICCIONARIO" << std::endl;
        }
        std::cout << "\nDesea eliminar otra palabra[s/n]: ";
        char option = 0;
        std::cin >> option;
        std::cin.ignore();
        if (option == 's' || option == 'S')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

inline void Application::administrator_menu_table()
{
    std::cout << "Administrador" << std::endl;
    std::string user = Utils::Validation::read_string("Ingrese el usuario: ", Utils::InputType::USER);
    std::string password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
    std::cout << std::endl;

    if (Utils::Login::login(user, password))
    {
        std::vector<MenuOption> menu_item{
            {1, "BUSCAR UNA PALABRA", find_word_table},
            {2, "LISTAR PALABRAS", list_words_table},
            {3, "INGRESAR NUEVA PALABRA", add_word},
            {4, "ELIMINAR UNA PALABRA", remove_word},
            {5, "MODIFICAR UNA PALABRA", nullptr},
            {6, "REGRESAR", main_menu},
            {7, "SALIR", exit}};

        Menu menu{menu_item};
        menu.navigation();
    }
    else
    {
        if (!Utils::File::exists_file("user.txt"))
        {
            std::cout << "NO EXISTE NINGUN ADMINISTRADOR PRINCIPAL" << std::endl;
            std::string user = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
            std::string password = Utils::Validation::read_string("Ingrese la contraseña: ", Utils::InputType::PASSWORD);
            Utils::Generator::generate_admins(user, password);
            std::cout << "\nAdministrador principal creado" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            main_menu();
        }
        std::cout << "\nUSUARIO O CONTRASEÑA INCORRECTO" << std::endl;
        std::cin.get();
        std::cout << "\033[2J\033[1;1H";
        main_menu();
    }
}

template <typename T, typename K>
inline void Application::init_table(HashTable<T, K> &table, int state, int type)
{
    static HashTable<T, K> temp_table_spanish;
    static HashTable<T, K> temp_table_english;
    if (state == ApplicationState::RUN)
    {
        if (type == Language::ENGLISH)
        {
            Utils::File::load_table(temp_table_english, "dic_table.txt", Language::ENGLISH);
        }
        if (type == Language::SPANISH)
        {
            Utils::File::load_table(temp_table_spanish, "dic_table.txt", Language::SPANISH);
        }
    }
    else if (state == ApplicationState::RUNNING)
    {
        if (type == Language::SPANISH)
        {
            table = temp_table_spanish;
        }
        if (type == Language::ENGLISH)
        {
            table = temp_table_english;
        }
    }
    else if (state == ApplicationState::STOP)
    {
        Utils::File::save_table(table, "dic_table.txt");
    }
}

inline void Application::find_word_table()
{
    enum LanguageType
    {
        ENGLISH = 1,
        SPANISH = 2
    };
    int option = 0;
    while (true)
    {
        std::cout << "BUSCAR PALABRA[INGLES/ESPAÑOL] o [ESPAÑOL/INGLES]\n"
                  << std::endl;
        std::cout << "[1] IMPRIMIR INGLES-ESPANOL" << std::endl;
        std::cout << "[2] IMPRIMIR ESPAÑOL-INGLES" << std::endl;
        option = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));

        if (option == ENGLISH || option == SPANISH)
        {
            break;
        }
        std::cout << "\033[2J\033[1;1H";
    }
    std::cin.ignore();
    std::string word = Utils::Validation::read_string(
        "Ingrese la palabra a buscar: ", Utils::InputType::WORD);

    if (option == ENGLISH)
    {
        HashTable<std::string, std::string> table;
        Application::init_table(table, ApplicationState::RUNNING, Language::ENGLISH);
        std::string found = table.find(word);
        std::cout << word << ": "
                  << found << std::endl;
    }
    if (option == SPANISH)
    {
        HashTable<std::string, std::string> table;
        Application::init_table(table, ApplicationState::RUNNING, Language::SPANISH);
        std::string found = table.find(word);
        std::cout << word << ": "
                  << found << std::endl;
    }
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
}

inline void Application::list_words_table()
{

    enum LanguageType
    {
        ENGLISH = 1,
        SPANISH = 2
    };

    HashTable<std::string, std::string> table_spanish; //[ESPAÑOL/INGLES]
    HashTable<std::string, std::string> table_english; //[INGLES/ESPAÑOL]
    Application::init_table(table_spanish, ApplicationState::RUNNING, Language::SPANISH);
    Application::init_table(table_english, ApplicationState::RUNNING, Language::ENGLISH);

    int op = 0;
    while (true)
    {
        std::cout << "[1] INGLES/ESPAÑOL" << std::endl;
        std::cout << "[2] ESPAÑOL/INGLES" << std::endl;
        op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
        if (op == ENGLISH || op == SPANISH)
        {
            break;
        }
        system("cls");
    }

    if (op == ENGLISH)
    {
        table_english.for_each([](const std::string &key, const std::string &value)
                               { std::cout << key << ": " << value << std::endl; });
    }
    if (op == SPANISH)
    {
        table_spanish.for_each([](const std::string &key, const std::string &value)
                               { std::cout << key << ": " << value << std::endl; });
    }
    system("pause");
}

inline void Application::add_word_table()
{
    HashTable<std::string, std::string> table_spanish; //[ESPAÑOL/INGLES]
    HashTable<std::string, std::string> table_english; //[INGLES/ESPAÑOL]
    Application::init_table(table_spanish, ApplicationState::RUNNING, Language::SPANISH);
    Application::init_table(table_english, ApplicationState::RUNNING, Language::ENGLISH);
    while (true)
    {
        std::cout << "Ingrese la palabra a insertar." << std::endl;
        int op = 0;
        while (true)
        {
            std::cout << "[1] INGLES/ESPAÑOL" << std::endl;
            std::cout << "[2] ESPAÑOL/INGLES" << std::endl;
            op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
            std::cin.ignore();
            if (op == ENGLISH || op == SPANISH)
            {
                break;
            }
            system("cls");
        }
        if (op == ENGLISH)
        {
            std::string english_word = Utils::Validation::read_string("Ingles: ", Utils::InputType::WORD);
            std::string spanish_word = Utils::Validation::read_string("Español: ", Utils::InputType::WORD);

            if (table_english.has(english_word))
            {
                std::cout << "La palabra ya existe en el diccionario." << std::endl;
            }
            else
            {
                table_english.insert(spanish_word, english_word);
            }
        }
        if (op == SPANISH)
        {
            std::string spanish_word = Utils::Validation::read_string("Español: ", Utils::InputType::WORD);
            std::string english_word = Utils::Validation::read_string("Ingles: ", Utils::InputType::WORD);

            if (table_spanish.has(spanish_word))
            {
                std::cout << "La palabra ya existe en el diccionario." << std::endl;
            }
            else
            {
                table_spanish.insert(spanish_word, english_word);
            }
        }
        std::cout << "Desea agregar otra palabra[s/n]: ";
        char option = 0;
        std::cin >> option;
        std::cin.ignore();
        if (option == 's' || option == 'S')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    system("cls");
    administrator_menu();
}