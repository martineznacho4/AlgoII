#include "TablaHashCerrada.h"
using namespace std;

TablaHashCerrada::TablaHashCerrada() : cantidadAeropuertos(0){
    for (int i=0; i<TAMANO_TABLA_HASH; i++){
        tabla[i].setOcupado(false);
    }
}

// modifica valor hash con una cmombinacion lineal
// devuelve el valor hash calculado.
int TablaHashCerrada::hash(const string& clave){
    int valorHash = 0;
    for (char c : clave){
        //uso un primo
        valorHash = (valorHash*33+c) % TAMANO_TABLA_HASH;
    }
    return valorHash;
}

//calculo el indice hash de la ciudad y una celda libre en la tabla usando el metodo linear probing
// si encuentro una celda vacía la marco como ocupada y guardo el aeropuerto en esa posicion
bool TablaHashCerrada::insertar( Aeropuerto& aeropuerto){
    if (cantidadAeropuertos == TAMANO_TABLA_HASH){
        return false;
    }
    int indice =hash(aeropuerto.getCiudad());
    for (int i=0; i<TAMANO_TABLA_HASH; i++){
        int nuevoIndice = (indice+i) % TAMANO_TABLA_HASH;
        if (!tabla[nuevoIndice].getOcupado()){
            tabla[nuevoIndice].setAeropuerto(aeropuerto);
            tabla[nuevoIndice].setOcupado(true);
            cantidadAeropuertos++;
            return true;
        }
    }
    return false;
}


//Calculo el índice de la ciudad y busco la celda que tiene el aeropuerto de esa ciudad
// Si lo encuentro, marco la celda como libre y actualizo el contador de aeropuertos
bool TablaHashCerrada::eliminar( string& nombreCiudad){
    int indice = hash(nombreCiudad);
    for (int i = 0; i < TAMANO_TABLA_HASH; i++){
        int nuevoIndice = (indice + i) % TAMANO_TABLA_HASH;
        if (tabla[nuevoIndice].getOcupado() && tabla[nuevoIndice].getAeropuerto().getCiudad() == nombreCiudad){
            tabla[nuevoIndice].setOcupado(false);
            cantidadAeropuertos--;
            return true;
        }
    }
    return false;
}

// Calculo el indice hash para la ciudad y busco la celda con el aeropuerto de esa ciudad
Aeropuerto TablaHashCerrada::buscar( string& nombreCiudad){
    int indice = hash(nombreCiudad);
    for (int i=0; i<TAMANO_TABLA_HASH; ++i){
        int nuevoIndice = (indice+i) % TAMANO_TABLA_HASH;
        if (tabla[nuevoIndice].getOcupado() && tabla[nuevoIndice].getAeropuerto().getCiudad() == nombreCiudad){
            return tabla[nuevoIndice].getAeropuerto();
        }
    }
    //Devuelvo un aeropuerto vacio si no se encuentra
    return Aeropuerto("", "", "", "", 0, 0, 0, 0);
}
