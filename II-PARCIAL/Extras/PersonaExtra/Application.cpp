
#include "Nodo.h"
#include "Arbol.h"
#include "Application.h"

/**
 * @brief Crear arbol
 * 
 */
void ingresarP();
/**
 * @brief Contar bisnietos
 * 
 */
void contarB();
/**
 * @brief Agregar hijo
 * 
 */
void tenerHijo();
/**
 * @brief Buscar coincidencia
 * 
 */
void buscarRelacion();
/**
 * @brief buscar parentesco
 * 
 */
void buscarParentesco();
/**
 * @brief terminar programa
 * 
 */
void exit_program();
/**
 * @brief Ingresar nodo
 * 
 * @return Nodo* 
 */
Nodo* ingresoDato();
/**
 * @brief Comprobar Si viven juntos
 * 
 */
void comprobarD();
Arbol* arbol;

int Application::run()
{
    init();
    return 0;
}

void Application::init()
{
    std::vector<MenuOption> menu_item
    {
        {1, "Crear Arbol", ingresarP},
        {2, "Tener hijo", tenerHijo},
        {3, "Contar bisnietos", contarB},
        {4, "Buscar personas relacionadas", buscarRelacion},
        {5, "Buscar parentesco", buscarParentesco},
        {6, "Comprobar divorcio", comprobarD},
        {7, "SALIR", exit_program}
    };
    Menu menu{ menu_item };
    menu.navigation();
}



void Application::exit_program()
{
    cout << "hasta la proxima" << endl;
    exit(0);
}

void ingresarP()
{
    if (arbol == nullptr) {
        Nodo* aux = ingresoDato();
        arbol = new Arbol(aux);
    }
    else {
        cout << "Arbol ya existente" << endl;

    }
    cout << endl;
    system("pause");
    Application::init();
}

Nodo* ingresoDato() {
    string nombre, oficio, sexo;
    int opc;
    Nodo* aux;
    cout << "Ingrese nombre de la persona" << endl;
    cin >> nombre;
    cout << "Ingrese oficio" << endl;
    cin >> oficio;
    cout << "Seleccione Sexo  1-Hombre// 2-Mujer" << endl;
    opc = Utils::Validation::validateDigits(1);
    if (opc == 1)
        sexo = "Masculino";
    else 
        sexo = "Femenino";
    return aux = new Nodo(nombre, oficio, sexo);
}

void contarB()
{
    if (arbol == nullptr) {
        cout << "Ingrese una persona" << endl;
    }
    else {
        string nombre;
        cout << "Ingrese nombre de persona" << endl;
        cin >> nombre;
        if (arbol->buscarNombre(nombre) != nullptr) {
            cout << arbol->cuantosBisNietos(arbol->buscarNombre(nombre)) << endl;

        }
        else {
            cout << "No existe" << endl;
        }

    }
    system("pause");
    Application::init();
}

void tenerHijo()
{

    if (arbol == nullptr) {
        cout << "Ingrese una persona" << endl;
        system("pause");
    }
    else {
        int opc;
        cout << "¿Es Divorciado?" << endl;
        cout << "Seleccione  1-si// 2-no" << endl;
        opc = Utils::Validation::validateDigits(1);
        Nodo* persona = arbol->getUltimo();
        if (opc == 1) {
            persona->setViudo(true);
        }
        else {
            persona->setViudo(false);
        }
        cout <<"\n Padre:" << persona->getNombre() << endl;
        persona->setPrimerHijo(ingresoDato());
        persona->getPrimerHijo()->setPadre(persona);
    }
    Application::init();
}

void buscarRelacion()
{
    if (arbol == nullptr) {
        cout << "Ingrese una persona" << endl;
    }
    else {
        string oficio,sexo;
        int opc;
        cout << "Ingrese el oficio" << endl;
        cin >> oficio;
        cout << "Seleccione Sexo  1-Hombre// 2-Mujer" << endl;
        opc = Utils::Validation::validateDigits(1);
        if (opc == 1)
            sexo = "Masculino";
        else {
            sexo = "Femenino";
        }
        arbol->buscarRelacionados(arbol->raiz, sexo, oficio);
    }
    system("pause");
    Application::init();
}

void buscarParentesco()
{
    string nombre1, nombre2;
    Nodo* p1, * p2;
    if (arbol == nullptr) {
        cout << "Ingrese una persona" << endl;
    }
    else {
        cout << "Ingrese el primer nombre" << endl;
        cin >> nombre1;
        cout << "Ingrese el segundo nombre" << endl;
        cin >> nombre2;
        p1 = arbol->buscarNombre(nombre1);
        p2 = arbol->buscarNombre(nombre2);
        if (p1 == nullptr || p2 == nullptr) {
            cout << "Datos incorrectos" << endl;
        }
        else {
            arbol->verParentesco(p1, p2);
        }
    }
    system("pause");
    Application::init();
}

void comprobarD() {
    string nombre1, nombre2;
    Nodo* p1, * p2;
    if (arbol == nullptr) {
        cout << "Ingrese una persona" << endl;
    }
    else {
        cout << "Ingrese el primer nombre" << endl;
        cin >> nombre1;
        p1 = arbol->buscarNombre(nombre1);
        if (p1 == nullptr ) {
            cout << "Datos incorrectos" << endl;
        }
        else {
            if (p1->getPadre()->getViudo()) {
                cout << "No viven juntos" << endl;
            }
            else {
                cout << "Viven juntos" << endl;
            }
        }
    }
    system("pause");
    Application::init();
}
