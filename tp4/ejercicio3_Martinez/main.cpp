#include <iostream>
#include "Grafo.h"
#include "Archivos.h"

int main() {

    Grafo grafo;

    cargar_vuelos(grafo);

    cout << "Ingrese el codigo IATA del aeropuerto de origen: " << endl;
    string origen_IATA;
    cin >> origen_IATA;
    Aeropuerto origen = Aeropuerto(origen_IATA);
    
    cout << "Ingrese el codigo IATA del aeropuerto de destino: " << endl;
    string destino_IATA;
    cin >> destino_IATA;
    Aeropuerto destino = Aeropuerto(destino_IATA);

    grafo.caminoMinimo(origen, destino);

    return 0;
}
