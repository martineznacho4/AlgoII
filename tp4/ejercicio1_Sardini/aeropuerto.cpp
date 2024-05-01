#include "aeropuerto.h"


Aeropuerto::Aeropuerto(std::string clave, std::string nombre, std::string ciudad, std::string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales){
    this->clave = clave;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cantidad_terminales = cantidad_terminales;
    this->destinos_nacionales = destinos_nacionales;
    this->destinos_internacionales = destinos_internacionales;
}

Aeropuerto::Aeropuerto(){
    clave = "";
    nombre = "";
    ciudad = "";
    pais = "";
    superficie = 0;
    cantidad_terminales = 0;
    destinos_nacionales = 0;
    destinos_internacionales = 0;
}

Aeropuerto::~Aeropuerto(){};

std::string Aeropuerto::get_clave(){
    return clave;
}

std::string Aeropuerto::get_nombre(){
    return nombre;
}

std::string Aeropuerto::get_ciudad(){
    return ciudad;
}

std::string Aeropuerto::get_pais(){
    return pais;
}

double Aeropuerto::get_superficie(){
    return superficie;
}

int Aeropuerto::get_terminales(){
    return cantidad_terminales;
}

int Aeropuerto::get_dest_nacionales(){
    return destinos_nacionales;
}

int Aeropuerto::get_dest_internacionales(){
    return destinos_internacionales;
}

void Aeropuerto::imprimir_aeropuerto(){
    std::cout << "Datos del aeropuerto:\n" << "COD IATA: " << clave << std::endl << "NOMBRE: " << nombre << std::endl << 
    "CIUDAD: " << ciudad << std::endl << "PAIS: " << pais << std::endl << "SUPERFICIE: " << superficie << std::endl <<
    "CANTIDAD DE TERMINALES: " << cantidad_terminales << std::endl << "CANTIDAD DE DESTINOS NACIONALES: " << destinos_nacionales << std::endl <<
    "CANTIDAD DE DESTINOS INTERNACIONALES: " << destinos_internacionales << std::endl;
}
