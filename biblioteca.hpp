#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>

const std::string UBICACION_ARCHIVO = "libros.csv";

const std::string AVENTURA = "A";
const std::string CIENCIA_FICCION = "C";
const std::string DIDACTICO = "D";
const std::string POLICIAL = "P";
const std::string ROMANCE = "R";
const std::string TERROR = "T";


struct Libro {
    std::string nombre;
    std::string genero;
    int puntaje;
};


struct Biblioteca {
    Libro** vector_libros; //Puntero a puntero de un vector de libros en el heap.
    int cantidad_libros_almacenados;
};


//Pre:
//Post:
void cargar_biblioteca(Biblioteca* biblioteca);


//Pre:
//Post:
void enumerar_libros_cargados(Biblioteca* biblioteca);


//Pre:
//Post:
void cargar_nuevo_libro(Biblioteca* biblioteca);


//Pre:
//Post:
void editar_puntaje_libro(Biblioteca* biblioteca);


//Pre:
//Post:
void listar_libros_mejor_puntuados(Biblioteca* biblioteca);


#endif