cmake_minimum_required(VERSION 3.17)
project(ParcoursGraphe)

set(CMAKE_CXX_STANDARD 17)

add_executable(ParcoursGraphe main.cpp Matrice.cpp Matrice.h Parcours.cpp Parcours.h Coloriage.cpp Coloriage.h)