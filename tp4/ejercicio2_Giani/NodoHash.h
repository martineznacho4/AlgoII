#ifndef NODOHASH_H
#define NODOHASH_H

#include "Aeropuerto.h"

class NodoHash {
public:
    // Pos: Crea un nodo vacio y desocupado
    NodoHash();

    // Pre: El aeropuerto es valido
    // Pos: Determina el aeropuerto del nodo
    void setAeropuerto(Aeropuerto& aeropuerto);

    // Pre: existe el nodo
    // Pos: Devuelve el aeropuerto del nodo
    Aeropuerto getAeropuerto() const;

    // Pre: existe el nodo
    // Pos: Determina el estado del nodo
    void setOcupado(bool estaOcupado);

    // Pre: existe el nodo
    // Pos: Devuelve el estado del nodo
    bool getOcupado() const;
private:
    Aeropuerto aeropuerto;
    bool ocupado;
};

#endif
