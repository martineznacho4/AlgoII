#include <fstream>
#include "Archivos.h"
#include <iostream>



using namespace std;

const string VUELOS = "vuelos.txt";


Aeropuerto * aeropuertos = new Aeropuerto[1];
Aeropuerto * aeropuertos_origen = new Aeropuerto[1];
Aeropuerto * aeropuertos_destino = new Aeropuerto[1];
int * costos = new int[1];
int cantidad_aeropuertos = 0;
int cantidad_vuelos = 0;


void cargar_vuelos(Grafo &grafo){

    ifstream archivo_vuelos(VUELOS);

    string IATA_origen, aeropuerto_origen, ciudad_origen, pais_origen, IATA_destino, aeropuerto_destino, ciudad_destino, pais_destino;
    int costo;

    
    while(archivo_vuelos >> IATA_origen >> aeropuerto_origen >> ciudad_origen >> pais_origen >> IATA_destino >> aeropuerto_destino >> ciudad_destino >> pais_destino >> costo){
        
        Aeropuerto origen = Aeropuerto( IATA_origen, aeropuerto_origen, ciudad_origen, pais_origen);
        Aeropuerto destino = Aeropuerto( IATA_destino, aeropuerto_destino, ciudad_destino, pais_destino);
        
        if(!buscar_aeropuerto(origen)){
            agrandar_aeropuertos(aeropuertos,cantidad_aeropuertos);
            aeropuertos[cantidad_aeropuertos] = origen;
            cantidad_aeropuertos++;
        }

        if(!buscar_aeropuerto(destino)){   
            agrandar_aeropuertos(aeropuertos, cantidad_aeropuertos);
            aeropuertos[cantidad_aeropuertos] = destino;
            cantidad_aeropuertos++;
        }
    
        agrandar_aeropuertos(aeropuertos_origen, cantidad_vuelos);
        aeropuertos_origen[cantidad_vuelos] = origen;

        agrandar_aeropuertos(aeropuertos_destino, cantidad_vuelos);
        aeropuertos_destino[cantidad_vuelos] = destino;

        agrandar_costos();
        costos[cantidad_vuelos] = costo;

        cantidad_vuelos++;  
    };

    for (int i = 0; i < cantidad_aeropuertos; i++){
        grafo.agregarVertice(aeropuertos[i]);
    }
    
    for (int i = 0; i < cantidad_vuelos; i++){
        grafo.agregarCamino(aeropuertos_origen[i], aeropuertos_destino[i], costos[i]);
    }

    cout << "Aeropuertos disponibles: " << endl;
    for (int i = 0; i < cantidad_aeropuertos; i++){
        cout << aeropuertos[i].obtenerNombre() << "   " << aeropuertos[i].obtenerAeropuerto() << endl;
    }

    archivo_vuelos.close();


}

// AUXILIARES

bool buscar_aeropuerto(Aeropuerto aeropuerto){

    for(int i = 0; i < cantidad_aeropuertos; i++){
        if(aeropuertos[i].obtenerNombre() == aeropuerto.obtenerNombre()){
            return true;
        }
    }
    return false;
}

void agrandar_aeropuertos(Aeropuerto* &array, int cantidad_aeropuertos){
    Aeropuerto * aux = new Aeropuerto[cantidad_aeropuertos + 1];
    for(int i = 0; i < cantidad_aeropuertos; i++){
        aux[i] = array[i];
    }
    delete[] array;
    array = aux;

}

void agrandar_costos(){
    int * aux = new int[cantidad_vuelos + 1];
    for(int i = 0; i < cantidad_vuelos; i++){
        aux[i] = costos[i];
    }
    delete[] costos;
    costos = aux;
}










