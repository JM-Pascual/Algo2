#include <iostream>
#include <string>
#include <fstream>
#include "biblioteca.hpp"

using namespace std;

//Cambios en el arcivo

void cargar_libro(Biblioteca* biblioteca, Libro* libro){
    int tope_actual_libros = biblioteca -> cantidad_libros_almacenados;

    Libro** vector_ampliado_libros = new Libro*[tope_actual_libros +1]; //Crea un vector que tenga exactamente un espacio más que el anterior.

    for (int i = 0; i < tope_actual_libros; i++){ //Carga el contenido del vector de menor tamaño al ampliado por 1 espacio.
        vector_ampliado_libros[i] = biblioteca -> vector_libros[i];
    }

    vector_ampliado_libros[tope_actual_libros] = libro;

    if (tope_actual_libros != 0){ //Me aseguro de no hacer delete si solo cree el primer libro.
        delete[] biblioteca -> vector_libros;
    }

    biblioteca -> vector_libros = vector_ampliado_libros; //El puntero dentro del struct ahora apunta al recién creado vector ampliado.
    biblioteca -> cantidad_libros_almacenados++;
}


void cargar_biblioteca(Biblioteca* biblioteca){

    fstream archivo(UBICACION_ARCHIVO, ios::in);

    if (!(archivo.is_open())){
        cout<<"No se encontró el archivo de almacenamiento. Se procederá a crear uno"<<'\n';
        archivo.open(UBICACION_ARCHIVO, ios::out);
        archivo.close();
        archivo.open(UBICACION_ARCHIVO, ios::in);
    }

    string nombre, genero, puntaje;

    while(getline(archivo, nombre, ',')){
        getline(archivo, genero, ',');
        getline(archivo, puntaje);

        Libro* libro = new Libro;
        
        libro -> nombre = nombre;
        libro -> genero = genero;
        libro -> puntaje = stoi(puntaje); 

        cargar_libro(biblioteca, libro);
    }

    archivo.close();
}


void enumerar_libros_cargados(Biblioteca* biblioteca){
    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    for (int i = 0; i < tope_libros; i++){
        cout<<biblioteca -> vector_libros[i] -> nombre<<" | "<<biblioteca -> vector_libros[i] -> puntaje<<'\n';
        cout<<"-----------------------------------------------"<<'\n';
    }
}


bool libro_existe(Biblioteca* biblioteca, string nombre_libro_nuevo){
    bool libro_repetido = false;
    
    int tope_libros = biblioteca -> cantidad_libros_almacenados;
    int i = 0;

    while (!libro_repetido && i < tope_libros){
        if (biblioteca -> vector_libros[i]->nombre == nombre_libro_nuevo){
            cout<<"Error! El libro ya está cargado. Intente nuevamente";
            libro_repetido = true;
        }
        i++;
    }

    return libro_repetido;
}


bool libro_existe_puntaje(Biblioteca* biblioteca, string nombre_libro_nuevo, int &index_libro){
    bool libro_existe = false;
    
    int tope_libros = biblioteca -> cantidad_libros_almacenados;
    int i = 0;

    while (!libro_existe && i < tope_libros){
        if (biblioteca -> vector_libros[i]->nombre == nombre_libro_nuevo){
            index_libro = i;
            libro_existe = true;
        }
        i++;
    }

    return libro_existe;
}


bool genero_valido(string genero_ingresado){
    bool genero_correcto = false;

    if (genero_ingresado == AVENTURA ||
        genero_ingresado == CIENCIA_FICCION ||
        genero_ingresado == DIDACTICO ||
        genero_ingresado == POLICIAL ||
        genero_ingresado == ROMANCE ||
        genero_ingresado == TERROR){

            genero_correcto = true;
    }

    else{
        cout<<"Error! Ese no es un genero válido!";
    }

    return genero_correcto;
}


void definir_genero(string &genero_libro_nuevo){
    cin>>genero_libro_nuevo;
    while(!(genero_valido(genero_libro_nuevo))){
        cin>>genero_libro_nuevo;
    }
}


int definir_puntaje(){
    int puntaje;
    cout<<"Introduzca su puntaje a continuación: ";
    cin>>puntaje;
    cout<<'\n';

    while (puntaje < -1 || puntaje > 11) {
        cout<<"Error! Ingrese un puntaje válido entre 0 y 10"<<'\n';
        cin>>puntaje;
    }
    
    return puntaje;
}


