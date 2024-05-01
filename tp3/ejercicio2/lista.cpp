#include <iostream>
#include "lista.h"

const int MAXIMO = 5;

using namespace std;
ListaCircular::ListaCircular() {
    primero = nullptr;
    cantidad = 0;
}

Nodo* ListaCircular::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void ListaCircular::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void ListaCircular::alta(Dato d){

    Nodo* nuevo = new Nodo(d);

    if (cantidad == 0){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        cantidad++;
    }else if(cantidad == MAXIMO ){
        Nodo* anterior = obtener_nodo(MAXIMO); 
        nuevo->cambiar_siguiente(primero->obtener_siguiente());
        primero = nuevo->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
        
    }else{
        Nodo* anterior = obtener_nodo(cantidad);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
        cantidad++;
    }
};



void ListaCircular::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    cantidad--;
}

Dato ListaCircular::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool ListaCircular::esta_vacia() {
return (cantidad == 0);
}

int ListaCircular::obtener_cantidad() {
return cantidad;
}

void ListaCircular::mostrar(){
    
    for (int i = 1; i <= this->cantidad; i++){
        std::cout << this->consulta(i) << std::endl;
    }

};

Dato ListaCircular::mas_antiguo(){
    return this->primero->obtener_dato();
};

double ListaCircular::promedio(){
    double resultado;
    
    for (int i = 1; i <= cantidad; i++){
        resultado += this->consulta(i);
    }
    
    return (resultado / this->cantidad);

};

ListaCircular::~ListaCircular() {
    while (!esta_vacia())
        baja(1);
}