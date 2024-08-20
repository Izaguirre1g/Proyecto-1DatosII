cmake_minimum_required(VERSION 3.27)
project(Proyecto_1DatosII)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_1DatosII main.cpp
        MPointer.cpp
        MPointer.h
        MPointerGC.cpp
        MPointerGC.h
)
