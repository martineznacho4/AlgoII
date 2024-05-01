#include <iostream>
#include "./clases/lista.h"
#include "./clases/carrera.h"
#include "./clases/buscador_carreras.h"
using namespace std;

int DUR_MAX = 5;

int main() {

    // Materias Predilectas
    Lista<string> materias_predilectas;
    materias_predilectas.alta("Analisis", 1);
    materias_predilectas.alta("Fisica", 2);
    materias_predilectas.alta("Algebra", 3);
    
    // -------------

    // Materias por Carrera
    Lista<string> materias_ingenieria;
    materias_ingenieria.alta("Analisis", 1);
    materias_ingenieria.alta("Algebra", 2);
    materias_ingenieria.alta("Algoritmos", 3);
    materias_ingenieria.alta("Fisica", 4);
    materias_ingenieria.alta("Logica", 5);

    Lista<string> materias_arquitectura;
    materias_arquitectura.alta("Fisica", 1);
    materias_arquitectura.alta("Analisis", 2);
    materias_arquitectura.alta("Algebra", 3);
    materias_arquitectura.alta("Fisica II", 4);

    Lista<string> materias_biologia;
    materias_biologia.alta("Quimica", 1);
    materias_biologia.alta("Fisica", 2);
    materias_biologia.alta("Microbiologia", 3);
    materias_biologia.alta("Genetica", 4);

    // -------------

    // Carreras
    Carrera ingenieria("Ingenieria", 5, &materias_ingenieria);
    Carrera arquitectura("Arquitectura", 5, &materias_arquitectura);
    Carrera biologia("Biologia", 5, &materias_biologia);

    Lista<Carrera*> carreras;
    carreras.alta(&ingenieria, 1);
    carreras.alta(&arquitectura, 2);
    carreras.alta(&biologia, 3);

    // -------------    

    Buscador_Carreras buscador;
    Lista<Carrera*> carreras_sugeridas = buscador.sugerir_carreras(&carreras, DUR_MAX, &materias_predilectas);

    cout << "Carreras sugeridas:" << endl;
    for (int i = 1; i <= carreras_sugeridas.obtener_cantidad(); i++) {
        Carrera* carrera = carreras_sugeridas.consulta(i);
        cout <<  carrera->obtener_nombre() << endl;
    }

    return 0;
}
