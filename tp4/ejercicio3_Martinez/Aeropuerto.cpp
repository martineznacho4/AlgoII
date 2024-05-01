#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(){}; // Constructor por defecto

Aeropuerto::Aeropuerto(string codigo_IATA) {
    this -> codigo_IATA = codigo_IATA;
};

Aeropuerto::Aeropuerto(string codigo_IATA, string nombre_aeropuerto, string ciudad, string pais) {
    this -> codigo_IATA = codigo_IATA;
    this -> nombre_aeropuerto = nombre_aeropuerto;
    this -> ciudad = ciudad;
    this -> pais = pais;
};

Aeropuerto::~Aeropuerto() {}

// Getters
string Aeropuerto::obtenerNombre(){return this->codigo_IATA;}
string Aeropuerto::obtenerAeropuerto(){return this->nombre_aeropuerto;}
string Aeropuerto::obtenerCiudad(){return this->ciudad;}
string Aeropuerto::obtenerPais(){return this->pais;}
