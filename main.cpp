#include <fstream>
#include "biblioteca.hpp"

using namespace std;

int main(){
    cout<<"Bienvenido al sistema de organización de libros!"<<'\n';
    cout<<'\n';
    
    Biblioteca* biblioteca = new Biblioteca;
    biblioteca -> cantidad_libros_almacenados = 0;
    
    cargar_biblioteca(biblioteca);
    cargar_nuevo_libro(biblioteca);
    guardar_y_salir(biblioteca);

    delete biblioteca;

    return 0;
}

//NO ESTOY LIMPIANDO LOS LIBROS! ---> Ahora si pero checkear memory leaks
//Permitirle al user agregar libros escribiendo el genero!