#include "Aeropuerto.h"

using namespace std;
Aeropuerto::Aeropuerto(const string& codigoIATA, const string& nombre, const string& ciudad, const string& pais, float superficie, int cantidadTerminales, int destinosNacionales, int destinosInternacionales) : codigoIATA(codigoIATA), nombre(nombre), ciudad(ciudad), pais(pais), superficie(superficie), cantidadTerminales(cantidadTerminales), destinosNacionales(destinosNacionales), destinosInternacionales(destinosInternacionales){}
string Aeropuerto::getCodigoIATA(){
    return codigoIATA;
}
string Aeropuerto::getNombre(){
    return nombre;
}
string Aeropuerto::getCiudad(){
    return ciudad;
}
string Aeropuerto::getPais(){
    return pais;
}
float Aeropuerto::getSuperficie(){
    return superficie;
}
int Aeropuerto::getCantidadTerminales(){
    return cantidadTerminales;
}
int Aeropuerto::getDestinosNacionales(){
    return destinosNacionales;
}
int Aeropuerto::getDestinosInternacionales(){
    return destinosInternacionales;
}