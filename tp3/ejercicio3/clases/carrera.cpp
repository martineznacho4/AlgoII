#include "carrera.h"

using namespace std;
// Post: Crea una Carrera con el nombre, duración y lista de materias
Carrera::Carrera(string nombre, int duracion, Lista<string>* materias){
    this->nombre = nombre;
    this->duracion = duracion;
    this->materias = materias;
}

// Getters
string Carrera::obtener_nombre() {return nombre;}
int Carrera::obtener_duracion() {return duracion;}
Lista<string>* Carrera::obtener_materias() {return materias;}
