#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include "nodo.h"
using namespace std;

template<typename Dato>
class Lista {
private:
    Nodo<Dato>* primero;
    Nodo<Dato>* cursor;
    int cantidad;

    Nodo<Dato>* obtener_nodo(int pos);

public:
    // Constructor
    Lista();
    
    // Destructor
    ~Lista();
    
    // Pos: Agrega un elemento "d" en la posicion "pos" a la Lista
    void alta(Dato d, int pos);

    // Pre: 0 < pos <= this.obtener_cantidad()
    // Pos: Elimina el elemento en la posicion indicada
    void baja(int pos);

    // Pre: 0 < pos <= this.obtener_cantidad()
    // Pos: Devuelve el Dato en la posicion pos
    Dato consulta(int pos);

    // Pos: Devuelve la cantidad de elementos en la lista
    int obtener_cantidad();


};

// Constructor
template<typename Dato>
Lista<Dato>::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}

template<typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

template<typename Dato>
void Lista<Dato>::alta(Dato d, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (cantidad == 0)
        cursor = nuevo;
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<Dato>* anterior = obtener_nodo(pos-1);
        Nodo<Dato>* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

template<typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato>* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
        cursor = primero;
    } else {
        Nodo<Dato>* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo<Dato>* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }

    delete borrar;
    cantidad--;
}

template<typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

template<typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}

template<typename Dato>
Lista<Dato>::~Lista() {
    while (cantidad > 0)
        baja(1);
}


#endif
