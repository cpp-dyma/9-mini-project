cmake_minimum_required(VERSION 3.5.0)
project(9-mini-project VERSION 0.1.0 LANGUAGES C CXX)

add_executable(pierre-feuille-ciseaux src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
