#include <iostream>
#include "avl_tree.h"
#include "avl_node.h"
#include "utils.h"
#include <iomanip>

int main()
{

    AvlTree tree;
    //? tree.insert(spanish_word, english_word);
    tree.insert("Hola", "Hello");
    tree.insert("sol", "sun");
    tree.insert("inteligente", "smart");
    tree.insert("telefono", "phone");
    tree.insert("casa", "house");

    std::cout << "Elementos Insertados" << std::endl;

    std::cout << "\nInorder Tree" << std::endl;
    int i = 1;

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