#include <iostream>

#include "utils.h"
#include "Operacion.h"
#include <iomanip>

int main()
{
    Operacion op;
    AvlTree tree;
    int a = 0;
    op.cargar_Archivo_en_arbol(tree, "dic.txt");
    //? tree.insert(spanish_word, english_word);
    tree.insert("Hola", "Hello");
    tree.insert("sol", "sun");
    tree.insert("inteligente", "smart");
    tree.insert("telefono", "phone");
    tree.insert("casa", "house");
    int i = 1;
    string f2 = "depuradodic.txt";
    ofstream archivo2(f2.c_str());
    tree.for_each_inorder([&i,&archivo2](AvlNode* node)
        { std::cout << i++ << "  " << node->english_word() << ", " << node->spanish_word() << std::endl;
    
        /*if (i == 1) {
            archivo2 << node->english_word() << ", " << node->spanish_word();
        }*/
        //else {
   
            archivo2 << endl;
            archivo2 << node->english_word() << "," << node->spanish_word();
       // }
        });
    archivo2.close();

    std::cout << "Elementos Insertados" << std::endl;

    std::cout << "\nInorder Tree" << std::endl;
     i = 1;

    std::cout << std::endl;
    tree.print_tree(tree.get_root(), nullptr, false, 1);
    std::cout << std::endl;

    tree.remove("sol");
    std::cout << std::endl;

    std::cout << "Arbol Luego de eliminar un nodo" << std::endl;
    std::cout << "\nPostorder Tree" << std::endl;
    tree.for_each_postorder([&i](AvlNode *node)
                            { std::cout << i++ << "  " << node->english_word() << ", " << node->spanish_word() << std::endl; });
    std::cout << std::endl;

    AvlNode *test_find = tree.find("house");
    std::cout << "Nodo encontrado: " << test_find->spanish_word() << "," << test_find->english_word() << std::endl;

    tree.print_tree(tree.get_root(), nullptr, false, 0);
    
    return 0;
}