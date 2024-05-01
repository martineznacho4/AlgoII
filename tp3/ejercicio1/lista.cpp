#include <iostream>
#include "lista.h"

using namespace std;

Lista::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (esta_vacia())
        cursor = nuevo;
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

void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
        reiniciar_cursor();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }

    if (cursor == borrar)
        siguiente();
    delete borrar;
    cantidad--;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
return (cantidad == 0);
}

int Lista::obtener_cantidad() {
return cantidad;
}

bool Lista::hay_siguiente() {
    return (cursor != nullptr);
}

Dato Lista::siguiente() {
    Dato dato = cursor->obtener_dato();
    cursor = cursor->obtener_siguiente();
    return dato;
}

void Lista::reiniciar_cursor() {
    cursor = primero;
}

Lista::~Lista() {
    while (!esta_vacia())
        baja(1);
}

// Listas no ordenadas -> comparo elemento a elemento

Lista* Lista::interseccion_A(Lista &otra){

    Lista *aux = new Lista();

    for (int i = 1; i <= this->cantidad; i++){
        for (int j = 1; j <= otra.obtener_cantidad(); j++){
            if(this->consulta(i) == otra.consulta(j) ){
                aux->alta(this->consulta(i), aux->obtener_cantidad() + 1);
            };
        };
    };
    return aux;
}


// Listas ordenadas

Lista* Lista::interseccion_B(Lista &otra){

    Lista *aux = new Lista();

    int i = 1;
    int j = 1;

    while(this->hay_siguiente() && otra.hay_siguiente()){
        int datoA = this->consulta(i);
        int datoB = otra.consulta(j);

        if(datoA == datoB){
            aux->alta(datoA, aux->obtener_cantidad() + 1);
            i++;j++;
            this->siguiente();
            otra.siguiente();
        }else if(datoA < datoB){
            i++;
            this->siguiente();
        } else if(datoA > datoB){
            j++;
            otra.siguiente();
        }
    }
    return aux;
}

void Lista::mostrar(){
    for (int i = 1; i <= this->cantidad; i++)
    {
        cout << this->consulta(i) << endl;
    }
    
}

