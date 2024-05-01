#include "nodo.h"

Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = nullptr;
}

Nodo::Nodo(Dato d, Nodo* pn) {
    dato = d;
    siguiente = pn;
}

Dato Nodo::obtener_dato() {
    return dato;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

void Nodo::cambiar_dato(Dato d) {
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}
