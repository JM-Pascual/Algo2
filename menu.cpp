#include "biblioteca.hpp"
#include "menu.hpp"


using namespace std;


//Pre: -
//Post: Pide al usuario que indique uno de los comandos disponibles.
int pedir_comandos(int &comando){
    cout<<"Las opciones son:"<<'\n';
    cout<<'\n'<<"------------------------------------------------------"<<'\n'<<
    "1- Listar libros"<<'\n'<<
    "2- Agregar un libro"<<'\n'<<
    "3- Editar el puntaje de un libro"<<'\n'<<
    "4- Listar el/los libro/s mejor puntuados"<<'\n'<<
    "5- Listar los libros peor puntuados"<<'\n'<<
    "6- Listar género/s más leído/s"<<'\n'<<
    "7- Listar género/s mejor puntuado/s"<<'\n'<<
    "0- Guardar y salir del programa"<<'\n';
    cout<<"------------------------------------------------------"<<'\n';
    cout<<"Introduzca la orden a ejecutar: ";
    cin>>comando;
    return comando;
}


//Pre: El comando proporcionado por el usuario debe ser 1 solo y numérico. Múltiples carácteres por comando alteran el funcionamiento del programa.
//Post: Analiza el input del usuario y si corresponde a un comando válido ejecuta su instrucción. 
void ejecutar_ordenes(Biblioteca* biblioteca, int comando, bool &fin_de_ordenes){
    switch (comando){
    case (COMANDO_LISTAR_LIBROS):
        cout<<"Eligió enumerar los libros cargados en el sistema, estos son:"<<'\n'<<'\n';
        enumerar_libros_cargados(biblioteca);
        break;
    case (COMANDO_AGREGAR_LIBRO):
        cout<<"Eligió añadir un libro al sistema."<<'\n';
        cargar_nuevo_libro(biblioteca);
        break;
    case (COMANDO_EDITAR_PUNTAJE):
        cout<<"Eligió modificar el puntaje de un libro."<<'\n';
        editar_puntaje_libro(biblioteca);
        break;
    case (COMANDO_LIBRO_FAVORITO):
        cout<<"Eligió enumerar el libro (o libros, en caso de empate) con el mejor puntaje:"<<'\n';
        libros_mejor_puntuados(biblioteca);
        break;
    case (COMANDO_PEORES_PUNTAJES):
        cout<<"Eligió enumerar los "<<TOPE_PEOR_PUNTUADOS<<" libros con los peores puntajes, estos son:"<<'\n';
        libros_con_menor_puntaje(biblioteca);
        break;
    case (COMANDO_GENERO_MAS_LEIDO):
        cout<<"Eligió enumerar el género (o generos, en caso de empate) más leídos:"<<'\n';
        generos_mas_leidos(biblioteca);
        break;
    case (COMANDO_GENERO_FAVORITO):
        cout<<"Eligió enumerar el genero (o generos, en caso de empate) con mejor promedio de puntaje:"<<'\n';
        genero_mejor_promedio(biblioteca);
        break;
    case (COMANDO_GUARDAR_Y_SALIR):
        cout<<"Eligió guardar los cambios realizados y finalizar el programa."<<'\n';
        guardar_y_salir(biblioteca);
        cout<<"Gracias por utilizar el sistema de organización de libros!";
        fin_de_ordenes = true;
        break;
    default:
        cout<<"ERROR! Introduzca alguna de las opciones posibles"<<'\n';
        break;
    }
}