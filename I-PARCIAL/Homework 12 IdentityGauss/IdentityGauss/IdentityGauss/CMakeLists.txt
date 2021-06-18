cmake_minimum_required(VERSION 3.20)
project(IdentityGauss VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(IdentityGauss main.cpp Matrix.h MatrixMath.h Utils.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
