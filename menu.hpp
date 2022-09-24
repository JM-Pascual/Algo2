#ifndef MENU_HPP
#define MENU_HPP

#include "biblioteca.hpp"

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


//Pre: -
//Post: Pide al usuario que indique uno de los comandos disponibles.
int pedir_comandos(int &comando);


//Pre: El comando proporcionado por el usuario debe ser 1 solo y numérico. Múltiples carácteres por comando alteran el funcionamiento del programa.
//Post: Analiza el input del usuario y si corresponde a un comando válido ejecuta su instrucción. 
void ejecutar_ordenes(Biblioteca*, int comando, bool &fin_de_ordenes);

#endif