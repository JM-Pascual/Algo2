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


const std::string AVENTURA_MAY = "Aventura";
const std::string CIENCIA_FICCION_MAY = "Ciencia-ficcion";
const std::string DIDACTICO_MAY = "Didactico";
const std::string POLICIAL_MAY = "Policial";
const std::string ROMANCE_MAY = "Romance";
const std::string TERROR_MAY = "Terror";

const std::string AVENTURA_MIN = "aventura";
const std::string CIENCIA_FICCION_MIN = "ciencia-ficcion";
const std::string DIDACTICO_MIN = "didactico";
const std::string POLICIAL_MIN = "policial";
const std::string ROMANCE_MIN = "romance";
const std::string TERROR_MIN = "terror";


const int TOPE_GENEROS = 6;
const int TOPE_PEOR_PUNTUADOS = 3;


const int INDEX_AVENTURA = 0;
const int INDEX_CIENCIA_FICCION = 1;
const int INDEX_DIDACTICO = 2;
const int INDEX_POLICIAL = 3;
const int INDEX_ROMANCE = 4;
const int INDEX_TERROR = 5;


enum OpcionMenu {
    COMANDO_GUARDAR_Y_SALIR = 0,
    COMANDO_LISTAR_LIBROS,
    COMANDO_AGREGAR_LIBRO,
    COMANDO_EDITAR_PUNTAJE,
    COMANDO_LIBRO_FAVORITO,
    COMANDO_PEORES_PUNTAJES,
    COMANDO_GENERO_MAS_LEIDO,
    COMANDO_GENERO_FAVORITO
};

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


//Pre:
//Post:
void libros_con_menor_puntaje(Biblioteca* biblioteca);


//Pre:
//Post:
void guardar_y_salir(Biblioteca* biblioteca);


//Pre:
//Post:
void ejecutar_ordenes(Biblioteca*, int comando, bool &fin_de_ordenes);


#endif