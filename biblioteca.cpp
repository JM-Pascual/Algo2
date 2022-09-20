#include <iostream>
#include <string>
#include <fstream>
#include "biblioteca.hpp"

using namespace std;


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

    if (genero_ingresado == AVENTURA_MAY ||
        genero_ingresado == AVENTURA_MIN ||
        genero_ingresado == CIENCIA_FICCION_MAY ||
        genero_ingresado == CIENCIA_FICCION_MIN ||
        genero_ingresado == DIDACTICO_MAY ||
        genero_ingresado == DIDACTICO_MIN ||
        genero_ingresado == POLICIAL_MAY ||
        genero_ingresado == POLICIAL_MIN ||
        genero_ingresado == ROMANCE_MAY ||
        genero_ingresado == ROMANCE_MIN ||
        genero_ingresado == TERROR_MAY ||
        genero_ingresado == TERROR_MIN){

            genero_correcto = true;
    }

    else{
        cout<<"Error! Ese no es un genero válido!";
    }

    return genero_correcto;
}


void format_genero(string &genero_libro_nuevo){
    if (genero_libro_nuevo == AVENTURA_MAY ||
        genero_libro_nuevo == AVENTURA_MIN){
            genero_libro_nuevo = AVENTURA;
        }
    else if (genero_libro_nuevo == CIENCIA_FICCION_MAY || 
        genero_libro_nuevo == CIENCIA_FICCION_MIN){
            genero_libro_nuevo = CIENCIA_FICCION;
        }
    else if (genero_libro_nuevo == DIDACTICO_MAY ||
        genero_libro_nuevo == DIDACTICO_MIN){
            genero_libro_nuevo = DIDACTICO;
        }
    else if (genero_libro_nuevo == POLICIAL_MAY ||
        genero_libro_nuevo == POLICIAL_MIN){
            genero_libro_nuevo = POLICIAL;
        }
    else if (genero_libro_nuevo == ROMANCE_MAY ||
        genero_libro_nuevo == ROMANCE_MIN){
            genero_libro_nuevo = ROMANCE;
        }
    else{ //Debido a que ya se valido el género, la única opción que queda es Terror.
        genero_libro_nuevo = TERROR;
    }
}


