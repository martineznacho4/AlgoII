#ifndef TABLAHASHCERRADA_H
#define TABLAHASHCERRADA_H

#include <string>
#include "NodoHash.h"

#define TAMANO_TABLA_HASH 67 // 50 aeropuertos a guardar por 0.74 (<0.8) de factor de carga aprox
using namespace std;

class TablaHashCerrada{
private:
    NodoHash tabla[TAMANO_TABLA_HASH];
    int cantidadAeropuertos;
    int hash(const string& clave);
public:
    //Pre
    //Pos: Crea una tabla vacía
    TablaHashCerrada();

    // PRE: La tabla no esta llena
    //Pos: Inserta un aeropuerto en la tabla. Devuelve true si se pudo insertar
    bool insertar(Aeropuerto& aeropuerto);

    //Pos: Elimina un aeropuerto de la tabla hash por el nombre de la ciudad. Devuelve true si se pudo eliminar
    bool eliminar(string& nombreCiudad);


    //Pos: Busca un aeropuerto en la tabla hash por el nombre de la ciudad.
    //Devuelve el aeropuerto o uno vacio si no lo encuentra
    Aeropuerto buscar(string& nombreCiudad);
};

#endif
