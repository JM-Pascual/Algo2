#include <fstream>
#include "biblioteca.hpp"

using namespace std;

int main(){
    cout<<"Bienvenido al sistema de organización de libros!"<<'\n';
    cout<<'\n';
    
    Biblioteca* biblioteca = new Biblioteca;
    //cout<<biblioteca -> cantidad_libros_almacenados; ¿Se inicia en 0 automáticamente?
    
    cargar_biblioteca(biblioteca); 
    enumerar_libros_cargados(biblioteca);
    listar_libros_mejor_puntuados(biblioteca);

    delete biblioteca;

    return 0;
}

//NO ESTOY LIMPIANDO LOS CONTACTOS!