#include <iostream>

#include "buscador_carreras.h"
using namespace std;

// Pre: -
// Post: Busca en la "carreras" las que tienen tres o más materias de la lista de "materias predilectas" y duración menor o igual que la "duracion_maxima".
// Devuelve una Lista con las carreras que cumplen las condiciones
Lista<Carrera *> Buscador_Carreras::sugerir_carreras(Lista<Carrera *> *carreras, int duracion_maxima, Lista<string> *materias_predilectas)
{

    Lista<Carrera *> aux;

    for (int i = 1; i <= carreras->obtener_cantidad(); i++)
    {
        Carrera *carrera = carreras->consulta(i);
        int cantidad_mat_comun = materias_en_comun(carrera, materias_predilectas);

        if (carrera->obtener_duracion() <= duracion_maxima && cantidad_mat_comun >= 3)
        {
            aux.alta(carrera, aux.obtener_cantidad() + 1);
        }
    }
    return aux;
}

int Buscador_Carreras::materias_en_comun(Carrera *carrera, Lista<string> *materias_predilectas)
{
    int cantidad = 0;

    for (int i = 1; i <= carrera->obtener_materias()->obtener_cantidad(); i++)
    {
        string materia_carrera = carrera->obtener_materias()->consulta(i);
        for (int j = 1; j <= materias_predilectas->obtener_cantidad(); j++)
        {
            string materia_predilecta = materias_predilectas->consulta(j);
            if (materia_carrera == materia_predilecta)
            {
                cantidad++;
            }
        }
    }
    return cantidad;
}
