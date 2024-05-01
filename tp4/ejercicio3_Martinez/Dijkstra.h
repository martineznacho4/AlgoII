#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H

#include "Lista.h"

const int INFINITO = 99999999;

class Dijkstra{
//Atributos
private:
    bool * verticesVisitados;
    int * distancia;
    int * recorrido;
    int * costo;

    int ** matrizAdyacencia;
    Lista<Aeropuerto> * vertices;
    int cantidadVertices;


//Métodos
    //post: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializarVisitados(int origen);

    //post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializarDistanciaCosto(const int * distanciaOrigen);

    //post: llena el vector de recorrido con el origen
    void inicializarRecorrido(int origen);

    //post: devuelve el número de vértice con menor distancia al origen
    int verticeMinimaDistancia();

    //post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizarDistancia(int vertice);

    //post: muestra por pantalla el resultado del recorrido.
    void mostrarRecorrido(int origen, int destino);

public:
    Dijkstra(Lista<Aeropuerto> * vertices, int ** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int origen, int destino);

    ~Dijkstra();

};


#endif //GRAFOS_DIJKSTRA_H
