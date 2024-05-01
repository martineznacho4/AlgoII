#ifndef TABLAHASHABIERTA_H
#define TABLAHASHABIERTA_H

#include <string>
#include "NodoHash.h"

#define TAMANO_TABLA_HASH 67 // 50 aeropuertos a guardar por 0.74 (<0.8) de factor de carga aprox
using namespace std;

class TablaHashAbierta{
private:
    NodoHash tabla[TAMANO_TABLA_HASH];
    int cantidadAeropuertos;
    int hash(const string& clave);
public:
    //Pos:  Crea una tabla vacia
    TablaHashAbierta();

    //Pre: la tabla no esta llena
    //Pos:  Inserta un aeropuerto en la tabla. Devuelve true si se pudo insertar
    bool insertar(Aeropuerto& aeropuerto);


    //Pos:  Elimina un aeropuerto de la tabla por el nombre de la ciudad. Devuelve true si se eliminó
    bool eliminar(string& nombreCiudad);


    //Pos:  Busca un aeropuerto en la tabla por el nombre de la ciudad.
    // si lo encuentra devuelve el aeropuerto, si no es asi; uno vacio
    Aeropuerto buscar(string& nombreCiudad);
};

#endif