void definir_genero(string &genero_libro_nuevo){
    cin>>genero_libro_nuevo;
    while(!(genero_valido(genero_libro_nuevo))){
        cin>>genero_libro_nuevo;
    }
    format_genero(genero_libro_nuevo);
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


void completar_datos_libro(Biblioteca* biblioteca, Libro* libro_nuevo, bool &libro_valido){
    cout<<"Introduzca el nombre del libro nombre a continuación: "<<'\n';
    string nombre_libro_nuevo;
    cin>>nombre_libro_nuevo;

    if(!(libro_existe(biblioteca, nombre_libro_nuevo))){
        cout<<"Introduzca el género del libro continuación: "<<'\n';
        cout<<"Los genéros posibles (junto con como los registra el sistema) son:"<<'\n';
        cout<<'\n';
        cout<<"- Aventura"<<'\n'<<"- Ciencia-ficcion"<<'\n';
        cout<<"- Didáctico"<<'\n'<<"- Policial"<<'\n';
        cout<<"- Romance"<<'\n'<<"- Terror"<<'\n'; 
        string genero_libro_nuevo;
        definir_genero(genero_libro_nuevo);

        int puntaje_libro_nuevo = definir_puntaje();

        libro_nuevo -> nombre = nombre_libro_nuevo;
        libro_nuevo -> genero = genero_libro_nuevo;
        libro_nuevo -> puntaje = puntaje_libro_nuevo;

        libro_valido = true;
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
    bool libro_valido = false;

    completar_datos_libro(biblioteca, libro_nuevo, libro_valido);

    if (libro_valido){
        cargar_libro(biblioteca, libro_nuevo);
    }
    else{
        delete libro_nuevo;
    }
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
        int tope_libros, int &puntaje_ganador){
    
    for(int i = 0; i < tope_libros; i++){
        if (biblioteca -> vector_libros[i] -> puntaje >= puntaje_ganador){
            puntaje_ganador = biblioteca -> vector_libros[i] -> puntaje;

            Libro* libro_ganador = new Libro;

            libro_ganador -> nombre = biblioteca -> vector_libros[i] -> nombre;
            libro_ganador -> genero = biblioteca -> vector_libros[i] -> genero;
            libro_ganador -> puntaje = biblioteca -> vector_libros[i] -> puntaje;

            cargar_libro(ranking, libro_ganador);
        }
    }
}


void listar_libros_mejor_puntuados(Biblioteca* biblioteca){
    Biblioteca* ranking = new Biblioteca;
    ranking -> cantidad_libros_almacenados = 0;

    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    int puntaje_ganador = 0;

    cargar_ranking(biblioteca, ranking, tope_libros, puntaje_ganador);
    int tope_ranking = ranking -> cantidad_libros_almacenados;

    cout<<"Mostrando los mejores libro/s, con un puntaje de: "<<puntaje_ganador<<'\n';
    for (int j = 0; j < tope_ranking; j++){
        if (ranking -> vector_libros[j] -> puntaje == puntaje_ganador){
            cout<<"- "<<ranking -> vector_libros[j] -> nombre<<'\n';

            ranking -> cantidad_libros_almacenados--;
            delete ranking -> vector_libros[j]; //Borro los libros una vez los haya listado o no.
        }

    }
    
    delete[] ranking -> vector_libros; 
    ranking -> vector_libros = nullptr;
    delete ranking;
}


void cargar_vector_contadores(Biblioteca* biblioteca, int tope_libros, int vector_contadores[]){
    int contador_aventura = 0, contador_ciencia_ficcion = 0, contador_didactico = 0, 
        contador_policial = 0, contador_romance = 0, contador_terror = 0;

    for (int i = 0; i < tope_libros; i++){
        string genero = biblioteca -> vector_libros[i] -> genero;
        if (genero == AVENTURA){
            contador_aventura++;
        }
        else if (genero == CIENCIA_FICCION){
            contador_ciencia_ficcion++;
        }
        else if (genero == DIDACTICO){
            contador_didactico++;
        }
        else if (genero == POLICIAL){
            contador_policial++;
        }
        else if (genero == ROMANCE){
            contador_romance++;
        }
        else if (genero == TERROR){
            contador_terror++;
        }
    }
    vector_contadores[INDEX_AVENTURA] = contador_aventura;
    vector_contadores[INDEX_CIENCIA_FICCION] = contador_ciencia_ficcion;
    vector_contadores[INDEX_DIDACTICO] = contador_didactico;
    vector_contadores[INDEX_POLICIAL] = contador_policial;
    vector_contadores[INDEX_ROMANCE] = contador_romance;
    vector_contadores[INDEX_TERROR] = contador_terror;
}


void imprimir_genero_ganador(int index){
    switch (index) {
    case (INDEX_AVENTURA):
        cout<<"- Aventura"<<'\n';
        break;
    case (INDEX_CIENCIA_FICCION):
        cout<<"- Ciencia Ficción"<<'\n';
        break;
    case (INDEX_DIDACTICO):
        cout<<"- Didactico"<<'\n';
        break;
    case (INDEX_POLICIAL):
        cout<<"- Policial"<<'\n';
        break;
    case (INDEX_ROMANCE):
        cout<<"- Romance"<<'\n';
        break;
    case (INDEX_TERROR):
        cout<<"- Terror"<<'\n';
        break;
    default:
        cout<<"Todo mal";
        break;
    }
}


void generos_mas_leidos(Biblioteca* biblioteca){
    int tope_libros = biblioteca -> cantidad_libros_almacenados;
    
    int vector_contadores[TOPE_GENEROS];
    
    cargar_vector_contadores(biblioteca, tope_libros, vector_contadores);
    
    int contador_mas_alto = 0;
    for (int i = 0; i < TOPE_GENEROS; i++){
        if (contador_mas_alto < vector_contadores[i]){
            contador_mas_alto = vector_contadores[i];
        }
    }

    for (int i = 0; i < TOPE_GENEROS; i++){
        if (vector_contadores[i] == contador_mas_alto){
            imprimir_genero_ganador(i);
        }
    }
}


void cargar_promedios(Biblioteca* biblioteca, int tope_libros, float vector_promedios[]){
    int contador_aventura = 0, contador_ciencia_ficcion = 0, contador_didactico = 0, 
        contador_policial = 0, contador_romance = 0, contador_terror = 0;

    int puntajes_aventura = 0, puntajes_ciencia_ficcion = 0, puntajes_didactico = 0, 
        puntajes_policial = 0, puntajes_romance = 0, puntajes_terror = 0;

    for (int i = 0; i < tope_libros; i++){
        string genero = biblioteca -> vector_libros[i] -> genero;
        int puntaje = biblioteca -> vector_libros[i] -> puntaje;
        if (genero == AVENTURA){
            puntajes_aventura += puntaje;
            contador_aventura++;
        }
        else if (genero == CIENCIA_FICCION){
            puntajes_ciencia_ficcion += puntaje;
            contador_ciencia_ficcion++;
        }
        else if (genero == DIDACTICO){
            puntajes_didactico += puntaje;
            contador_didactico++;
        }
        else if (genero == POLICIAL){
            puntajes_policial += puntaje;
            contador_policial++;
        }
        else if (genero == ROMANCE){
            puntajes_romance += puntaje;
            contador_romance++;
        }
        else if (genero == TERROR){
            puntajes_terror += puntaje;
            contador_terror++;
        }
    }
    vector_promedios[INDEX_AVENTURA] = (float)puntajes_aventura / (float)contador_aventura;
    vector_promedios[INDEX_CIENCIA_FICCION] = (float)puntajes_ciencia_ficcion / (float)contador_ciencia_ficcion;
    vector_promedios[INDEX_DIDACTICO] = (float)puntajes_didactico / (float)contador_didactico;
    vector_promedios[INDEX_POLICIAL] = (float)puntajes_policial / (float)contador_policial;
    vector_promedios[INDEX_ROMANCE] = (float)puntajes_romance / (float)contador_romance;
    vector_promedios[INDEX_TERROR] = (float)puntajes_terror / (float)contador_terror;
}


void genero_mejor_promedio(Biblioteca* biblioteca){
    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    float vector_promedios[TOPE_GENEROS];

    cargar_promedios(biblioteca, tope_libros, vector_promedios);

    float promedio_mas_alto = 0.0;
    for (int i = 0; i < TOPE_GENEROS; i++){
        if (promedio_mas_alto < vector_promedios[i]){
            promedio_mas_alto = vector_promedios[i];
        }
    }

    for (int i = 0; i < TOPE_GENEROS; i++){
        if (vector_promedios[i] == promedio_mas_alto){
            imprimir_genero_ganador(i);
        }
    }
}


void ordenar_libros_por_nombre(Biblioteca* biblioteca, int tope_libros){
    Libro* libro_auxiliar;
    int j;

    for (int i = 1; i < tope_libros; i++) {
        j=i;
        libro_auxiliar = biblioteca -> vector_libros[i];

        while (j > 0 && libro_auxiliar -> puntaje == biblioteca -> vector_libros[j-1] -> puntaje 
        && (libro_auxiliar -> nombre).compare(biblioteca -> vector_libros[j-1] -> nombre) < 0){
            biblioteca -> vector_libros[j] = biblioteca -> vector_libros[j-1];
            j--;
        }
        biblioteca -> vector_libros[j] = libro_auxiliar;
    }
}


void ordenar_libros_por_puntaje(Biblioteca* biblioteca, int tope_libros){
    Libro* libro_auxiliar;
    int j;

    for (int i = 1; i < tope_libros; i++) {
        j=i;
        libro_auxiliar = biblioteca -> vector_libros[i];

        while (j > 0 && libro_auxiliar -> puntaje <= biblioteca -> vector_libros[j-1] -> puntaje){
            biblioteca -> vector_libros[j] = biblioteca -> vector_libros[j-1];
            j--;
        }
        biblioteca -> vector_libros[j] = libro_auxiliar;
    }
}


void imprimir_libros_peor_puntuados(Biblioteca* biblioteca){
    for (int i = 0; i <  TOPE_PEOR_PUNTUADOS; i++){
        cout<<"- "<<biblioteca -> vector_libros[i] -> nombre<<" // Puntaje: "<<biblioteca -> vector_libros[i] -> puntaje<<'\n';
    }
}


void libros_con_menor_puntaje(Biblioteca* biblioteca){
    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    ordenar_libros_por_puntaje(biblioteca, tope_libros);

    ordenar_libros_por_nombre(biblioteca, tope_libros);

    imprimir_libros_peor_puntuados(biblioteca);
}


void sobreescribir_archivo(Biblioteca* biblioteca){
    fstream archivo(UBICACION_ARCHIVO, ios::out);
    
    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    for(int i = 0; i < tope_libros; i++){
        Libro* libro_a_cargar = biblioteca -> vector_libros[i];  
        archivo<<libro_a_cargar -> nombre<<','<<libro_a_cargar -> genero<<','<<libro_a_cargar -> puntaje<<'\n';
    }
}


void borrar_biblioteca(Biblioteca* biblioteca){
    int tope_libros = biblioteca -> cantidad_libros_almacenados;

    for(int i = 0; i < tope_libros; i++){
        delete biblioteca -> vector_libros[i];
        biblioteca -> cantidad_libros_almacenados--;
    }

    delete[] biblioteca -> vector_libros;
    biblioteca -> vector_libros = nullptr;
}


void guardar_y_salir(Biblioteca* biblioteca){
    sobreescribir_archivo(biblioteca);

    borrar_biblioteca(biblioteca);
}


void ejecutar_ordenes(Biblioteca* biblioteca, int comando, bool &fin_de_ordenes){
    switch (comando){
    case (COMANDO_LISTAR_LIBROS):
        cout<<"Eligió enumerar los libros cargados en el sistema, estos son:"<<'\n';
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
        cout<<"Eligió enumerar el/los libro/s con el mejor puntaje:"<<'\n';
        listar_libros_mejor_puntuados(biblioteca);
        break;
    case (COMANDO_PEORES_PUNTAJES):
        cout<<"Eligió enumerar los "<<TOPE_PEOR_PUNTUADOS<<" libros con los peores puntajes, estos son:"<<'\n';
        libros_con_menor_puntaje(biblioteca);
        break;
    case (COMANDO_GENERO_MAS_LEIDO):
        cout<<"Eligió enumerar el/los género/s más leídos:"<<'\n';
        generos_mas_leidos(biblioteca);
        break;
    case (COMANDO_GENERO_FAVORITO):
        cout<<"Eligió enumerar el/los genero/s con mejor promedio de puntaje:"<<'\n';
        genero_mejor_promedio(biblioteca);
        break;
    case (COMANDO_GUARDAR_Y_SALIR):
        cout<<"Eligió guardar los cambios realizados y finalizar el programa."<<'\n';
        guardar_y_salir(biblioteca);
        fin_de_ordenes = true;
        break;
    default:
        cout<<"ERROR! Introduzca alguna de las opciones posibles"<<'\n';
        break;
    }
}