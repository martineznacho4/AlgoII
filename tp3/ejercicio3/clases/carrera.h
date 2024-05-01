#ifndef CARRERA_H
#define CARRERA_H

#include "lista.h"
#include <string>
using namespace std;

class Carrera {
private:
    string nombre;
    int duracion;
    Lista<string>* materias;

public:
    // Post: Crea una Carrera con el nombre, duración y lista de materias
    Carrera(string nombre, int duracion, Lista<string>* materias);

    // Getters
    string obtener_nombre();
    int obtener_duracion();
    Lista<string>* obtener_materias();

};

#endif
