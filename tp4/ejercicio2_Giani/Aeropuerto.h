#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <string>
using namespace std;

class Aeropuerto {
public:
    // Pre: Los parametros indicados son correctos
    // pos: crea un aeropuerto con los atributos indicados
    Aeropuerto(const string& codigoIATA, const string& nombre, const string& ciudad, const string& pais, float superficie, int cantidadTerminales, int destinosNacionales, int destinosInternacionales);

    // pre: existe el aeropuerto
    // pos: devuelve  el codigo IATA del aeropuerto
    string getCodigoIATA();

    // pre: existe el aeropuerto
    // pos: devuelve  el nombre del aeropuerto
    string getNombre();

    // pre: existe el aeropuerto
    // pos: devuelve  la ciudad del aeropuerto
    string getCiudad();

    // pre: existe el aeropuerto
    // pos: devuelve  el país del aeropuerto
    string getPais();

    // pre: existe el aeropuerto
    // pos: devuelve  la superficie del aeropuerto
    float getSuperficie();

    // pre: existe el aeropuerto
    // pos: devuelve  la cantidad de terminales del aeropuerto
    int getCantidadTerminales();

    // pre: existe el aeropuerto
    // pos: devuelve  la cantidad de destinos nacionales del aeropuerto
    int getDestinosNacionales();

    // pre: existe el aeropuerto
    // pos: devuelve  la cantidad de destinos internacionales del aeropuerto
    int getDestinosInternacionales();
private:
    string codigoIATA;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;
};

#endif
