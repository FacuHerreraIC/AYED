cmake_minimum_required(VERSION 3.10)
project(AyED_Practica)

set(CMAKE_CXX_STANDARD 17)

# Lab de testing
add_executable(laboratorio 00_Laboratorio/pruebas_rapidas.cpp)
# Punteros
add_executable(punteros_basicos 01_Punteros/punteros_basicos.cpp)
add_executable(paso_parametros 01_Punteros/paso_parametros.cpp)
add_executable(memoria_dinamica 01_Punteros/memoria_dinamica.cpp)
add_executable(aritmetica_punteros 01_Punteros/aritmetica_punteros.cpp)
# OOP
add_executable(conceptos_basicos 02_OOP/conceptos_basicos.cpp)
add_executable(constructores 02_OOP/constructores.cpp)
add_executable(herencia 02_OOP/herencia.cpp)
# Estructuras
add_executable(cola 03_Estructuras/cola.cpp)
add_executable(lista 03_Estructuras/lista_enlazada.cpp)
add_executable(pila 03_Estructuras/pila.cpp)
# Complejidad Algoritmica
add_executable(complejidad 04_Complejidad/ejemplos_complejidad.cpp)
# Algoritmos De Ordenamiento
add_executable(ncuadrado 05_AlgoritmosDeOrdenamiento/ncuadrado.cpp)

