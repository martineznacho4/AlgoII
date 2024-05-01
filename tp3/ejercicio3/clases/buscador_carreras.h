#ifndef BUSCADOR_CARRERAS_H
#define BUSCADOR_CARRERAS_H

#include "lista.h"
#include "carrera.h"
using namespace std;

class Buscador_Carreras{
public:
    // Pre: -
    // Post: Busca en la "carreras" las que tienen tres o más materias de la lista de "materias predilectas" y duración menor o igual que la "duracion_maxima". 
    // Devuelve una Lista con las carreras que cumplen las condiciones
    Lista<Carrera*> sugerir_carreras(Lista<Carrera*>* carreras, int duracion_maxima, Lista<string>* materias_predilectas);

    // Pre: -
    // Post: Devuelve la cantidad de materias_predilectas que hay en una Carrera
    int materias_en_comun(Carrera* carrera, Lista<string>* materias_predilectas);

};

#endif