void completar_datos_libro(Biblioteca* biblioteca, Libro* libro_nuevo){
    cout<<"Introduzca el nombre del libro nombre a continuación: "<<'\n';
    string nombre_libro_nuevo;
    cin>>nombre_libro_nuevo;

    if(!(libro_existe(biblioteca, nombre_libro_nuevo))){
        cout<<"Introduzca el género del libro continuación: "<<'\n';
        cout<<"Los genéros posibles son:"<<'\n';
        cout<<'\n';
        cout<<"Aventura --> introducir A"<<'\n'<<"Ciencia ficción --> introducir C"<<'\n';
        cout<<"Didáctico --> introducir D"<<'\n'<<"Policial --> introducir P"<<'\n';
        cout<<"Romance --> introducir R"<<'\n'<<"Terror --> introducir T"<<'\n'; 
        string genero_libro_nuevo;
        definir_genero(genero_libro_nuevo);

        int puntaje_libro_nuevo = definir_puntaje();

        libro_nuevo -> nombre = nombre_libro_nuevo;
        libro_nuevo -> genero = genero_libro_nuevo;
        libro_nuevo -> puntaje = puntaje_libro_nuevo;
    }
    
    else{
        cout<<"Error! El libro ingresado ya se encuentra en el listado."<<'\n';
        cout<<"Intente una opción distinta desde el menú."<<'\n';
    }
}


void cargar_nuevo_libro(Biblioteca* biblioteca){
    cout<<"Elegió cargar un nuevo libro."<<'\n'; 
    cout<<"Para completar el cargado del libro debe indicar su nombre, género y puntaje"<<'\n';
    
    Libro* libro_nuevo = new Libro;
    completar_datos_libro(biblioteca, libro_nuevo);
    cargar_libro(biblioteca, libro_nuevo);
}


void editar_puntaje_libro(Biblioteca* biblioteca){
    cout<<"Selecciono el modificar el puntaje de un libro."<<'\n';
    
    int index_libro = 0;
    string libro_a_modificar;
    cout<<"Indique el nombre del libro que desea modificar:";
    cin>>libro_a_modificar;

    if (libro_existe_puntaje(biblioteca, libro_a_modificar, index_libro)){
        cout<<"Se modificará la puntuación del libro: "<<libro_a_modificar<<'\n';
        int puntaje_nuevo = definir_puntaje();
        biblioteca -> vector_libros[index_libro] -> puntaje = puntaje_nuevo;
    }

    else{
        cout<<"El libro ingresado no está presente"<<'\n';
        cout<<"Intente una opción distinta desde el menú."<<'\n';
    }
}


void cargar_ranking(Biblioteca* biblioteca, Biblioteca* ranking, 
        int tope_libros, int &tope_ranking, int puntaje_ganador){
    
    for(int i = 0; i < tope_libros; i++){
        if (biblioteca -> vector_libros[i] -> puntaje >= puntaje_ganador){
            puntaje_ganador = biblioteca -> vector_libros[i] -> puntaje;

            Libro* libro_ganador = new Libro;

            libro_ganador -> nombre = biblioteca -> vector_libros[i] -> nombre;
            libro_ganador -> genero = biblioteca -> vector_libros[i] -> genero;
            libro_ganador -> puntaje = biblioteca -> vector_libros[i] -> puntaje;

            cargar_libro(ranking, libro_ganador);
            tope_ranking++;
        }
    }
}


void listar_libros_mejor_puntuados(Biblioteca* biblioteca){
    Biblioteca* ranking = new Biblioteca;

    int tope_libros = biblioteca -> cantidad_libros_almacenados;
    int tope_ranking = 0;

    int puntaje_ganador = 0;

    cargar_ranking(biblioteca, ranking, tope_libros, tope_ranking, puntaje_ganador);

    for (int j = 0; j < tope_ranking; j++){
        if (ranking -> vector_libros[j] -> puntaje == puntaje_ganador){
            cout<<"- "<<ranking -> vector_libros[j] -> nombre<<'\n';
        }

        delete ranking -> vector_libros[j]; //Borro los libros una vez los haya listado o no.
    }

    delete ranking;
}