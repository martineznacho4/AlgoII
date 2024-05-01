#include <iostream>
#include "Dijkstra.h"
using namespace std;

Dijkstra::Dijkstra(Lista<Aeropuerto> *vertices, int **matrizAdyacencia){
    verticesVisitados = new bool[cantidadVertices];
    distancia = new int[cantidadVertices];
    recorrido = new int[cantidadVertices];
    costo = new int[cantidadVertices];

    this -> vertices = vertices;
    this -> matrizAdyacencia = matrizAdyacencia;
    this->cantidadVertices = vertices -> obtenerCantidadDeElementos();

}

void Dijkstra::caminoMinimo(int origen, int destino) {
    inicializarVisitados(origen);
    inicializarDistanciaCosto(matrizAdyacencia[origen]);
    inicializarRecorrido(origen);

    for (int i = 0; i < cantidadVertices; i++){
        int vertice = verticeMinimaDistancia();
        verticesVisitados[vertice] = true;
        actualizarDistancia(vertice);     
    }

    mostrarRecorrido(origen, destino);
}

int Dijkstra::verticeMinimaDistancia() {
    int minimaDistancia = INFINITO;
    int minimoVertice;

    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[i] <= minimaDistancia){
            minimaDistancia = distancia[i];
            minimoVertice = i;
        }
    }
    return minimoVertice;
}

void Dijkstra::actualizarDistancia(int vertice) {
    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[vertice] != INFINITO && distancia[i] > matrizAdyacencia[vertice][i] + distancia[vertice]){
            distancia[i] = matrizAdyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
            costo[i] = matrizAdyacencia[vertice][i];
        }
    }
}

void Dijkstra::inicializarVisitados(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        verticesVisitados[i] = false;
    verticesVisitados[origen] = true;
}
void Dijkstra::inicializarRecorrido(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        recorrido[i] = origen;
}
void Dijkstra::inicializarDistanciaCosto(const int * distanciaOrigen) {
    for(int i = 0; i < cantidadVertices; i++){
        distancia[i] = distanciaOrigen[i];
        costo[i] = distanciaOrigen[i];
    }
}

Dijkstra::~Dijkstra() {
    delete[] verticesVisitados;
    delete[] distancia;
    delete[] recorrido;
    delete[] costo;
}

void Dijkstra::mostrarRecorrido(int origen, int destino) {
    if(distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " 
        <<  vertices->obtenerNombre(origen + 1) << " - " << vertices->consulta(origen + 1).obtenerAeropuerto() 
        << " con " 
        << vertices->obtenerNombre(destino + 1) << " - " << vertices->consulta(destino + 1).obtenerAeropuerto();

    }else{
        cout << "El camino minimo que une " 
            <<  vertices->obtenerNombre(origen + 1) << " - " << vertices->consulta(origen + 1).obtenerAeropuerto()
            << " con " 
            << vertices->obtenerNombre(destino + 1) << " - " << vertices->consulta(destino + 1).obtenerAeropuerto();

        cout << " tiene un costo de: $" << distancia[destino] << " y es el siguiente: " << endl;

        do {
            int previo = recorrido[destino];
            cout << vertices->obtenerNombre(destino + 1) ; 
            cout << " (Costo: $" << costo[destino] << ")" << " <- ";
            destino = previo;
        } while(origen != destino);
        cout << vertices->obtenerNombre(origen + 1);
    }
    cout << endl;
}




