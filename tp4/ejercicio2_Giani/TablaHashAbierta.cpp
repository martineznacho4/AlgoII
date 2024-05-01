#include "TablaHashAbierta.h"
using namespace std;

//El direccionamiento cerrado lo implemento buscando la siguiente celda libre en la misma tabla cuando se da una colision
//en vez de buscar en otra estructura

TablaHashAbierta::TablaHashAbierta():cantidadAeropuertos(0){
    for (int i = 0; i < TAMANO_TABLA_HASH; i++){
        tabla[i].setOcupado(false);
    }
}

// calculo el valor de hash
// actualizo el valor  utilizando una combinación lineal.
int TablaHashAbierta::hash(const string& clave){
    int valorHash = 0;
    for (char c:clave){
        //Uso un numero primo para evitar colisiones
        valorHash =(valorHash*33+c) % TAMANO_TABLA_HASH;
    }
    return valorHash;
}


//calculo el indice hash de la ciudad y busco la proxima celda libre en la misma tabla
//usando el método linear probing
bool TablaHashAbierta::insertar(Aeropuerto& aeropuerto){
    //Verifico que no se sobrepase la cantidad deseada
    if (cantidadAeropuertos>=50){
        return false;
    }
    int indice =hash(aeropuerto.getCiudad());
    int i = 0;
    while ((tabla[indice].getOcupado()) && (i < TAMANO_TABLA_HASH)){
        //Busco la proxima celda libre en la tabla
        indice = (indice+1)%TAMANO_TABLA_HASH;
        i++;
    }
    if (!tabla[indice].getOcupado()){
        tabla[indice].setAeropuerto(aeropuerto);
        tabla[indice].setOcupado(true);
        cantidadAeropuertos++;
        return true;
    }
    return false;
}


//calculo el indice hash de la ciudad y busco la siguiente celda que tenga el aeropuerto de esa ciudad en la tabla
bool TablaHashAbierta::eliminar(string& nombreCiudad){
    int indice=hash(nombreCiudad);
    int i =0;
    while ((tabla[indice].getOcupado()) && (i<TAMANO_TABLA_HASH)){
        if (tabla[indice].getAeropuerto().getCiudad() ==nombreCiudad){
            tabla[indice].setOcupado(false);
            cantidadAeropuertos--;
            return true;
        }
        indice =(indice+1) % TAMANO_TABLA_HASH;
        i++;
    }
    return false;
}

// calculo el indice hash de la ciudad
// Busco la proxima celda que contiene el aeropuerto de esa ciudad en la misma tabla
Aeropuerto TablaHashAbierta::buscar(string& nombreCiudad){
    int indice = hash(nombreCiudad);
    int i = 0;
    while (tabla[indice].getOcupado() && i < TAMANO_TABLA_HASH){
        if (tabla[indice].getAeropuerto().getCiudad() ==nombreCiudad){
            return tabla[indice].getAeropuerto();
        }
        indice = (indice + 1) %TAMANO_TABLA_HASH;
        i++;
    }
    // devuelvo un aeropuerto vacío si no se encuentro el buscado
    return Aeropuerto("", "", "", "", 0, 0, 0, 0);
}
