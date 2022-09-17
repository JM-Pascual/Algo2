#include <fstream>
#include "biblioteca.hpp"

using namespace std;

int main(){
    cout<<"Bienvenido al sistema de organización de libros!"<<'\n';
    cout<<'\n';
    
    Biblioteca* biblioteca = new Biblioteca;
    biblioteca -> cantidad_libros_almacenados = 0;
    //cout<<biblioteca -> cantidad_libros_almacenados; ¿Se inicia en 0 automáticamente?
    
    cargar_biblioteca(biblioteca);
    genero_mejor_promedio(biblioteca);
    generos_mas_leidos(biblioteca);

    delete biblioteca;

    return 0;
}

//NO ESTOY LIMPIANDO LOS LIBROS!
//Permitirle al user agregar libros escribiendo el genero!