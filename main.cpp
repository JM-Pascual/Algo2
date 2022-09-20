#include <fstream>
#include "biblioteca.hpp"

using namespace std;

int main(){
    cout<<"Bienvenido al sistema de organización de libros!"<<'\n';
    cout<<'\n';
    
    Biblioteca* biblioteca = new Biblioteca;
    biblioteca -> cantidad_libros_almacenados = 0;
    
    cargar_biblioteca(biblioteca);
    
    bool fin_de_ordenes = false;
    int comando;

    while (!fin_de_ordenes){
        cout<<"Las opciones son:"<<'\n'<<
        "1- Listar libros"<<'\n'<<
        "2- Agregar un libro"<<'\n'<<
        "3- Editar el puntaje de un libro"<<'\n'<<
        "4- Listar el/los libro/s mejor puntuados"<<'\n'<<
        "5- Listar los libros peor puntuados"<<'\n'<<
        "6- Listar género/s más leído/s"<<'\n'<<
        "7- Listar género/s mejor puntuado/s"<<'\n'<<
        "0- Guardar y salir del programa"<<'\n';
        cout<<"Introduzca la orden a ejecutar:";
        cin>>comando;
        ejecutar_ordenes(biblioteca, comando, fin_de_ordenes);
    }

    delete biblioteca;

    return 0;
}

//Permitirle al user agregar libros escribiendo el genero!