cmake_minimum_required(VERSION 3.0.0)
project(AVL_Tree VERSION 0.1.0)


add_executable(AVL_Tree main.cpp avl_node.h avl_tree.h utils.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
