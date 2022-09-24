#include <iostream>
#include <stdlib.h>
#include <string>
#include "biblioteca.hpp"

using namespace std;

int main(){
    cout<<R"(
 ______    __   _______  __   __  ____    ____  _______  __   __   __   _______   ______    __  
|   _  \  |  | |   ____||  \ |  | \   \  /   / |   ____||  \ |  | |  | |       \ /  __  \  |  | 
|  |_)  | |  | |  |__   |   \|  |  \   \/   /  |  |__   |   \|  | |  | |  .--.  |  |  |  | |  | 
|   _  <  |  | |   __|  |  . `  |   \      /   |   __|  |  . `  | |  | |  |  |  |  |  |  | |  | 
|  |_)  | |  | |  |____ |  |\   |    \    /    |  |____ |  |\   | |  | |  '--'  |  `--'  | |__| 
|______/  |__| |_______||__| \__|     \__/     |_______||__| \__| |__| |_______/ \______/  (__)                                                                                            
    )"<<'\n';
    cout<<"Bienvenido al sistema de organización de libros!"<<'\n';
    cout<<"Este le permite realizar una serie de operaciones sobre los libros que cargue al sistema."<<'\n';
    cout<<"Presione cualquier tecla junto con ENTER para continuar"<<'\n';
    char cualquier_tecla;
    cin>>cualquier_tecla;
    system("clear");

    Biblioteca* biblioteca = new Biblioteca;
    biblioteca -> cantidad_libros_almacenados = 0;
    
    cargar_biblioteca(biblioteca);
    
    bool fin_de_ordenes = false;
    int comando;

    while (!fin_de_ordenes){
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
        system("clear");
        ejecutar_ordenes(biblioteca, comando, fin_de_ordenes);
    }

    delete biblioteca;

    return 0;
}