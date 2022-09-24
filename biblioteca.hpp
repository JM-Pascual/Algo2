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
const std::string CIENCIA_FICCION_MAY = "Ciencia ficcion";
const std::string DIDACTICO_MAY = "Didactico";
const std::string POLICIAL_MAY = "Policial";
const std::string ROMANCE_MAY = "Romance";
const std::string TERROR_MAY = "Terror";

const std::string AVENTURA_MIN = "aventura";
const std::string CIENCIA_FICCION_MIN = "ciencia ficcion";
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


//Pre: -
//Post: Carga el vector dinámico inicial con los datos presentes en el csv al inicializar el programa.
//      De no encontrarse, creara uno.
void cargar_biblioteca(Biblioteca* biblioteca);


//Pre: -
//Post: Muestra por pantalla los libros cargados en el vector dinámico de Libros y su información.
void enumerar_libros_cargados(Biblioteca* biblioteca);


//Pre: - 
//Post: Pide al usuario la información de un nuevo libro el cual luego se cargará en el vector de Libros.
void cargar_nuevo_libro(Biblioteca* biblioteca);


//Pre: -
//Post: Pide al usuario el nombre de un libro, y de encontrarse presente en el vector permite modificar su puntaje.
void editar_puntaje_libro(Biblioteca* biblioteca);


//Pre: -
//Post: Muestra por pantalla todos los libros que tengan el puntaje más alto entre los demás dentro del vector.
void listar_libros_mejor_puntuados(Biblioteca* biblioteca);


//Pre: -
//Post: Muestra por pantalla los o el género más repetido dentro de los libros presentes en el vector de Libros.
void generos_mas_leidos(Biblioteca* biblioteca);


//Pre: -
//Post: Muestra por pantalla el género con el mejor promedio de puntuaciones ofrecidas por el usuario.
void genero_mejor_promedio(Biblioteca* biblioteca);


//Pre: -
//Post: Muestra por pantalla los 3 libros con el puntaje más bajo (Desempatando por orden alfabético en caso de empate).
void libros_con_menor_puntaje(Biblioteca* biblioteca);


//Pre: -
//Post: Guarda los libros presentes en el vector de Libros en un csv que sobreescribe al preexistente con los cambios realizados.
void guardar_y_salir(Biblioteca* biblioteca);


//Pre: El comando proporcionado por el usuario debe ser 1 solo y numérico. Múltiples carácteres por comando alteran el funcionamiento del programa.
//Post: Analiza el input del usuario y si corresponde a un comando válido ejecuta su instrucción. 
void ejecutar_ordenes(Biblioteca*, int comando, bool &fin_de_ordenes);


#endif