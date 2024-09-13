cmake_minimum_required(VERSION 3.27)
project(Proyecto_1DatosII)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

# Archivo de código fuente de tu proyecto
add_executable(Proyecto_1DatosII
        main.cpp
        MPointerGC.cpp
        MPointer.cpp
        DoubleLinkedList.cpp
        DoubleLinkedList.h
        Quicksort.h
        BubbleSort.h
        InsertionSort.h
        googletest/googletest/include/gtest/gtest.h
        PruebasUnitaria_Bubblesort.cpp
        PruebaUnitaria_Quicksort.cpp
        PruebaUnitaria_MPointer.cpp
        PruebaUnitaria_InsertionSort.cpp

)
set(CMAKE_CXX_STANDARD 22)

target_link_libraries(Proyecto_1DatosII gtest)


