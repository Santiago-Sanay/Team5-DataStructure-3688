cmake_minimum_required(VERSION 3.0.0)
project(ProrityQueue VERSION 0.1.0)


add_executable(ProrityQueue "main.cpp" "node.h" "doubly_linked_list.h")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
