#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "Aeropuerto.h"
#include "Grafo.h"


// PRE: Existe un archivo fuente valido con el formato "IATA_origen aeropuerto_origen ciudad_origen pais_origen IATA_destino aeropuerto_destino ciudad_destino pais_destino costo"
// POS: Carga los datos del archivo fuente en el Grafo
void cargar_vuelos(Grafo &grafo);

// POS: Devuelve true si el aeropuerto ya se encuentra en el array de aeropuertos, false en caso contrario
bool buscar_aeropuerto(Aeropuerto aeropuerto);

// POS: Aumenta la capacidad del array de aeropuertos
void agrandar_aeropuertos(Aeropuerto* &array, int cantidad_aeropuertos);

// POS: Aumenta la capacidad del array de costos
void agrandar_costos();

#endif