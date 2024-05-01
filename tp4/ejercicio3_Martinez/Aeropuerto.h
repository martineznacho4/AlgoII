#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <string>
using namespace std;

class Aeropuerto {

private:
    string codigo_IATA, nombre_aeropuerto, ciudad, pais;

public:

    // Constructores
    Aeropuerto();
    Aeropuerto( string codigo_IATA, string nombre_aeropuerto, string ciudad, string pais);
    Aeropuerto(string codigo_IATA);

    // Destructor
    ~Aeropuerto();

    //post: Devuelve el codigo IATA del Aeropuerto
    string obtenerNombre();
    // Post: Devuelve el nombre del Aeropuerto
    string obtenerAeropuerto();
    // Post: Devuelve la ciudad del Aeropuerto
    string obtenerCiudad();
    // Post: Devuelve el pais del Aeropuerto
    string obtenerPais();

};


#endif //AEROPUERTO_H
