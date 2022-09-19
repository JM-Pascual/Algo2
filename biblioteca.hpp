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


const int TOPE_GENEROS = 6;
const int TOPE_PEOR_PUNTUADOS = 3;

const int INDEX_AVENTURA = 0;
const int INDEX_CIENCIA_FICCION = 1;
const int INDEX_DIDACTICO = 2;
const int INDEX_POLICIAL = 3;
const int INDEX_ROMANCE = 4;
const int INDEX_TERROR = 5;


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


//Pre:
//Post:
void generos_mas_leidos(Biblioteca* biblioteca);


//Pre:
//Post:
void genero_mejor_promedio(Biblioteca* biblioteca);

#endif